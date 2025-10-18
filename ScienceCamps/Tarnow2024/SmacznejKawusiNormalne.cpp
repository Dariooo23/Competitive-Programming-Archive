//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

//LCA
vector<int> glebokosci;
vector<vector<int>> lca;
vector<vector<int>> graf;
vector<long long int> ile_razy_lca;

//ODPOWIEDZI
vector<pair<int,int>> krawedzie;
map<pair<int,int>,long long int> ilosc_odwiedzin;
map<pair<int,int>,pair<long long int,long long int>> koszty;

void dfs(int s,int p){
    lca[s][0]=p;
    glebokosci[s]=glebokosci[p]+1;

    for(const int &v:graf[s]){
        if(v==p)continue;
        dfs(v,s);
    }
}

void policz_lca(int n){
    for(int k=1;k<=20;k++){
        for(int i=1;i<=n;i++){
            lca[i][k]=lca[lca[i][k-1]][k-1];
        }
    }

    return;
}


int znajdz_lca(int a,int b){
    if(glebokosci[a]>glebokosci[b]){
        swap(a,b);
    }


    for(int k=20;k>=0;k--){
        if(glebokosci[lca[b][k]]>=glebokosci[a]){
            b=lca[b][k];
        }
    }

    if(a==b){
        return a;
    }

    for(int k=20;k>=0;k--){
        if(lca[a][k]!=lca[b][k]){
            a=lca[a][k];
            b=lca[b][k];
        }
    }

    return lca[a][0];
}

int dfs_wynikowy(int s,int p,int n){
    long long int suma=0;
    if(s!=n){
        suma=2;
    }
    if(s==n){
        suma=1;
    }

    for(const int &v:graf[s]){
        if(v==p)continue;
        suma+=dfs_wynikowy(v,s,n);
    }

    int liczba1=s,liczba2=p;
    if(liczba1>liczba2)swap(liczba1,liczba2);

    ilosc_odwiedzin[{liczba1,liczba2}]=suma-ile_razy_lca[s]*2;
    return ilosc_odwiedzin[{liczba1,liczba2}];
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    graf.resize(n+1);
    glebokosci.resize(n+1);
    ile_razy_lca.resize(n+1,0);
    lca.resize(n+1,vector<int> (21));

    for(int i=1;i<n;i++){
        long long int a,b,c,d;
        cin>>a>>b>>c>>d;
        graf[a].push_back(b);
        graf[b].push_back(a);

        if(a>b)swap(a,b);
        koszty[{a,b}]={c,d};
        krawedzie.push_back({a,b});
    }

    glebokosci[0]=0;
    dfs(1,0);
    policz_lca(n);

    
    for(int i=1;i<n;i++){
        long long int liczba_lca=znajdz_lca(i,i+1);
        ile_razy_lca[liczba_lca]++;
    }

    dfs_wynikowy(1,0,n);

    long long int wynikg=0;
    for(int i=0;i<n-1;i++){
        int liczba1=krawedzie[i].first,liczba2=krawedzie[i].second;

        long long int wynikp=min(koszty[krawedzie[i]].first*ilosc_odwiedzin[krawedzie[i]],
                                koszty[krawedzie[i]].second);
        wynikg+=wynikp;                        
    }

    cout<<wynikg;
    return 0;
}