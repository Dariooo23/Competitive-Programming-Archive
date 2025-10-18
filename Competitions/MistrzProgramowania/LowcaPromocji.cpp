//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

struct przecena{
    long long int produkt,typ,cena,dzien;
};

vector<long long int> podstawowe_ceny;
vector<przecena> przeceny;

bool cmp(const przecena &a, const przecena &b){
    if(a.dzien==b.dzien){
        return a.typ>b.typ;
    }else{
        return a.dzien<b.dzien;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,m,kosztg=0,dzien=1,kosztp=0;
    cin>>n>>m;

    podstawowe_ceny.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>podstawowe_ceny[i];
        kosztg=kosztg+podstawowe_ceny[i];
        kosztp=kosztp+podstawowe_ceny[i];
    }
    for(int i=1;i<=m;i++){
        long long int produkt,poczatek,koniec,cena;
        cin>>produkt>>poczatek>>koniec>>cena;
        
        przeceny.push_back({produkt,1,cena,poczatek});
        przeceny.push_back({produkt,-1,cena,koniec});
    }

    sort(przeceny.begin(),przeceny.end(),cmp);

    for(int i=0;i<przeceny.size();i++){
        if(przeceny[i].typ==1){
            kosztp=kosztp-podstawowe_ceny[przeceny[i].produkt];
            kosztp=kosztp+przeceny[i].cena;
        }else{
            kosztp=kosztp+podstawowe_ceny[przeceny[i].produkt];
            kosztp=kosztp-przeceny[i].cena;
        }
        if(kosztp<kosztg){
            kosztg=kosztp;
            dzien=przeceny[i].dzien;
        }
    }

    cout<<kosztg<<" "<<dzien;
    return 0;
}