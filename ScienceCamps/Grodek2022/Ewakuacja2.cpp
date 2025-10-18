//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

//Brut
vector<vector<int>> graf;
vector<bool> visited;
vector<int> dist;

void dfs_brut(int s,int odl)
{
        dist[s]=odl;
        for(const int &v:graf[s])
        {
            if(visited[v]==0)
            {
                visited[v]=1;
                dfs_brut(v,odl+1);
            }
        }
}

void brut(int n)
{
    graf.resize(n+1);

    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;

        graf[x].push_back(y);
        graf[y].push_back(x);
    }

    for(int i=1;i<=n;i++)
    {
        visited.resize(n+1,0);
        dist.resize(n+1,0);
        visited[i]=1;
        dist[i]=1;
        
        dfs_brut(i,1);

        int maks=0;
        for(int j=1;j<=n;j++)
        {
            maks=max(maks,dist[j]);
        }

        cout<<maks<<" ";

        visited.clear();
        dist.clear();
    }
}

//Niebrut
vector<pair<int,int>> dp;

pair<int,int> dfs_niebrut(int s,int p)
{
    if(graf[s].size()==1)
    {
        dp[s]={1,0};
        return dp[s];
    }

    int maks1=0,maks2=0,liczba=0;
    for(const int &v:graf[s])
    {
        if(v!=p)
        {
            liczba=dfs_niebrut(v,s).first;
            if(liczba+1>maks1)
            {
                maks2=maks1;
                maks1=liczba+1;
            }
            else
            {
                if(liczba+1>maks2)
                {
                    maks2=liczba+1;
                }
            }
        }
    }

    dp[s]={maks1,maks2};
    return dp[s];
}

void dfs2_niebrut(int s,int p)
{
    for(const int &v:graf[s])
    {
        if(v!=p)
        {
            if(dp[s].first==dp[v].first+1)
            {
                if(dp[s].second+1>dp[v].first)
                {
                    dp[v].second=dp[v].first;
                    dp[v].first=dp[s].second+1;
                }
                else
                {
                    if(dp[s].second+1>dp[v].second)
                    {
                        dp[v].second=dp[s].second+1;
                    }
                }
            }
            else
            {
                if(dp[s].first+1>dp[v].first)
                {
                    dp[v].second=dp[v].first;
                    dp[v].first=dp[s].first+1;
                }
                else
                {
                    if(dp[s].first+1>dp[v].second)
                    {
                        dp[v].second=dp[s].first+1;
                    }
                }
            }
            dfs2_niebrut(v,s);
        }
    }
}

void niebrut(int n)
{
    dp.resize(n+1,{0,0});
    graf.resize(n+1);

    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;

        graf[x].push_back(y);
        graf[y].push_back(x);
    }

    int start;
    for(int i=1;i<=n;i++)
    {
        if(graf[i].size()!=1)
        {
            start=i;
            break;
        }
    }

    dfs_niebrut(start,0);
    dfs2_niebrut(start,0);

    for(int i=1;i<=n;i++)
    {
        cout<<dp[i].first<<" ";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    if(n<=2000)
    {
        brut(n);
    }
    else
    {
        niebrut(n);
    }
    return 0;
}
 