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

void dodaj(int k)
{
    wskaznik_na_koniec++;

    if(wskaznik_na_koniec==ilosc_faktur)
    {
        wskaznik_na_koniec=1;
    }

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

    indeks=wskaznik_na_koniec;
    while(indeks<=rozmiar_tablicy)
    {
        kwoty_faktur[indeks]=kwoty_faktur[indeks]-wartosc;
        indeks=indeks+(indeks&(-indeks));
    }

    indeks=wskaznik_na_koniec;
    while(indeks<=rozmiar_tablicy)
    {
        kwoty_faktur[indeks]=kwoty_faktur[indeks]+k;
        indeks=indeks+(indeks&(-indeks));
    }

    return;
}
void koryguj(int i,int k)
{
    int indeks;

    if(i>wskaznik_na_koniec)
    {
        i=i-wskaznik_na_koniec;
        indeks=ilosc_faktur-i;
    }
    else
    {
        indeks=wskaznik_na_koniec-i+1;
    }

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
        indeks=wskaznik_na_koniec;
        while(indeks>0)
        {
            wynik1=wynik1+kwoty_faktur[indeks];
            indeks=indeks-(indeks&(-indeks));
        }

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
