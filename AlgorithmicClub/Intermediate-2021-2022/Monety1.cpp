//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> dp;
vector<int> nominaly;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,k;
    cin>>n;

    nominaly.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>nominaly[i];
    }

    cin>>k;
    dp.resize(k+1);
    dp[0]=1;

    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dp[i-nominaly[j]]==1)
            {
                dp[i]=1;
                break;
            }
        }
    }
    
    if(dp[k])
    {
        cout<<"TAK"<<endl;
    }
    else
    {
        cout<<"NIE"<<endl;
    }
    return 0;
}
 