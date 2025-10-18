//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

vector<int> rodzic;
vector<int> numery;
vector<int> glebokosc;
vector<vector<int>> graf;
vector<pair<int,int>> przedzialy;

int akt_punkt=1;
void dfs(int s,int p){
    rodzic[s]=p;
    glebokosc[s]=glebokosc[p]+1;
    przedzialy[s].first=akt_punkt;
    numery[s]=akt_punkt;
    akt_punkt++;
    for(const int &v:graf[s]){
        if(v==p)continue;
        dfs(v,s);
    }
    przedzialy[s].second=akt_punkt-1;
    return;
}

int M=(1<<20);
vector<int> tree(2*M);

void update(int a,int b,int wartosc){
    a+=M;
    b+=M;

    tree[a]+=wartosc;
    if(b!=a)tree[b]+=wartosc;

    while(a/2!=b/2){
        if(a%2==0){
            tree[a+1]+=wartosc;
        }
        if(b%2==1){
            tree[b-1]+=wartosc;
        }
        a/=2;
        b/=2;
    }

    return;
}
int query(int a){
    a+=M;
    int wynik=tree[a];
    while(a!=1){
        a/=2;
        wynik+=tree[a];
    }

    return wynik;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n;
    cin>>n;

    graf.resize(n+1);
    rodzic.resize(n+1);
    numery.resize(n+1);
    glebokosc.resize(n+1);
    przedzialy.resize(n+1);

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    glebokosc[0]=-1;
    dfs(1,0);

    int q;
    cin>>q;
    while(q){
        char typ;
        int a,b;
        cin>>typ;
        if(typ=='A'){
            cin>>a>>b;
            if(rodzic[a]!=b)swap(a,b);
            update(przedzialy[a].first,przedzialy[a].second,1);
        }else{
            cin>>a;
            cout<<glebokosc[a]-query(numery[a])<<endl;
            q--;
        }
    }
    return 0;
}