//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int M=1<<20;
vector<long long int> tree(M*2);

void update(int indeks,int wartosc,int koniec_tablicy)
{
    while(indeks<=koniec_tablicy)
    {
        tree[indeks]=tree[indeks]+wartosc;
        indeks=indeks+(indeks&(-indeks));
    }

    return;
}
long long int query(int indeks)
{
    long long int wynik=0;
    while(indeks!=0)
    {
        wynik=wynik+tree[indeks];
        indeks=indeks-(indeks&(-indeks));
    }

    return wynik;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int rozmiar_drzewa,ilosc_zapytan;
    cin>>rozmiar_drzewa>>ilosc_zapytan;

    while(ilosc_zapytan--)
    {
        int operacja,indeks,wartosc;
        cin>>operacja;

        if(operacja==1)
        {
            cin>>indeks>>wartosc;
            update(indeks,wartosc,rozmiar_drzewa);
        }
        else
        {
            cin>>indeks;
            query(indeks);
        }
    }
    return 0;
}
 