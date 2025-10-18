//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> ceny_klientow;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int liczba_telefonow,koszt_telefonu,liczba_klientow;
    cin>>liczba_telefonow>>koszt_telefonu>>liczba_klientow;

    for(int i=1;i<=liczba_klientow;i++)
    {
        int cena;
        cin>>cena;
        ceny_klientow.push_back(cena);
    }

    sort(ceny_klientow.begin(),ceny_klientow.end());

    long long int zysk=0,indeks=liczba_klientow-1,ilosc_klientow=1;;
    while(liczba_telefonow>0 && indeks>=0 && ceny_klientow[indeks]>koszt_telefonu)
    {
        zysk=max(zysk,(ceny_klientow[indeks]-koszt_telefonu)*ilosc_klientow);
        
        ilosc_klientow++;
        liczba_telefonow--;
        indeks--;
    }

    cout<<zysk;

    return 0;
}
 