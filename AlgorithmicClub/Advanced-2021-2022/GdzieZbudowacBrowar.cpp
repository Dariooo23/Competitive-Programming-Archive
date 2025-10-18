//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int iloscmiast,najdalejnalewo=0,najdalejnaprawo=0,odleglosclewo=0,odlegloscprawo=0;
long long int zapotrzebowanielewo=0,zapotrzebowanieprawo=0,koszt=0,wynik=1e18;
vector<long long int> zapotrzebowanie;
vector<long long int> odleglosc;

void pierwsze_miasto()
{
    int indeks=1;
    while(indeks<iloscmiast)
    {
        if(odleglosclewo+odleglosc[(najdalejnalewo+iloscmiast-1)%iloscmiast]<odlegloscprawo+odleglosc[najdalejnaprawo])
        {
            najdalejnalewo=(najdalejnalewo+iloscmiast-1)%iloscmiast;
            odleglosclewo=odleglosclewo+odleglosc[najdalejnalewo];
            koszt=koszt+odleglosclewo*zapotrzebowanie[najdalejnalewo];
            zapotrzebowanielewo=zapotrzebowanielewo+zapotrzebowanie[najdalejnalewo];
        }
        else
        {
            odlegloscprawo=odlegloscprawo+odleglosc[najdalejnaprawo];
            najdalejnaprawo=(najdalejnaprawo+1)%iloscmiast;
            koszt=koszt+odlegloscprawo*zapotrzebowanie[najdalejnaprawo];
            zapotrzebowanieprawo=zapotrzebowanieprawo+zapotrzebowanie[najdalejnaprawo];
        }
        indeks++;
    }
    wynik=min(wynik,koszt);
}

void pozostale_miasta()
{
    for(int i=1;i<iloscmiast;i++)
    {
        zapotrzebowanielewo=zapotrzebowanielewo+zapotrzebowanie[i-1];
        koszt=koszt+odleglosc[i-1]*(zapotrzebowanielewo-zapotrzebowanieprawo);
        zapotrzebowanieprawo=zapotrzebowanieprawo-zapotrzebowanie[i];
        odleglosclewo=odleglosclewo+odleglosc[i-1];
        odlegloscprawo=odlegloscprawo-odleglosc[i-1];

        while(odleglosclewo>(odlegloscprawo+odleglosc[najdalejnaprawo]))
        {
            odlegloscprawo=odlegloscprawo+odleglosc[najdalejnaprawo];
            najdalejnaprawo=(najdalejnaprawo+1)%iloscmiast;
            najdalejnalewo=(najdalejnalewo+1)%iloscmiast;
            zapotrzebowanieprawo=zapotrzebowanieprawo+zapotrzebowanie[najdalejnaprawo];
            zapotrzebowanielewo=zapotrzebowanielewo-zapotrzebowanie[najdalejnaprawo];
            koszt=koszt+zapotrzebowanie[najdalejnaprawo]*(odlegloscprawo-odleglosclewo);
            odleglosclewo=odleglosclewo-odleglosc[najdalejnaprawo];
        }

        wynik=min(wynik,koszt);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>iloscmiast;

    zapotrzebowanie.resize(iloscmiast+1);
    odleglosc.resize(iloscmiast+1);

    for(int i=0;i<iloscmiast;i++)
    {
        cin>>zapotrzebowanie[i]>>odleglosc[i];
    }

    pierwsze_miasto();

    pozostale_miasta();

    cout<<wynik;
    return 0;
}
 