//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
long long int modulo=1e9+7;
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    vector<int> dp(n+1,0);
    dp[0]=1;

    for(int i=1;i*i<=n;i++){
        int kwadrat=i*i;
        for(int j=n;j>=kwadrat;j--){
            dp[j]=(dp[j]+dp[j-kwadrat])%modulo;
        }
    }

    cout<<dp[n]<<"\n";
    return 0;
}