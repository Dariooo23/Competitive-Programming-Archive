//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7;
struct macierz{
    long long int a,b,c,d;
};

macierz mnozenie(macierz a,macierz b){
    macierz wynik;
    wynik.a=((a.a*b.a)%mod+(a.b*b.c)%mod)%mod;
    wynik.b=((a.a*b.b)%mod+(a.b*b.d)%mod)%mod;
    wynik.c=((a.c*b.a)%mod+(a.d*b.c)%mod)%mod;
    wynik.d=((a.c*b.b)%mod+(a.d*b.d)%mod)%mod;
    return wynik;
}
macierz potegowanie(macierz fib, int potega){
    if(potega==1){
        return {1,1,1,0};
    }
    if(potega%2){
        return mnozenie(fib,potegowanie(fib,potega-1));
    }else{
        macierz wynik=potegowanie(fib,potega/2);
        return mnozenie(wynik,wynik); 
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    macierz fib={1,1,1,0};
    int potega;
    cin>>potega;
    potega=potega+3;

    fib=potegowanie(fib,potega);
    cout<<fib.b-1;
    return 0;
}