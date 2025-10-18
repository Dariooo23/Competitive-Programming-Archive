#include <bits/stdc++.h>

using namespace std;
int  dasie[1000000]={0};
vector<pair<int,int>> kasa;
int main()
{

    int t,kwota=0;
    cin>>t;
    pair<int,int> banknoty;
    for(int i=0;i<t;i++)
    {
     cin>>banknoty.first>>banknoty.second;
     kwota=kwota+banknoty.first*banknoty.second;
     kasa.push_back(banknoty);
    }

    if(kwota%2==1)
    {
        cout<<"NIE";
        return 0;
    }
    else
    {
        kwota=kwota/2;

        for(int i=0;i<t;i++)
        {
            for(int j=0;j<kasa[i].first;j++)
            {
                int ilosc=kasa[i].second;
                for(int k=j;k<=kwota;k=k+kasa[i].first)
                {
                    if(k-kasa[i].first<0)
                    {
                        continue;
                    }
                    if(k-dasie[k-kasa[i].first]==kasa[i].first &&dasie[k]==0)
                    {
                        ilosc--;
                        dasie[k]=k;
                    }
                    if(ilosc==0)
                    {
                        break;
                    }

                }
                if(dasie[kwota]!=0)
                {
                    cout<<"TAK";
                    return 0;
                }
            }
        }
    }
    cout<<"NIE";
    return 0;
}
