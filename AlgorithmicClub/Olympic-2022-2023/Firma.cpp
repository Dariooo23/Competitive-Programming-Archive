//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const long long int M=1<<20;
vector<long long int> tree(M*2,0);

long long int query(int pocz,int kon){
    pocz=pocz+M;
    kon=kon+M;

    long long int wynik=tree[pocz];
    if(pocz!=kon){
        wynik=wynik+tree[kon];
    }

    while(pocz/2!=kon/2){
        if(pocz%2==0){
            wynik=wynik+tree[pocz+1];
        }
        if(kon%2==1){
            wynik=wynik+tree[kon-1];
        }
        pocz=pocz/2;
        kon=kon/2;
    }
    return wynik;
}
void update(int x,long long int y){
    x=x+M;
    tree[x]=tree[x]+y;

    while(x!=1){
        x=x/2;
        tree[x]=tree[2*x]+tree[2*x+1];
    }

    return;
}

struct polecenie{
    int pracownik,glebokosc,czas;
    bool rodzaj;
};

vector<int> usun;
vector<int> glebokosci;
vector<vector<int>> graf;
vector<polecenie> polecenia;
vector<pair<int,int>> preorder;
vector<pair<int,long long int>> wyniki;

int punkt=0;

void dfs(int s,int p){
    punkt++;
    preorder[s].first=punkt;
    glebokosci[s]=glebokosci[p]+1;

    for(int &v:graf[s]){
        if(v==p)continue;
        dfs(v,s);
    }

    preorder[s].second=punkt;
    return;
}
void ustaw_glebokosci(int n){
    for(int i=0;i<n;i++){
        if(polecenia[i].rodzaj==0){
            polecenia[i].glebokosc=glebokosci[polecenia[i].pracownik];
        }else{
            polecenia[i].glebokosc=glebokosci[polecenia[i].pracownik]+polecenia[i].glebokosc+1;
        }
    }

    return;
}

bool comp(const polecenie &a,const polecenie &b){
    if(a.glebokosc==b.glebokosc){
        return a.czas<b.czas;
    }else{
        return a.glebokosc<b.glebokosc;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    graf.resize(n+100000);
    glebokosci.resize(n+100000,0);
    preorder.resize(n+100000,{0,0});

    for(int i=1;i<=n;i++){
        char rodzaj;
        int a,b;

        cin>>rodzaj;
        cin>>a>>b;

        if(rodzaj=='Z'){
            graf[b].push_back(a);
            graf[a].push_back(b);
            polecenia.push_back({a,b,i,0});
        }else{
            polecenia.push_back({a,b,i,1});
        }
    }

    dfs(1,0);
    ustaw_glebokosci(polecenia.size());
    sort(polecenia.begin(),polecenia.end(),comp);

    for(int i=0;i<n;i++){
        if(polecenia[i].rodzaj==0){
            update(preorder[polecenia[i].pracownik].first,1);
            usun.push_back(preorder[polecenia[i].pracownik].first);
        }
        if(polecenia[i].rodzaj==1){
            wyniki.push_back({polecenia[i].czas,query(preorder[polecenia[i].pracownik].first,
                                                      preorder[polecenia[i].pracownik].second)});
        }
        if(i+1>=polecenia.size())continue;
        if(polecenia[i].glebokosc!=polecenia[i+1].glebokosc){
            for(int j=0;j<usun.size();j++){
                update(usun[j],-1);
            }
            usun.clear();
        }
    }

    sort(wyniki.begin(),wyniki.end());
    for(int i=0;i<wyniki.size();i++){
        cout<<wyniki[i].second<<endl;
    }


 
    
    return 0;
}
 