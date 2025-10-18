//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct zbior{
    int ilosc,miejsce;
};

vector<int> przedmioty;
vector<int> plecaki;
vector<zbior> dp;

bool cmp(const int &a, const int &b)
{
    return a>b;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int ilosc_przedmiotow,ilosc_plecakow;

    cin>>ilosc_przedmiotow>>ilosc_plecakow;

    dp.resize((1<<ilosc_przedmiotow),{30,0});
    dp[0]={0,0};

    for(int i=1;i<=ilosc_przedmiotow;i++)
    {
        int przedmiot;
        cin>>przedmiot;
        przedmioty.push_back(przedmiot);
    }
    for(int i=1;i<=ilosc_plecakow;i++)
    {
        int plecak;
        cin>>plecak;
        plecaki.push_back(plecak);
    }

    sort(plecaki.begin(),plecaki.end(),cmp);

    for(int i=1;i<(1<<ilosc_przedmiotow);i++)
    {
        for(int j=0;j<ilosc_przedmiotow;j++)
        {
            if(i&(1<<j))
            {
                int zbior=i-(1<<j);
                if(dp[zbior].miejsce+przedmioty[j]<=plecaki[dp[zbior].ilosc])
                {
                    if(dp[zbior].ilosc<dp[i].ilosc)
                    {
                        dp[i].ilosc=dp[zbior].ilosc;
                        dp[i].miejsce=dp[zbior].miejsce+przedmioty[j];
                    }
                    if(dp[zbior].ilosc==dp[i].ilosc && dp[zbior].miejsce+przedmioty[j]<dp[i].miejsce)
                    {
                        dp[i].miejsce=dp[zbior].miejsce+przedmioty[j];
                    }
                }
                else
                {
                    if(przedmioty[j]<=plecaki[dp[zbior].ilosc+1])
                    {
                        if(dp[zbior].ilosc+1<dp[i].ilosc)
                        {
                            dp[i].ilosc=dp[zbior].ilosc+1;
                            dp[i].miejsce=przedmioty[j];
                        }
                        if(dp[zbior].ilosc+1==dp[i].ilosc && przedmioty[j]<dp[i].miejsce)
                        {
                            dp[i].miejsce=przedmioty[j];
                        }
                    }
                    
                }
                
            }
        }
        if(dp[i].ilosc==30)
        {
            cout<<"NIE";
            return 0;
        }
    }

    cout<<dp[(1<<ilosc_przedmiotow)-1].ilosc+1;
    
    return 0;
}
 