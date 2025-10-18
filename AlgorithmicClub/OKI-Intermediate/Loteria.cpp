//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

long long int modulo=1e9+9;
vector<long long int> dp;

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,k;
    cin>>n>>k;

    dp.resize(200009,0);
    dp[0]=1;

    for(int i=1;i<=n;i++){
        long long int a;
        cin>>a;
        dp[a]+=dp[a-1];
        dp[a]%=modulo;
    }

    cout<<dp[k];
    return 0;
}