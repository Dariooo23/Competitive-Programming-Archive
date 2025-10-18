//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

struct Struktura2{
    int tab[100];

    Struktura2(){
        for (int i = 0; i < 100; i++){
            tab[i] = i;
        }
    }
};

struct Struktura1{
    int a;
    char b;
    bool c;
    shared_ptr<Struktura2> d;
};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    shared_ptr<Struktura2> wskaznik(new Struktura2);
    
    cout << wskaznik->tab[0];
    
    Struktura1* struktura;
    struktura->d = wskaznik;



    return 0;
}
