//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> graf;
vector<bool> visited;
vector<int> xory;

void dfs(int s,int p)
{
    for(pair<int,int> &v : graf[s])
    {
        if(visited[v.first]==0)
        {
            visited[v.first]=1;
            xory[v.first]=xory[s]^v.second;
            dfs(v.first,s);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,m;
    cin>>n>>m;

    graf.resize(n+1);
    xory.resize(n+1,-1);
    visited.resize(n+1,0);
    xory[0]=0;

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graf[a-1].push_back({b,c});
        graf[b].push_back({a-1,c});
    }

    visited[0]=1;
    dfs(0,0);

    for(int i=0;i<=n;i++)
    {
        if(!visited[i])
        {
            cout<<"NIE";
            return 0;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<(xory[i]^xory[i+1])<<" ";
    }


    return 0;
}
 