//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL n,m;
LL aktualny_punkt = 1;

vector<LL> rodzice;
vector<LL> preorder;
vector<LL> poddrzewa;
vector<LL> glebokosc;

vector<vector<LL>> graf;
vector<LL> rodzice_krawedzi_hld;

//DFS obliczajacy dla kazdego punktu rozmiar poddrzewa, przodka i glebokosc w drzewie
void oblicz_poddrzewa(LL s,LL p){
    poddrzewa[s]++;
    rodzice[s] = p;
    glebokosc[s] = glebokosc[p] + 1;

    for(const LL &v : graf[s]){
        if(v == p)continue;
        oblicz_poddrzewa(v,s);
        poddrzewa[s] = poddrzewa[s] + poddrzewa[v];
    } 
    return;
}

//Statyczne drzewo przedzialowe (przedzial-punkt)
const LL M = 1 << 20;
vector<LL> tree(2 * M);

void update(LL a, LL b, LL c){
    a=a+M;
    b=b+M;

    tree[a] = max(tree[a], c);
    tree[b] = max(tree[b], c);

    while(a / 2 != b / 2){
        if(a % 2 == 0){
            tree[a + 1] = max(tree[a + 1],c);
        }
        if(b % 2 == 1){
            tree[b - 1] = max(tree[b - 1],c);
        }
        a = a / 2;
        b = b / 2;
    }
    return;
}
LL query(LL a){
    a = a + M;
    LL wynik = tree [a];

    while(a != 1){
        a = a / 2;
        wynik=max(wynik, tree[a]);
    }

    return wynik;
}
void update_hld(LL lewo, LL prawo, LL wartosc){
    LL a, b;
    while(rodzice_krawedzi_hld[lewo] != rodzice_krawedzi_hld[prawo]){
        if(glebokosc[rodzice_krawedzi_hld[lewo]] > glebokosc[rodzice_krawedzi_hld[prawo]]){
            a = preorder[lewo];
            b = preorder[rodzice_krawedzi_hld[lewo]];

            if(a > b)swap(a,b);
            update(a, b, wartosc);
            lewo = rodzice[rodzice_krawedzi_hld[lewo]];

        }else{
            a = preorder[prawo];
            b = preorder[rodzice_krawedzi_hld[prawo]];

            if(a > b)swap(a, b);
            update(a, b, wartosc);
            prawo = rodzice[rodzice_krawedzi_hld[prawo]];

        }
    }

    a = preorder[lewo];
    b = preorder[prawo];

    if(a > b)swap(a,b);

    update(a,b,wartosc);
    
    return;
}

//HLD
void hld(LL s){
    preorder[s] = aktualny_punkt;
    aktualny_punkt++;

    if(rodzice_krawedzi_hld[s] == 0){
        rodzice_krawedzi_hld[s] = s;
    }

    LL dziecko = 0,maks = 0;
    for(int i = 0; i < graf[s].size(); i++){
        if(poddrzewa[graf[s][i]] > maks && graf[s][i] != rodzice[s]){
            maks = poddrzewa[graf[s][i]];
            dziecko = graf[s][i];
        }
    }

    if(dziecko != 0){
        rodzice_krawedzi_hld[dziecko] = rodzice_krawedzi_hld[s];
        hld(dziecko);
    }

    for(int i = 0;i < graf[s].size(); i++){
        if(graf[s][i] == rodzice[s] || graf[s][i] == dziecko)continue;
        hld(graf[s][i]);
    }

    return;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    LL a,b,c;
    cin >> n >> m;

    graf.resize(n + 1);
    rodzice.resize(n + 1,0);
    preorder.resize(n + 1,0);
    glebokosc.resize(n + 1,0);
    poddrzewa.resize(n + 1,0);
    rodzice_krawedzi_hld.resize(n + 1,0);

    for(int i = 1; i < n; i++){
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    oblicz_poddrzewa(1, 0);
    hld(1);

    for(int i = 1; i <= m; i++){
        char operacja;
        cin >> operacja;
        if(operacja == 'm'){
            cin >> a >> b >> c;
            update_hld(a,b,c);
        }else{
            cin >> a;
            cout << query(preorder[a]) << endl;
        }
    }

    for(LL i = 1;i <= n; i++){
        cout << query(preorder[i])<<" ";
    }
    return 0;
}
 