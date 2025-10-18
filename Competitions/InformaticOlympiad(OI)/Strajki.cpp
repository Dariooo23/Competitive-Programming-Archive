//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

vector<pair<long long int,long long int>> przedzialy;
vector<vector<long long int>> graf;
vector<long long int> numeracja;
vector<long long int> parent;

long long int akt_punkt=2;
void dfs(long long int s,long long int p){
    parent[s]=p;
    przedzialy[s].first=akt_punkt;
    for(const int &v:graf[s]){
        if(v==p)continue;
        numeracja[v]=akt_punkt;
        akt_punkt++;
    }

    if(graf[s].size()==1 && s!=1){
        przedzialy[s]={-1,-1};
    }else{
        przedzialy[s].second=akt_punkt-1;
    }

    for(const int &v:graf[s]){
        if(v==p)continue;
        dfs(v,s);
    }

    return;
}

long long int M=(1<<20);
vector<long long int> tree(2*M);
void update(long long int a,long long int b,long long int wartosc){
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

long long int query(long long int a){
    a+=M;
    long long int wynik=tree[a];
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

    int n;
    cin>>n;

    graf.resize(n+1);
    parent.resize(n+1);
    numeracja.resize(n+1);
    przedzialy.resize(n+1);

    for(int i=1;i<n;i++){
        long long int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    numeracja[1]=1;
    dfs(1,0);

    long long int q;
    cin>>q;
    long long int wynik=1;
    while(q--){
        long long int a;
        cin>>a;
        if(a>0){
            wynik=wynik+graf[a].size()-query(numeracja[a])-1;
            update(numeracja[parent[a]],numeracja[parent[a]],1);
            if(przedzialy[a].first!=-1)update(przedzialy[a].first,przedzialy[a].second,1);
        }else{
            a*=-1;
            wynik=wynik-graf[a].size()+query(numeracja[a])+1;
            update(numeracja[parent[a]],numeracja[parent[a]],-1);
            if(przedzialy[a].first!=-1)update(przedzialy[a].first,przedzialy[a].second,-1);
        }

        cout<<wynik<<endl;
    }
    return 0;
}