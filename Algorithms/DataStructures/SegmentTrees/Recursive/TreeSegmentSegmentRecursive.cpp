//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

//PODSTAWA DRZEWA// ILOSC WIERZCHOLKOW NA SAMYM DOLE DRZEWA
const long long int M=1<<3;

//DRZEWO PRZEDZIALOWE PRZECHOWUJACE WARTOSCI
long long int tree[M*2+1];

//TABLICA PRZETRZYMUJACA WARTOSCI DOPÓKI NIE ZAPYTAMY SIĘ O PRZEDZIAŁ KTÓREGO DOTYCZY
long long int lazy[M*2+1];

//FUNKCJA DODAJĄCA W PUNKCIE W TREE WARTOŚĆ KTÓRĄ CHCEMY DODAĆ RAZY ILOŚĆ LIŚCI ORAZ DODAJĄCA W LAZY WARTOŚĆ KTÓRĄ TRZEBA PÓŹNIEJ PRZEKAZAĆ SYNOM
void dodaj(int punkt,int ilosc,long long int ile){
    lazy[punkt]=lazy[punkt]+ile;
    tree[punkt]=tree[punkt]+ile*ilosc;
}

//FUNKCJA PRZEKAZUJĄCA WARTOŚCI Z LAZY OD OJCA DO SYNÓW
void przekaz(int punkt,int ilosc){
    dodaj(2*punkt,ilosc/2,lazy[punkt]);
    dodaj(2*punkt+1,ilosc/2,lazy[punkt]);
    lazy[punkt]=0;
}

//AKTUALIZACJA WARTOŚCI NA PRZEDZIALE X-Y O WARTOSC ILE
void update(int gdzie,int pocz,int kon,int x,int y,long long int ile){
    //PUNKT W KTÓRYM JESTEŚMY ZNAJDUJĘ SIĘ CAŁY W PRZEDZIALE, DODAJEMY DO PUNKTU WARTOŚĆ Z LAZY I KOŃCZYMY AKTUALIZACJE NA TYM PRZEDZIALE
    if(x<=pocz && y>=kon){
        dodaj(gdzie,kon-pocz+1,ile);
        return;
    }

    //PUNKT W KTÓRYM JESTEŚMY ZNAJDUJĘ SIĘ CZĘŚCIOWO W PRZEDZIALE, PRZEKAZUJEMY JEGO SYNOM WARTOŚĆ Z LAZY I KONTYNUUJEMY PRZESZUKIWANIE
    przekaz(gdzie,kon-pocz+1);

    //ROZCHODZIMY SIĘ NA LEWO I PRAWO TAK DŁUGO JAK NIE OBEJMIEMY CAŁEGO POSZUKIWANEGO OBSZARU
    int mid=(pocz+kon)/2;
    if(x<=mid){
        update(2*gdzie,pocz,mid,x,y,ile);
    }
    if(y>mid){
        update(2*gdzie+1,mid+1,kon,x,y,ile);
    }

    //NA KONCU AKTUALIZUJEMY WSZYSTKICH ODWIEDZONYCH PRZODKOW LISCIA
    tree[gdzie]=tree[2*gdzie]+tree[2*gdzie+1];
    return;
}

//ZAPYTANIE O SUME NA PRZEDZIALE X-Y
long long int query(int gdzie, int pocz, int kon, int x,int y){

   //PUNKT W KTÓRYM JESTEŚMY ZNAJDUJĘ SIĘ CAŁY W PRZEDZIALE, ZWRACAMY JEGO WARTOŚĆ
   if(x<=pocz && y>=kon){
       return tree[gdzie];
   }
   //PUNKT W KTÓRYM JESTEŚMY ZNAJDUJĘ SIĘ CZĘŚCIOWO W PRZEDZIALE, PRZEKAZUJEMY JEGO SYNOM WARTOŚĆ Z LAZY I KONTYNUUJEMY PRZESZUKIWANIE
   przekaz(gdzie,kon-pocz+1);

   //ROZCHODZIMY SIĘ NA LEWO I PRAWO TAK DŁUGO JAK NIE OBEJMIEMY CAŁEGO POSZUKIWANEGO OBSZARU
   long long int mid=(pocz+kon)/2,wynik=0;
   if(x<=mid){
       wynik=wynik+query(2*gdzie,pocz,mid,x,y);
   }
   if(y>mid){
       wynik=wynik+query(2*gdzie+1,mid+1,kon,x,y);
   }

   return wynik;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //WCZYTANIE DANYCH 
    int n,q;
    cin>>n>>q;

    //AKTUALIZACJA LUB ZAPYTANIE NA PRZEDZIALE
    while(q>0){
        int t,a,b,c;
        cin>>t;
        if(t==1){
            cin>>a>>b>>c;
            update(1,1,M,a,b,c);
        }
        else{
            cin>>a>>b;
            cout<<query(1,1,M,a,b)<<endl;
        }
        q--;
    }

    return 0;
}
 