//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,wynik=0;
    cin>>n;

    dp.resize(n+9,vector<int> (4));
    dp[0]={1,1,0,0};

    for(int i=1;i<=n;i++)
    {
        int bomby;
        cin>>bomby;

        if(bomby==0)
        {
            dp[i][0]=dp[i-1][0]; dp[i][1]=0; dp[i][2]=0; dp[i][3]=0;
        }
        if(bomby==1)
        {
            dp[i][0]=dp[i-1][2]; dp[i][1]=dp[i-1][0]; dp[i][2]=dp[i-1][1]; dp[i][3]=0;
        }
        if(bomby==2)
        {
            dp[i][2]=0; dp[i][1]=dp[i-1][2]; dp[i][2]=dp[i-1][3]; dp[i][3]=dp[i-1][1];
        }
        if(bomby==3)
        {
            dp[i][0]=0; dp[i][1]=0; dp[i][2]=0; dp[i][3]=dp[i-1][3];
        }
    }

    cout<<dp[n][0]+dp[n][2];
    return 0;
}
 