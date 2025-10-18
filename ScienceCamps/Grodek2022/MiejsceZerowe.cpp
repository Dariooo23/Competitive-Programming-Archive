//Karol Dziekan
#include <bits/stdc++.h>
#include "mzelib.h"

using namespace std;

long long int modulo,stopien;

long long int potega(long long int a,long long int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2==0)
    {
        long long int wynik=potega(a,b/2);
        return (wynik*wynik)%modulo;
    }
    else
    {
        return (a*potega(a,b-1))%modulo;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    stopien=dajN();
    modulo=dajP();

    vector<long long int> wartosci(stopien+1);
    vector<long long int> iloczyn(stopien+1,1);
    vector<long long int> licznik(modulo+1,0);

    for(int i=0;i<=stopien;i++)
    {
        wartosci[i]=zgaduj(i);
    }
    for(int i=0;i<=stopien;i++)
    {
        for(int j=0;j<=stopien;j++)
        {
            if(j==i)
            {
                continue;
            }
            iloczyn[i]=((iloczyn[i]*(i-j))%modulo+modulo)%modulo;
        }
        iloczyn[i]=potega(iloczyn[i],modulo-2);
    }

    for(int i=0;i<=modulo;i++)
    {
        licznik[i]=potega(i,modulo-2);
    }

    for(int x=stopien+1;x<modulo;x++)
    {
        long long int mnozenie=1,suma=0;
        for(int j=0;j<=stopien;j++)
        {
            mnozenie=1;
            mnozenie=(((((mnozenie*wartosci[j])%modulo)*iloczyn[j])%modulo)*licznik[x-j])%modulo;
            suma=(suma+mnozenie)%modulo;
        }
        if(suma==0)
        {
            zgaduj(x);
        }
    }
}
 