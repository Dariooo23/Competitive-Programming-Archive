//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int wynik=0;
void iteracyjna_rekurencja(long long int poczatek,long long int koniec,long long int a, long long int b){
    while(poczatek<=b){
        if(poczatek>=a && koniec<=b){
            wynik+=koniec-poczatek+1;
        }else{
            long long int liczba=((min(b,koniec))-(max(a,poczatek))+1);
            if(liczba>=0)wynik+=liczba;
        }
        poczatek*=2;
        koniec*=2;
        koniec++;
    }
}
void wzorcowka(long long int k,long long int a,long long int b){
    wynik=0;

    if(k==0){
        cout<<b-a+1<<'\n';
        return;
    }
    if(k%2==1){
        if(k>=a && k<=b)wynik++;
        k=(long long int)(k*2);
    }
    iteracyjna_rekurencja(k,k+1,a,b);
    
    
    cout<<wynik<<'\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int q,k,a,b;
    cin>>q;
    while(q--){
        cin>>k>>a>>b;
        wzorcowka(k,a,b);
    }
    return 0;
}