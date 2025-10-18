//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct macierz{
    long long int a,b,c,d;
};
struct punkt{
    long long int mlode,stare;
};
const long long int M=1<<20;
const long long int mod=1e9+9;
vector<punkt> tree(M*2+10,{0,0});
vector<macierz> lazy(M*2+10,{1,0,0,1});

macierz mnozenie_macierzy(macierz m1,macierz m2){
    macierz m3;
    m3.a=((m1.a*m2.a)+(m1.b*m2.c))%mod;
    m3.b=((m1.a*m2.b)+(m1.b*m2.d))%mod;
    m3.c=((m1.c*m2.a)+(m1.d*m2.c))%mod;
    m3.d=((m1.c*m2.b)+(m1.d*m2.d))%mod;
    return m3;
}
macierz potegowanie(macierz m2, long long int potega){
    macierz m3;
    if(potega==1){
        return m2;
    }
    if(potega%2==1){
        m3=potegowanie(m2,potega/2);
        m3=mnozenie_macierzy(m2,mnozenie_macierzy(m3,m3));
    }else{
        m3=potegowanie(m2,potega/2);
        m3=mnozenie_macierzy(m3,m3);
    }

    return m3;
}
punkt mnozenie_macierzy_punkt(macierz m1,punkt krolik){
    return {((m1.c*krolik.stare)%mod+(m1.d*krolik.mlode)%mod)%mod,((m1.a*krolik.stare)%mod+(m1.b*krolik.mlode)%mod)%mod};
}

void dodaj(long long int punkt1,macierz potega_macierzy){
    lazy[punkt1]=mnozenie_macierzy(lazy[punkt1],potega_macierzy);
    tree[punkt1]=mnozenie_macierzy_punkt(potega_macierzy,{tree[punkt1].mlode,tree[punkt1].stare});
}
void przekaz(long long int punkt){
    dodaj(2*punkt,lazy[punkt]);
    dodaj(2*punkt+1,lazy[punkt]);
    lazy[punkt]={1,0,0,1};
}


void update(long long int gdzie,long long int pocz,long long int kon,long long int x,long long int y,macierz potega_macierzy){
    if(x<=pocz && y>=kon){
        dodaj(gdzie,potega_macierzy);
        return;
    }

    przekaz(gdzie);
    long long int mid=(pocz+kon)/2;

    if(x<=mid){
        update(2*gdzie,pocz,mid,x,y,potega_macierzy);
    }
    if(y>mid){
        update(2*gdzie+1,mid+1,kon,x,y,potega_macierzy);
    }


    tree[gdzie].mlode=(tree[2*gdzie].mlode+tree[2*gdzie+1].mlode)%mod;
    tree[gdzie].stare=(tree[2*gdzie].stare+tree[2*gdzie+1].stare)%mod;
    return;
}

pair<long long int,long long int> query(long long int gdzie,long long int pocz,long long int kon,long long int x,long long int y){
    if(x<=pocz && y>=kon){
        return {tree[gdzie].mlode,tree[gdzie].stare};
    }

    przekaz(gdzie);
    long long int mid=(pocz+kon)/2;
    pair<long long int,long long int> wynik={0,0};
    pair<long long int,long long int> liczba={0,0};

    if(x<=mid){
        liczba=query(2*gdzie,pocz,mid,x,y);
        wynik.first=wynik.first+liczba.first;
        wynik.second=wynik.second+liczba.second;
    }
    if(y>mid){
        liczba=query(2*gdzie+1,mid+1,kon,x,y);
        wynik.first=wynik.first+liczba.first;
        wynik.second=wynik.second+liczba.second;
    }

    tree[gdzie].mlode=(tree[2*gdzie].mlode+tree[2*gdzie+1].mlode)%mod;
    tree[gdzie].stare=(tree[2*gdzie].stare+tree[2*gdzie+1].stare)%mod;
    return wynik;
}
void ustaw_stan_poczatkowy(long long int punkt,long long int poczatek,long long int koniec,long long int wartosc,long long int zakres){
    if(poczatek==koniec){
        if(punkt<M+zakres){
            tree[punkt].mlode=wartosc;
            tree[punkt].stare=wartosc-1;
        }
        return;
    }

    long long int mid=(poczatek+koniec)/2;
    ustaw_stan_poczatkowy(punkt*2,poczatek,mid,wartosc,zakres);
    ustaw_stan_poczatkowy(punkt*2+1,mid+1,koniec,wartosc,zakres);

    tree[punkt].mlode=(tree[2*punkt].mlode+tree[2*punkt+1].mlode)%mod;
    tree[punkt].stare=(tree[2*punkt].stare+tree[2*punkt+1].stare)%mod;
    return;
}


int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,q;
    cin>>n>>q;

    ustaw_stan_poczatkowy(1,1,M,1,n);

    while(q--){
        long long int t,a,b,c;
        cin>>t;

        if(t==1){
            cin>>a>>b>>c;
            update(1,1,M,a,b,potegowanie({1,1,1,0},c));
        }else{
            cin>>a>>b;
            pair<long long int,long long int> wynik=query(1,1,M,a,b);
            cout<<(wynik.first+wynik.second)%mod<<endl;
        }
    }

    return 0;
}
 