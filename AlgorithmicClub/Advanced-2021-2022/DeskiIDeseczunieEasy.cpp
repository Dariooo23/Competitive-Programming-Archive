//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,m;
    long long int modulo=1e9+7;

    cin>>n>>m;

    vector<long long int> dp;
    dp.resize(1e6+9);

    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        if(i-m>=0)
        {
            dp[i]=(dp[i-1]+dp[i-m])%modulo;
        }
        else
        {
            dp[i]=dp[i-1];
        }
    }

    cout<<(dp[n])%modulo;
    
    return 0;
}