#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g(30009);
vector<vector<int>> przodkowie(30009,vector<int>(16));
vector<int> wysokosc(30009);

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
    for(int k=1;k<16;k++)
    {
        for(int i=1;i<30009;i++)
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

    for(int k=15;k>=0;k--)
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

    for(int k=15;k>=0;k--)
    {
        if(przodkowie[a][k]!=przodkowie[b][k])
        {
            a=przodkowie[a][k];
            b=przodkowie[b][k];
        }
    }
    return przodkowie[a][0];
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n,wynik=0;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    wysokosc[0]=-1;
    dfs(1,0);
    przo();

    int testy,c;
    cin>>testy>>c;
    while(testy>1)
    {
        int d;
        cin>>d;
        wynik=wynik+wysokosc[d]+wysokosc[c]-2*wysokosc[LCA(d,c)];
        c=d;
        testy--;
    }
    cout<<wynik;

    return 0;
}
