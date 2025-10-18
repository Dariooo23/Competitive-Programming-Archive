//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;
//PODSTAWA DRZEWA// ILOSC WIERZCHOLKOW NA SAMYM DOLE DRZEWA
const long long int M=1<<20;

vector<long long int> tree(M*2+1,0);

//AKTUALIZACJA NA PRZEDZIALE X-Y O WARTOSC
void update(int gdzie, int pocz, int kon, int x, int y, long long int wartosc)
{
    //JEŻELI ZNALEŹLIŚMY PUNKT ODPOWIADAJĄCY ZA PRZEDZIAŁ MIESZCZĄCY SIĘ W ZAPYTANIU TO GO AKTUALIZUJEMY
    if(x<=pocz && y>=kon)
    {
        tree[gdzie]=tree[gdzie]+wartosc;
        return;
    }


    long long int mid=(pocz+kon)/2;
    //ROZCHODZIMY SIĘ NA LEWO I PRAWO TAK DŁUGO JAK NIE OBEJMIEMY CAŁEGO POSZUKIWANEGO OBSZARU
    if(x<=mid)
    {
        update(2*gdzie,pocz,mid,x,y,wartosc);
    }
    if(y>mid)
    {
        update(2*gdzie+1,mid+1,kon,x,y,wartosc);
    }
}

//ZAPYTANIE W PUNKCIE X
long long int query(int gdzie,int pocz,int kon,int x)
{
    //JEŻELI ZNALEŹLIŚMY LIŚĆ TO ZWRACAMY JEGO WARTOSC
    if(x==pocz && kon==x)
    {
        return tree[gdzie];
    }

    int mid=(pocz+kon)/2;
    if(x<=mid)//JEZELI SZUKANY INDEKS JEST MNIEJSZY LUB RÓWNY ŚRODKOWI TO SKRECAMY W LEWO W PRZECIWNYM WYPADKU W PRAWO
    {
        return tree[gdzie]+query(2*gdzie,pocz,mid,x);
    }
    else
    {
        return tree[gdzie]+query(2*gdzie+1,mid+1,kon,x);
    }
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
        int a,b,c;
        cin>>a>>b>>c;
        update(1,1,M,a,b,c);
    }

    //AKTUALIZACJA NA PRZEDZIALE LUB ZAPYTANIE W PUNKCIE
    while(q>0)
    {
        int t,a,b,c;
        cin>>t;

        if(t==1)
        {
            cin>>a>>b>>c;
            update(1,1,M,a,b,c);
        }
        else
        {
            cin>>a;
            cout<<query(1,1,M,a)<<endl;
        }
        q--;
    }

    return 0;
}
 