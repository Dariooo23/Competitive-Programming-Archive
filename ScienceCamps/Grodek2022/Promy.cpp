//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const long long int M=1<<20;
long long int modulo=1e9+7;
long long int tree[M*2];
vector<vector<long long int>> g;

//ZAPYTANIE O SUME NA PRZEDZIALE
long long int query(int pocz,int kon)
{
    pocz=pocz+M;
    kon=kon+M;    
    long long int wynik=tree[pocz];
    if(pocz!=kon)
    {
        wynik=(wynik+tree[kon])%modulo;
    }

    while(pocz/2!=kon/2)
    {
        if(pocz%2==0)
        {
            wynik=(wynik+tree[pocz+1])%modulo;
        }
        if(kon%2==1)
        {
            wynik=(wynik+tree[kon-1])%modulo;
        }
        pocz=pocz/2;
        kon=kon/2;
    }
    return wynik;
}
void update(int x,long long int y)
{
    x=x+M;
    tree[x]=(tree[x]+y)%modulo;
    while(x!=1)
    {
        x=x/2;
        tree[x]=(tree[2*x]+tree[2*x+1])%modulo;
    }

}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,m,t;
    cin>>n>>m>>t;

    g.resize(n+1);
    for(int i=1;i<=t;i++){
        long long int a,b;cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end());
    }

    update(0,1);
    for(int i=1;i<=n;i++)
    {
        for(int j=g[i].size()-1;j>=0;j--)
        {
            update(g[i][j],query(0,g[i][j]-1));
        }
    }
    cout<<query(0,m);

    
    
    return 0;
}
 