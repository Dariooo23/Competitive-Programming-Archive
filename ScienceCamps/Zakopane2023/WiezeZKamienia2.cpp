//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    vector<int> tab(n+1,0);

    int maksimum=0;
    for(int i=1;i<=n;i++){
        cin>>tab[i];
        maksimum=max(maksimum,tab[i]);
    }

    vector<int> dp(maksimum+1,0);

    int wynik=1,sum=0;
    for(int i=1;i<=n;i++){
        sum=(wynik-dp[tab[i]]+mod)%mod;
        wynik=(wynik+sum)%mod;
        dp[tab[i]]=(dp[tab[i]]+sum)%mod;
    }

    cout<<wynik-1;
    return 0;
}