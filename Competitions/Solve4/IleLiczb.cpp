//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int mod=1e6;
int liczby_n_cyfrowe(int n, int k){
    if(k>9*n){
        return 0;
    }
    if(n==1){
        return 1;
    }
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));

    dp[0][0]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k;j++){
            for(int cyfra=0;cyfra<=9;cyfra++){
                if(j>=cyfra){  
                    dp[i][j]=(dp[i][j]+dp[i-1][j-cyfra])%mod;
                }
            }
        }
    }

    return dp[n][k];
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    cout<<liczby_n_cyfrowe(n,k);

    return 0;
}