//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<long long int> poziomy_kolek;
vector<long long int> poziomy_nauczycieli;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int ilosc_kolek,ilosc_nauczycieli;
    cin>>ilosc_kolek>>ilosc_nauczycieli;

    for(int i=1;i<=ilosc_kolek;i++)
    {
        long long int poziom;
        cin>>poziom;
        poziomy_kolek.push_back(poziom);
    }
    for(int i=1;i<=ilosc_nauczycieli;i++)
    {
        long long int poziom;
        cin>>poziom;
        poziomy_nauczycieli.push_back(poziom);
    }

    sort(poziomy_kolek.begin(),poziomy_kolek.end());
    sort(poziomy_nauczycieli.begin(),poziomy_nauczycieli.end());

    long long int suma_roznic=0,indeks_kolka=0,indeks_nauczyciela=0;

    while(indeks_kolka!=poziomy_kolek.size() && indeks_nauczyciela!=poziomy_nauczycieli.size())
    {
        if(poziomy_kolek[indeks_kolka]<poziomy_nauczycieli[indeks_nauczyciela])
        {
            suma_roznic=suma_roznic+poziomy_nauczycieli[indeks_nauczyciela]-poziomy_kolek[indeks_kolka];
            indeks_kolka++;
            indeks_nauczyciela++;
        }
        else
        {
            indeks_nauczyciela++;
        }
    }

    if(indeks_kolka!=poziomy_kolek.size())
    {
        cout<<"NIE"<<endl;
        cout<<ilosc_kolek-indeks_kolka;
    }
    else
    {
        cout<<"TAK"<<endl;
        cout<<suma_roznic;
    }

    return 0;
}
 