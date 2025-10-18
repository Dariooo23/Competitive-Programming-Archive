//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int modulo=1e9+7;
vector<long long int> ostatnia;
vector<long long int> wejscie;
vector<long long int> dp;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int n;
    cin>>n;

    ostatnia.resize(1000009,0);
    wejscie.resize(n+10,0);
    dp.resize(n+10,0);

    for(int i=1;i<=n;i++){
        cin>>wejscie[i];
    }

    dp[0]=1;

    for(int i=1;i<=n;i++){
        dp[i]=(dp[i-1]*2-ostatnia[wejscie[i]]+modulo)%modulo;
        ostatnia[wejscie[i]]=dp[i-1]%modulo;
    }

    cout<<dp[n];
    return 0;
}
 