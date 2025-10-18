#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n=0,k=0,dziewczynki=0;
    cin>>n>>k;
    int chidzi[n+1];
    for (int i=1;i<=n;i++)
    {
        cin>>chidzi[i];
    }
    int poczatek=1;
    int koniec=1;
    int wynik=n+1;
    if (chidzi[1]==0)
    {
        dziewczynki=1;
    }
    else
    {
        dziewczynki=0;
    }
    while(koniec<n)
    {
        while(dziewczynki<k && poczatek<n)
        {
            poczatek=poczatek+1;
            if (chidzi[poczatek]==0)
            {
                dziewczynki=dziewczynki+1;
            }
        }
        if (dziewczynki==k)
        {
            wynik=min(wynik,poczatek-koniec+1);
        }
        if (chidzi[koniec]==0)
        {
            dziewczynki=dziewczynki-1;
        }
        koniec=koniec+1;
    }
    if (wynik==n+1)
    {
        cout<<"NIE";
    }
    else
    {
        cout<<wynik-k;
    }
    return 0;
}