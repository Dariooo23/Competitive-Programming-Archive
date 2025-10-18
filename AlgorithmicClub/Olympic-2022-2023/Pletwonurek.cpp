//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int,int> PII;

struct butla{
    int tlen,azot,waga;
};

vector<vector<int>> dp(100,vector<int> (100,1e6+9));
vector<butla> butle(1e4);

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int wymtlen,wymazot,ilosc;
    cin>>wymtlen>>wymazot>>ilosc;
    for(int i=0;i<ilosc;i++)
    {
        cin>>butle[i].tlen>>butle[i].azot>>butle[i].waga;
    }


    dp[0][0]=0;
    for(int k=0;k<ilosc;k++)
    {
        for(int i=wymtlen;i>=0;i--)
        {
            for(int j=wymazot;j>=0;j--)
            {
                int tlen,azot;
                tlen=min(wymtlen,i+butle[k].tlen);
                azot=min(wymazot,j+butle[k].azot);
                dp[tlen][azot]=min(dp[tlen][azot],dp[i][j]+butle[k].waga);
            }
        }
    }

    cout<<dp[wymtlen][wymazot];

    return 0;
}