//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> tab;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    //WCZYTYWANIE DANYCH
    int n,k;
    cin>>n>>k;
    tab.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>tab[i];
    }

    //ALGORYTM GĄSIENICY
    int poczatek=1,koniec=1,suma=tab[1],wynik=0;
    while(poczatek<=n)
    {
        if(koniec<poczatek)
        {
            koniec=poczatek;
            suma=tab[poczatek];
        }
        while(koniec+1<=n && suma+tab[koniec+1]<k)
        {
            suma=suma+tab[koniec+1];
            koniec++;
        }
        wynik=max(wynik,koniec-poczatek+1);
        suma=suma-tab[poczatek];
        poczatek++;
    }

    //NAJDLUŻSZY PODCIĄG O SUMIE NIE WIĘKSZEJ NIŻ K
    cout<<wynik;

    return 0;
}