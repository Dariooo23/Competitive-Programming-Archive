//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;



int n, m;
int aktualny_punkt = 1;
//Tablice do HLD i Segment Tree
vector<vector<int>> graf;

vector<int> rodzice;
vector<int> numeracja;
vector<int> poddrzewa;
vector<int> glebokosc;

vector<int> rodzice_krawedzi_hld;

int M = 1;
vector<int> drzewo;



//DFS Obliczajacy podstawowe informacje o drzewie
void oblicz_poddrzewa(int s, int p){
    poddrzewa[s]++;
    rodzice[s] = p;
    glebokosc[s] = glebokosc[p] + 1;

    for(const int &v : graf[s]){
        if(v == p)continue;
        oblicz_poddrzewa(v,s);
        poddrzewa[s] = poddrzewa[s] + poddrzewa[v];
    } 
}



//Implementacja Segment Tree (Przedzial - Punkt)
void update(int x, int y, int wartosc, int gdzie = 1, int pocz = 1, int kon = M){
    if(x <= pocz && y >= kon){
        drzewo[gdzie] = max(drzewo[gdzie], wartosc);
        return;
    }

    int mid = (pocz + kon) / 2;
    if(x <= mid) update(x, y, wartosc, 2 * gdzie, pocz, mid);
    if(y > mid)  update(x, y, wartosc, 2 * gdzie + 1, mid + 1, kon);
}

int query(int x, int gdzie = 1, int pocz = 1, int kon = M){
    if(x == pocz && kon == x)return drzewo[gdzie];
    
    int mid = (pocz + kon) / 2;

    if(x <= mid){
        return max(drzewo[gdzie],query(x, 2 * gdzie, pocz, mid));
    }else{
        return max(drzewo[gdzie],query(x, 2 * gdzie + 1, mid + 1, kon));
    }
}

void update_hld(int lewo, int prawo, int wartosc){
    int a, b;

    while(rodzice_krawedzi_hld[lewo] != rodzice_krawedzi_hld[prawo]){
        if(glebokosc[rodzice_krawedzi_hld[lewo]] > glebokosc[rodzice_krawedzi_hld[prawo]]){
            a = numeracja[lewo];
            b = numeracja[rodzice_krawedzi_hld[lewo]];

            if(a > b)swap(a, b);
            update(a, b, wartosc);
            lewo = rodzice[rodzice_krawedzi_hld[lewo]];

        }else{
            a = numeracja[prawo];
            b = numeracja[rodzice_krawedzi_hld[prawo]];

            if(a > b)swap(a, b);
            update(a, b, wartosc);
            prawo = rodzice[rodzice_krawedzi_hld[prawo]];

        }
    }

    a = numeracja[lewo];
    b = numeracja[prawo];

    if(a > b)swap(a, b);
    update(a, b, wartosc);
}



//Heavy-Light Decomposition (HLD)
void hld(int s){
    numeracja[s] = aktualny_punkt;
    aktualny_punkt++;

    if(rodzice_krawedzi_hld[s] == 0) rodzice_krawedzi_hld[s] = s;
    
    int dziecko = 0, maks = 0;
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
        if(graf[s][i] == rodzice[s] || graf[s][i] == dziecko) continue;
        hld(graf[s][i]);
    }
}



int main(){
    cin >> n >> m;

    graf.resize(n + 1);
    rodzice.resize(n + 1, 0);
    numeracja.resize(n + 1, 0);
    glebokosc.resize(n + 1, 0);
    poddrzewa.resize(n + 1, 0);
    rodzice_krawedzi_hld.resize(n + 1, 0);

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;

        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    oblicz_poddrzewa(1, 0);
    hld(1);
    
    while (M < n) M = M * 2;
    M = M * 2;
    drzewo.resize(M * 2, 0);

    for (int i = 1; i <= m; i++){
        char operacja;
        int a, b, c;
        cin >> operacja;

        if (operacja == 'A'){
            cin >> a >> b >> c;
            update_hld(a, b, c);
        }
        if (operacja == 'Q'){
            cin >> a;
            cout << query(numeracja[a]) << endl;
        }
    }

    for(int i = 1; i <= n; i++) cout << query(numeracja[i])<<" ";

    return 0;
}
 