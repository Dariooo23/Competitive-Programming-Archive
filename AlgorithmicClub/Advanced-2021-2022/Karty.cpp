//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,a,modulo=1e9+7,w=0;
    cin>>n>>a;
    w=n*500;

    vector<int> karty;
    vector<int> dp;

    karty.resize(n+9);
    dp.resize(2*w+9);

    for(int i=0;i<n;i++)
    {
        cin>>karty[i];
        karty[i]=karty[i]-a;
    }

    dp[w]=1;
    for(int i=0;i<n;i++)
    {
        if(karty[i]>=0)
        {
            for(int j=2*w;j>=0;j--)
            {
                if(j-karty[i]<0 || j-karty[i]>2*w)
                {
                    continue;
                }
                
                dp[j]=(dp[j]+dp[j-karty[i]])%modulo;
            }
        }
        else
        {
            for(int j=0;j<2*w;j++)
            {
                if(j-karty[i]<0 || j-karty[i]>2*w)
                {
                    continue;
                }
                
                dp[j]=(dp[j]+dp[j-karty[i]])%modulo;
            }
        }
    }

    cout<<dp[w]-1;
    
    return 0;
}