//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int dp[2][10009];

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    long long int n,m;
    cin>>n>>m;

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=-1e18-9;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            long long int a,maks;
            if(i%2==0)
            {
                cin>>a;
                dp[0][j]=a;
                maks=max(dp[1][j],dp[0][j-1]);
                dp[0][j]=dp[0][j]+maks;
                dp[0][0]=-1e18-9;
            }
            else
            {
                cin>>a;
                dp[1][j]=a;
                maks=max(dp[0][j],dp[1][j-1]);
                dp[1][j]=dp[1][j]+maks;
            }
            
        }
    

    }
    cout<<dp[(n+1)%2][m];
    return 0;
}