//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n,m,k;
vector<int> graf;
vector<vector<long long int>> dp;
vector<int> fotogenicznosc;

void oblicz_dp(){
    for(int i=n;i>=1;i--){
        for(int j=0;j<(1<<k);j++){

            if(!(j&1)){
                dp[i][j]=dp[i+1][(j>>1)];
            }else{
                dp[i][j]=dp[i+1][((j>>1)|graf[i])]+fotogenicznosc[i];
            }
        }
    }
    return;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n>>m>>k; 

    graf.resize(n+5,0);        
    fotogenicznosc.resize(n+10);
    dp.resize(n+5,vector<long long int> ((1<<k)+5,0));

    for(int i=1;i<=n;i++){
        cin>>fotogenicznosc[i];
    }

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        graf[a]=graf[a]+(1<<(b-a-1));
    }

    oblicz_dp();

    for(int i=1;i<=n;i++){
        cout<<dp[i][1]<<endl;
    }

    return 0;
}
 