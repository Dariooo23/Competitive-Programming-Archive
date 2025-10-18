//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,wynik=0,poczatek=0,koniec=1;
    cin>>n;

    string slowo;
    cin>>slowo;

    while(koniec!=slowo.size())
    {
        if(slowo[poczatek]==slowo[koniec])
        {
            wynik++;
            koniec++;
        }
        else
        {
            poczatek=koniec;
            koniec++;
        }
    }
    cout<<wynik;

    return 0;
}
 