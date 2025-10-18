//Karol Dziekan
#include <iostream>

using namespace std;

const int inf=1e5;
int dp[10001][1<<10][11];
int dziela[10001];

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>dziela[i];
        dziela[i]--;
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<(1<<k);j++){
            for(int l=0;l<=k;l++){
                dp[i][j][l]=inf;
            }
        }
    }
    dp[0][0][k]=0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<k);j++){
            if(j&(1<<dziela[i])){
                for(int l=0;l<=k;l++){
                    if(l==dziela[i]){
                        dp[i][j][l]=min(dp[i][j][l],dp[i-1][j][l]);
                    }else{
                        dp[i][j][l]=min(dp[i][j][l],dp[i-1][j][l]+1);
                        dp[i][j][dziela[i]]=min(dp[i][j][dziela[i]],dp[i-1][j^(1<<dziela[i])][l]);
                    }
                }
            }else{
                for(int l=0;l<=k;l++){
                    dp[i][j][l]=min(dp[i][j][l],dp[i-1][j][l]+1);
                }
            }
        }
    }

    int wynik=inf;
    for(int i=0;i<(1<<k);i++){
        for(int j=0;j<=k;j++){
            wynik=min(wynik,dp[n][i][j]);
        }
    }

    cout<<wynik;
    return 0;
}