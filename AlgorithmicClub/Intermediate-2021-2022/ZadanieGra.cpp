
//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> dp;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    dp.resize(n+1);

    for(int i=1;i<=n;i++)
    {
        int pole;
        cin>>pole;
        
        dp[i]=dp[i-1];
        for(int j=i-1;j>=max(i-6,1);j--)
        {
            dp[i]=max(dp[i],dp[j]);
        }
        dp[i]=dp[i]+pole;
    }

    cout<<dp[n];


    return 0;
}
 