//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> wejscie(m+1,vector<int>(n+1,0));
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>wejscie[i][j];
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+wejscie[i][j];
        }
    }

    cout<<dp[m][n]<<endl;
    wejscie.clear();
    dp.clear();

    return;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}