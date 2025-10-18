// Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> wejscie(n+1);
    vector<long long int> dp(n+1);

    for(int i=1;i<=n;i++){
        cin>>wejscie[i];
    }

    dp[0]=0;
    dp[1]=wejscie[1];
    for(int i=2;i<=n;i++){
        dp[i]=min(dp[i-1],dp[i-2])+wejscie[i];
    }

    cout<<min(dp[n],dp[n-1]);
    return 0;
}