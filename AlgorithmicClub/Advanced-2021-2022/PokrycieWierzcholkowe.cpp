#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
vector<long long int> cost;
vector<vector<long long int>> dp;
string res;


void dfs(int s,int p)
{
    for(int v:g[s])
    {
        if(v!=p)
        {
            dfs(v,s);
            dp[s][0]=dp[s][0]+dp[v][1];
            dp[s][1]=dp[s][1]+min(dp[v][0],dp[v][1]);
        }
    }
    dp[s][1]=dp[s][1]+cost[s];
}

void poddfs(int s,int p,int typ=2)
{
   if(typ==2 && min(dp[s][0],dp[s][1])==dp[s][1])
   {
       typ=1;
   }
       if(typ==1)
       {
           res[s-1]='1';
       }
       for(int v:g[s])
       {
           if(v!=p)
           {
               if(typ==1)
               {
                   poddfs(v,s,2);
               }
               if(typ==2)
               {
                   poddfs(v,s,1);
               }
           }
       }

}


int main()
{
    std::ios_base::sync_with_stdio(0);
    int n,a,b;
    cin>>n;
    cost.resize(n+1);
    g.resize(n+1);
    dp.resize(n+1,vector<long long int> (2));
    res.resize(n,'0');
    for(int i=1;i<=n;i++)
    {
       cin>>cost[i];
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    poddfs(1,0);
    cout<<min(dp[1][0],dp[1][1])<<endl;
    cout<<res;
    return 0;
}