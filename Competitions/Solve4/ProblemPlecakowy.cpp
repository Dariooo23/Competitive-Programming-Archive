//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<pair<int,int>> przedmioty(n+1);
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        przedmioty[i]={a,b};
    }

    int limit;
    cin>>limit;

    vector<vector<int>> dp(n+100,vector<int> (limit+100));
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int i=0;i<=n;i++)dp[0][i]=0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=limit;j++){
            if(przedmioty[i].first>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-przedmioty[i].first]+przedmioty[i].second);
            }
        }
    }

    cout<<dp[n][limit];
    return 0;
}