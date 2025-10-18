//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,suma=0;
    cin>>n;

    bitset<4000009> dp;
    dp[0]=1;
    
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        suma=suma+a;
        dp=dp|(dp<<a);
    }

    if(suma%2)
    {
        cout<<suma<<"/2 ";
    }
    else
    {
        cout<<suma/2<<"/1 ";

    }

    for(int i=suma/2;i>=0;i--)
    {
        if(dp[i])
        {
            cout<<i<<"/1";
            return 0;
        }
    }
    return 0;
}
 