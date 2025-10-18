//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int,int> PII;

LL suma=0,wynik=0;
vector<int> stos1,stos2;
vector<vector<int>> dp;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    stos1.resize(n+1);
    stos2.resize(m+1);
    dp.resize(n+1,vector<int> (m+1));

    for(int i=1;i<=n;i++)
    {
        cin>>stos1[i];
        suma=suma+stos1[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>stos2[i];
        suma=suma+stos2[i];
    }

    dp[0][0]=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            
            if(i!=0 && j!=0)
            {
                dp[i][j]=max(stos1[i]-dp[i-1][j],stos2[j]-dp[i][j-1]);
            }
            else
            {
                if(i==0 && j!=0)
                {
                    dp[i][j]=stos2[j]-dp[i][j-1];
                }
                else
                {
                    if(i!=0 && j==0)
                    {
                        dp[i][j]=stos1[i]-dp[i-1][j];
                    }
                }
            }
        }
    }

    cout<<(suma+dp[n][m])/2;
    return 0;
}