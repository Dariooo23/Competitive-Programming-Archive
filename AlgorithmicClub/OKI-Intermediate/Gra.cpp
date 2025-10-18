//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> wejscie(n+1);
    vector<int> dp(n+1);

    for(int i=0;i<n;i++){
        cin>>wejscie[i];
    }

    dp[0]=wejscie[0];
    for(int i=1;i<n;i++){
        dp[i]=dp[i-1];
        if(i-2>=0){
            dp[i]=max(dp[i-2],dp[i]);
        }
        if(i-3>=0){
            dp[i]=max(dp[i-3],dp[i]);
        }
        if(i-4>=0){
            dp[i]=max(dp[i-4],dp[i]);
        }
        if(i-5>=0){
            dp[i]=max(dp[i-5],dp[i]);
        }
        if(i-6>=0){
            dp[i]=max(dp[i-6],dp[i]);
        }

        dp[i]+=wejscie[i];
    }

    cout<<dp[n-1];
    return 0;
}