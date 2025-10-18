//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<long long int> dp;
const int mod=1e9+7;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    dp.resize(n+1);

    dp[0]=0;
    dp[1]=6;
    dp[2]=36;
    for(int i=3;i<=n;i++)
    {
        dp[i]=(dp[i-1]*5)%mod+(dp[i-2]*5)%mod;
    }

    cout<<dp[n]%mod;
    return 0;
}
 