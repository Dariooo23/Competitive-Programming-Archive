//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graf;
vector<int> wielkosc;

void dfs(int v, int parent)
{
    wielkosc[v]=1;
    for(int u : graf[v])
    {
        if(u!=parent)
        {
            dfs(u,v);
            wielkosc[v]=wielkosc[u]+wielkosc[v];
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    graf.resize(n+1);
    wielkosc.resize(n+1);
    graf[1].push_back(1);

    for(int i=2;i<=n;i++)
    {
        int a;
        cin>>a;
        graf[i].push_back(a);
        graf[a].push_back(i);
    }

    dfs(1,1);
    for(int i=1;i<=n;i++)
    {
        cout<<wielkosc[i]-1<<" ";
    }
    
    return 0;
}