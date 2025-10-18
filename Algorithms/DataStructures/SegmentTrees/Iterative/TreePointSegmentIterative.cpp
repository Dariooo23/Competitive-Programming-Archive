//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;
//PODSTAWA DRZEWA// ILOSC WIERZCHOLKOW NA SAMYM DOLE DRZEWA
const long long int M=1<<20;

long long int tree[M*2];

//ZAPYTANIE O SUME NA PRZEDZIALE
long long int query(int pocz,int kon){
    //ZWIEKSZAMY INDEKSY O BAZE DRZEWA
    pocz=pocz+M;
    kon=kon+M;
    //USTAWIAMY WYNIK JAKO WARTOSCI NA INDEKSACH WEJSCIOWYCH
    long long int wynik=tree[pocz];
    if(pocz!=kon){
        wynik=wynik+tree[kon];
    }

    //ZWIEKSZAMY WYNIK DO MOMENTU SPOTKANIA SIĘ INDEKSÓW O KOLEJNE PUNKTY (DLA POCZ PUNKTY PO PRAWEJ)(DLA KON PUNKTY PO LEWEJ)
    while(pocz/2!=kon/2){
        if(pocz%2==0){
            wynik=wynik+tree[pocz+1];
        }
        if(kon%2==1){
            wynik=wynik+tree[kon-1];
        }
        pocz=pocz/2;
        kon=kon/2;
    }
    return wynik;
}

//AKTUALIZACJA WARTOŚCI W PUNKCIE X NA WARTOŚĆ Y
void update(int x,long long int y){
    //ZWIEKSZAMY INDEKS O BAZE DRZEWA
    x=x+M;
    //AKTUALIZUJEMY WARTOSC W LISCIU
    tree[x]=tree[x]+y;
    //AKTUALIZUJEMY WARTOSC WE WSZYSTKICH PRZODKACH LISCIA
    while(x!=1){
        x=x/2;
        tree[x]=tree[2*x]+tree[2*x+1];
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
        int a;
        cin>>a;
        update(i,a);
    }

    //AKTUALIZACJA W PUNKCIE LUB ZAPYTANIE NA PRZEDZIALE
    while(q>0)
    {
        int t,a,b;
        cin>>t>>a>>b;
        if(t==1)
        {
            update(a,b);
        }
        else
        {
            cout<<query(a,b)<<endl;
        }
        q--;
    }

    return 0;
}
 