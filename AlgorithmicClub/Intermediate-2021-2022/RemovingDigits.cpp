//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> dp;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int liczba;
    cin>>liczba;

    dp.resize(liczba+1,1e9+7);
    dp[0]=0;

    for(int i=1;i<=liczba;i++)
    {
        int przypadek=i;
        while(przypadek)
        {
            int indeks=przypadek%10;
            dp[i]=min(dp[i],dp[i-indeks]+1);
            przypadek=przypadek/10;
        }
    }

    cout<<dp[liczba];

    return 0;
}
 