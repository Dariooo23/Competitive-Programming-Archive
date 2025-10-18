//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    LL n;
    cin>>n;

    vector<LL> tab(n+1);
    vector<vector<LL>> dp(4,vector<LL>(n+1,-1e18));

    dp[0][0]=0;
    dp[1][0]=0;
    dp[2][0]=0;
    dp[3][0]=0;

    for(LL i=1;i<=n;i++)cin>>tab[i];

    for(LL i=1;i<=n;i++){
        dp[0][i]=max(dp[0][i],dp[0][i-1]+tab[i]);
    }
    for(LL i=1;i<=n;i++){
        if(i>=3)dp[1][i]=max(dp[1][i],dp[0][i-3]);
    }
    for(LL i=1;i<=n;i++){
        if(i>=3){
            dp[2][i]=max(dp[2][i],max(dp[1][i-1],max(dp[1][i-2],dp[1][i])));
        }
    }
    for(LL i=1;i<=n;i++){
        if(i>=3)dp[1][i]=max(dp[1][i],max(dp[1][i],dp[1][i-1]+tab[i]));
        else dp[1][i]=max(dp[1][i],dp[0][i]);
    }
    for(LL i=1;i<=n;i++){
        if(i>=3){
            dp[2][i]=max(dp[2][i],max(dp[2][i],dp[1][i-3]));
        }
    }
    for(LL i=1;i<=n;i++){
        if(i>=3){
            dp[3][i]=max(dp[3][i],max(dp[2][i-1],max(dp[2][i-2],dp[2][i])));
        }
    }
    for(LL i=1;i<=n;i++){
        if(i>=3)dp[2][i]=max(dp[2][i],max(dp[2][i],dp[2][i-1]+tab[i]));
        else dp[2][i]=max(dp[2][i],dp[0][i]);
    }
    for(LL i=1;i<=n;i++){
        if(i>=3){
            dp[3][i]=max(dp[3][i],max(dp[3][i],dp[2][i-3]));
        }
    }
    for(LL i=1;i<=n;i++){
        if(i>=3)dp[3][i]=max(dp[3][i],dp[3][i-1]+tab[i]);
        else dp[3][i]=dp[0][i];
    }

    cout<<max((LL)0,max(dp[2][n],max(dp[1][n],dp[0][n])))<<endl;
    return 0;
}