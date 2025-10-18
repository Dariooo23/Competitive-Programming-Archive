//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;
//PODSTAWA DRZEWA// ILOSC WIERZCHOLKOW NA SAMYM DOLE DRZEWA
const long long int M=1<<20;

long long int tree[M*2+1];

//ZAPYTANIE O SUME NA PRZEDZIALE X-Y
long long int query(int gdzie, int pocz, int kon, int x, int y)
{
    //JEŻELI ZNALEŹLIŚMY PUNKT ODPOWIADAJĄCY ZA PRZEDZIAŁ MIESZCZĄCY SIĘ W ZAPYTANIU TO GO ZWRACAMY
    if(x<=pocz && y>=kon)
    {
        return tree[gdzie];
    }


    long long int mid=(pocz+kon)/2,wynik=0;
    //ROZCHODZIMY SIĘ NA LEWO I PRAWO TAK DŁUGO JAK NIE OBEJMIEMY CAŁEGO POSZUKIWANEGO OBSZARU
    if(x<=mid)
    {
        wynik=wynik+query(2*gdzie,pocz,mid,x,y);
    }
    if(y>mid)
    {
        wynik=wynik+query(2*gdzie+1,mid+1,kon,x,y);
    }
    return wynik;
}

//AKTUALIZACJA WARTOŚCI W PUNKCIE X NA WARTOŚĆ Y
void update(int gdzie,int pocz,int kon,int x,long long int y)
{
    //JEŻELI ZNALEŹLIŚMY LIŚĆ TO AKTUALIZUJEMY W NIM WARTOŚĆ
    if(x==pocz && kon==x)
    {
        tree[gdzie]=tree[gdzie]+y;
        return;
    }

    int mid=(pocz+kon)/2;
    if(x<=mid)//JEZELI SZUKANY INDEKS JEST MNIEJSZY LUB RÓWNY ŚRODKOWI TO SKRECAMY W LEWO W PRZECIWNYM WYPADKU W PRAWO
    {
        update(2*gdzie,pocz,mid,x,y);
    }
    else
    {
        update(2*gdzie+1,mid+1,kon,x,y);
    }

    //NA KONCU AKTUALIZUJEMY WSZYSTKICH ODWIEDZONYCH PRZODKOW LISCIA
    tree[gdzie]=tree[2*gdzie]+tree[2*gdzie+1];
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //WCZYTANIE DANYCH 
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        update(1,1,M,i,a);
    }

    //AKTUALIZACJA W PUNKCIE LUB ZAPYTANIE NA PRZEDZIALE
    while(q>0)
    {
        int t,a,b;
        cin>>t>>a>>b;
        if(t==1)
        {
            update(1,1,M,a,b);
        }
        else
        {
            cout<<query(1,1,M,a,b)<<endl;
        }
        q--;
    }

    return 0;
}
 