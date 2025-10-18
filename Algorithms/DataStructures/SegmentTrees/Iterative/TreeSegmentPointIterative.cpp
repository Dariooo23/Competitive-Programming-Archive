//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;
//PODSTAWA DRZEWA// ILOSC WIERZCHOLKOW NA SAMYM DOLE DRZEWA
const long long int M=1<<20;

long long int tree[M*2];

//AKTUALIZACJA PUNKTOW NA PRZEDZIALE A-B O C
void update(int a,int b,long long int c){
    a=a+M;
    b=b+M;
    tree[a]=tree[a]+c;
    if(a!=b){
        tree[b]=tree[b]+c;
    }
    while(a/2!=b/2){
        if(a%2==0){
            tree[a+1]=tree[a+1]+c;
        }
        if(b%2==1){
            tree[b-1]=tree[b-1]+c;
        }
        a=a/2;
        b=b/2;
    }

}

//ZAPYTANIE O WARTOSC W PUNKCIE A
long long int query(int a){
    //ZWIEKSZAMY
    a=a+M;
    long long int wynik=tree[a];
    while(a!=1){
        a=a/2;
        wynik=wynik+tree[a];
    }
    return wynik;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //WCZYTANIE DANYCH 
    int q;
    cin>>q;

    //AKTUALIZACJA NA PRZEDZIALE LUB ZAPYTANIE W PUNKCIE
    while(q>0)
    {
        int t,a,b,c;
        cin>>t;
        if(t==1)
        {
            cin>>a>>b>>c;
            update(a,b,c);
        }
        else
        {
            cin>>a;
            cout<<query(a)<<endl;
        }
        q--;
    }

    return 0;
}
 