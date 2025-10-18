#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g(500009);
vector<vector<int>> przodkowie(500009,vector<int>(20));
vector<int> wysokosc(500009);
vector<long long int> koszty(500009);

void dfs(int s, int parent)
{
    przodkowie[s][0]=parent;
    wysokosc[s]=wysokosc[parent]+1;
    for(int v : g[s])
    {
        if(v!=parent)
        {
            dfs(v,s);
        }
    }
}

void przo()
{
    for(int k=1;k<20;k++)
    {
        for(int i=1;i<500009;i++)
        {
            przodkowie[i][k]=przodkowie[przodkowie[i][k-1]][k-1];
        }
    }
}

int LCA(int a,int b)
{
    if(wysokosc[a]<wysokosc[b])
    {
        swap(a,b);
    }

    for(int k=20;k>=0;k--)
    {
        if(wysokosc[przodkowie[a][k]]>=wysokosc[b])
        {
            a=przodkowie[a][k];
        }
    }

    if(a==b)
    {
        return a;
    }

    for(int k=20;k>=0;k--)
    {
        if(przodkowie[a][k]!=przodkowie[b][k])
        {
            a=przodkowie[a][k];
            b=przodkowie[b][k];
        }
    }
    return przodkowie[a][0];
}

long long int zliczanie(int s,int p)
{
    long long int wynik1=0;
    for(int v : g[s])
    {
        if(v!=p)
        {
            wynik1=max(wynik1,zliczanie(v,s));
            koszty[s]=koszty[s]+koszty[v];
        }
    }
    return max(wynik1,koszty[s]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n-1;i++)
    {
        long long int a,b;
        cin>>a>>b;
        a++;
        b++;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    wysokosc[0]=-1;
    dfs(1,0);
    przo();

    while(m>=1)
    {
        long long int c,d,e;
        cin>>c>>d>>e;
        c++;
        d++;
        koszty[c]=koszty[c]+e;
        koszty[d]=koszty[d]+e;
        koszty[LCA(c,d)]=koszty[LCA(c,d)]-2*e;
        m--;
    }
    cout<<zliczanie(1,0);

    return 0;
}