//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int ilosc_faktur,rozmiar_tablicy=(1<<20)+1,wskaznik_na_koniec;
vector<long long int> kwoty_faktur;

void inicjuj(int m)
{
    ilosc_faktur=m;
    ilosc_faktur++;
    wskaznik_na_koniec=0;
    kwoty_faktur.resize(rozmiar_tablicy,0);

    return;
}

void koryguj(int i,int k)
{
    int indeks;

    //Popraw indeks 
    //Jezeli "i" jest wieksze niz aktualny wskaznik na ostatnia fakture to znaczy ze musimy odjac od "i" wartosc wskaznika
    //Oraz przeniesc sie na koniec tablicy i tam szukac interesujacej nas faktury do korekty czyli (ilosc_faktur-i)
    if(i>wskaznik_na_koniec)
    {
        i=i-wskaznik_na_koniec;
        indeks=ilosc_faktur-i;
    }
    else
    {
        indeks=wskaznik_na_koniec-i+1;
    }

    //Gdy znalezlismy juz fakture to korygujemy jej wartosc i wszystkie sumy prefiksowe w ktorych sie zawiera
    while(indeks<=rozmiar_tablicy)
    {
        kwoty_faktur[indeks]=kwoty_faktur[indeks]+(long long int)k;
        indeks=indeks+(indeks&(-indeks));
    }

    return;
}
long long suma(int i)
{
    long long int wynik_glowny,wynik1=0,wynik2=0,wynik3=0;
    long long int indeks;

    if(i>wskaznik_na_koniec)
    {
        //Jezeli "i" jest wieksze niz wskaznik_na_koniec to oznacza ze czesc faktury do zsumowania jest na poczatku listy a czesc na koncu

        //Na poczatku sumujemy wszystkie faktury od 1 do wskaznik_na_koniec i zapisujemy w wynik1
        //W ten sposob uzyskujemy lewa czesc sumy o ktora sie pytamy
        indeks=wskaznik_na_koniec;
        while(indeks>0)
        {
            wynik1=wynik1+kwoty_faktur[indeks];
            indeks=indeks-(indeks&(-indeks));
        }

        //Aby uzyskac prawa czesc sumy o ktora sie pytamy musimy:
        //  -Zsumowac wszystkie faktury jakie do tej pory wczytalismy i zapisac w wynik2
        //  -Zsumowac wszystkie faktury od 1 do (ilosc_faktur-(i-wskaznik_na_koniec+1)) czyli do pierwszej nie interesujacej nas juz faktury i zapisac w wynik3
        //  -Odjac od wynik2 wynik3
        indeks=ilosc_faktur-1;
        while(indeks>0)
        {
            wynik2=wynik2+kwoty_faktur[indeks];
            indeks=indeks-(indeks&(-indeks));
        }
        indeks=ilosc_faktur-(i-wskaznik_na_koniec+1);
        while(indeks>0)
        {
            wynik3=wynik3+kwoty_faktur[indeks];
            indeks=indeks-(indeks&(-indeks));
        }
        
        wynik_glowny=wynik1+wynik2-wynik3;
    }
    else
    {
        //Zsumuj wszystkie wartosci od najnowszej faktury( indeks wskaznik_na_koniec) az do i-tej faktury wstecz (indeks wskaznik_na_koniec-i+1)
        //Czyli zsumuj wszystko od 1 indeksu do indeksu wskaznik_na_koniec po czym odejmij faktury od indeksu 1 do indeksu wskaznik_na_koniec-i
        indeks=wskaznik_na_koniec;
        while(indeks>0)
        {
            wynik1=wynik1+kwoty_faktur[indeks];
            indeks=indeks-(indeks&(-indeks));
        }

        indeks=wskaznik_na_koniec-i;
        while(indeks>0)
        {
            wynik2=wynik2+kwoty_faktur[indeks];
            indeks=indeks-(indeks&(-indeks));
        }

        wynik_glowny=wynik1-wynik2;
    }

    return wynik_glowny;
}
void dodaj(int k)
{
    wskaznik_na_koniec++;

    if(wskaznik_na_koniec==ilosc_faktur)
    {
        wskaznik_na_koniec=1;
    }

    //Znajdz wartosc na danym indeksie poprzez zsumowanie wszystkie do tego indeksu i odjecie od tej wartosci sumy do indeksu-1
    int indeks=wskaznik_na_koniec;
    long long int wartosc=0;
    while(indeks>0)
    {
        wartosc=wartosc+kwoty_faktur[indeks];
        indeks=indeks-(indeks&(-indeks));
    }
    indeks=wskaznik_na_koniec-1;
    while(indeks>0)
    {
        wartosc=wartosc-kwoty_faktur[indeks];
        indeks=indeks-(indeks&(-indeks));
    }

    //Wykasuj ze wszystkich prefiksow do samego konca te wartosc
    indeks=wskaznik_na_koniec;
    while(indeks<=rozmiar_tablicy)
    {
        kwoty_faktur[indeks]=kwoty_faktur[indeks]-wartosc;
        indeks=indeks+(indeks&(-indeks));
    }

    //Zastap wykasowana wartosc nowa wartoscia do samego konca
    indeks=wskaznik_na_koniec;
    while(indeks<=rozmiar_tablicy)
    {
        kwoty_faktur[indeks]=kwoty_faktur[indeks]+k;
        indeks=indeks+(indeks&(-indeks));
    }

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int m,wybor;
    cin>>m;

    inicjuj(m);

    while(cin>>wybor)
    {
        int a,b;
        if(wybor==1)
        {
            cin>>a;
            dodaj(a);
        }
        if(wybor==2)
        {
            cin>>a>>b;
            koryguj(a,b);
        }
        if(wybor==3)
        {
            cin>>a;
            cout<<suma(a)<<endl;
        }
    }
    return 0;
}