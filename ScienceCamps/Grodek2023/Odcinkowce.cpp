//Karol Dziekan
#include <bits/stdc++.h>
using namespace std;

void wzorcowka(int n){
    vector<long long int> dlugosci(n+10);
    vector<vector<long long int>> dp(n+10,vector<long long int> (n+10,0));
    for(int i=1;i<=n;i++)cin>>dlugosci[i];
    for(int dl=3;dl<=n;dl++)
        for(int pocz=1;pocz<=n-dl+1;pocz++)
            for(int gr=1;gr<dl;gr++)
                dp[dl][pocz]=max(dp[dl][pocz],dlugosci[pocz]*dlugosci[pocz+dl-1]+dp[gr][pocz]+dp[dl-gr+1][pocz+gr-1]);
    cout<<dp[n][1]<<endl;
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int q,n;
    cin>>q;
    while(q--){
        cin>>n;
        wzorcowka(n);
    }
    return 0;
}
 