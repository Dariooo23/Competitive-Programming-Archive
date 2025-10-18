#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
int tab[1009][1009];
int main()
{
    std::ios_base::sync_with_stdio(0);

    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<":";
        int j=0;
        while(j<g[i].size())
        {
            cout<<" "<<g[i][j];
            j++;
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int k=0;k<g[i].size();k++)
        {
          tab[i][g[i][k]]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
          cout<<tab[i][k]<<" ";
        }
        cout<<endl;
    }

    return 0;
}