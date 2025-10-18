//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct sztabka{
    long double waga,wartosc;
    int nr;
};

vector<sztabka> sztabki;
vector<long double> prefiksy;
//Bez eps psul mi sie chyba binsearch z set'a ale jak bedzie eps=0 powinno tez przejsc
long double eps=1e-5;

set<pair<long double,int>,greater <pair<long double,int>>> indeksy;

bool cmp(const sztabka &a,const sztabka &b){
    return (a.waga/a.wartosc)<=(b.waga/b.wartosc);
}

//Funkcja do obliczenia sum mas i wartosci przy aktualnym cieciu z binsearch'a
long double sumowanie(long double ciecie1,long double ciecie2){
    int indeks1=indeksy.lower_bound({ciecie1+eps,1e9})->second;
    int indeks2=indeksy.lower_bound({ciecie2+eps,1e9})->second;

    long double roznica=prefiksy[indeks2]-prefiksy[indeks1];

    long double roznica1=ciecie1-indeksy.lower_bound({ciecie1+eps,1e9})->first;
    long double roznica2=ciecie2-indeksy.lower_bound({ciecie2+eps,1e9})->first;

    long double mnoznik1=1.0-roznica1/sztabki[indeks1+1].wartosc;
    long double mnoznik2=roznica2/sztabki[indeks2+1].wartosc;

    roznica=roznica-(1.0-mnoznik1)*sztabki[indeks1+1].waga;
    roznica=roznica+mnoznik2*sztabki[indeks2+1].waga;
    return roznica;
}

void solve(){
    //Zawsze istnieje odpowiedz
    cout<<"TAK"<<'\n';
    int flaga=1;
    int n;
    cin>>n;

    long double sumawartosci=0;
    long double sumamasy=0;

    sztabki.clear();
    indeksy.clear();
    prefiksy.clear();
    sztabki.resize(n+1);
    prefiksy.resize(n+1);

    sztabki[0].waga=0;
    sztabki[0].wartosc=1;
    sztabki[0].nr=0;

    long long int licznik,mianownik;
    for(int i=1;i<=n;i++){
        cin>>sztabki[i].waga>>sztabki[i].wartosc;
        sztabki[i].nr=i;

        //Ifowanie niedzialajacego podzadania gdzie stosunki mas sa identyczne
        if(i==1){
            licznik=sztabki[i].waga;
            mianownik=sztabki[i].wartosc;
        }else{
            if(sztabki[i].waga*mianownik!=sztabki[i].wartosc*licznik){
                flaga=0;
            }
        }

        sumamasy=sumamasy+sztabki[i].waga;
        sumawartosci=sumawartosci+sztabki[i].wartosc;
    }

    //Sortowanie sztabek po stosunku masy do wartosci
    stable_sort(sztabki.begin(),sztabki.end(),cmp);

    prefiksy[0]=0;
    long double suma=0;
    indeksy.insert({suma,0});
    for(int i=1;i<=n;i++){
        prefiksy[i]=prefiksy[i-1]+sztabki[i].waga;
        suma=suma+sztabki[i].wartosc;
        indeksy.insert({suma,i});
    }

    int cntr=60;
    long double l=0.0,r=sumawartosci/2.0,mid;
    while(flaga==0 && cntr--){
        mid=(l+r)/2.0;
        long double zsumowane=sumowanie(mid,mid+sumawartosci/2.0);
        if(zsumowane<(sumamasy/2.0)){
            l=mid;
        }else{
            r=mid;
        }
    }

    //Obliczanie dwoch punktow ktore zostaly znalezione binsearch'em
    vector<char> wyniki(n+1);
    int indeks1=indeksy.lower_bound({l+eps,1e9})->second;
    int indeks2=indeksy.lower_bound({l+sumawartosci/2.0+eps,1e9})->second;

    long double roznica1=l-indeksy.lower_bound({l+eps,1e9})->first;
    long double roznica2=l+sumawartosci/2.0-indeksy.lower_bound({l+sumawartosci/2.0+eps,1e9})->first;
    long double mnoznik1=1-roznica1/sztabki[indeks1+1].wartosc;
    long double mnoznik2=roznica2/sztabki[indeks2+1].wartosc;

    //Przez long double czasami dokladnosc sie psuje i sa bardzo niewielkie odchyly od 0 i 1
    if(mnoznik1<0)mnoznik1=0;
    if(mnoznik2<0)mnoznik2=0;
    if(mnoznik1>1)mnoznik1=1;
    if(mnoznik2>1)mnoznik2=1;

    for(int i=1;i<=indeks1;i++){
        wyniki[sztabki[i].nr]='B';
    }
    for(int i=indeks1+1;i<=indeks2;i++){
        wyniki[sztabki[i].nr]='A';
    }
    for(int i=indeks2+1;i<=n;i++){
        wyniki[sztabki[i].nr]='B';
    }

    wyniki[sztabki[indeks1+1].nr]='1';
    wyniki[sztabki[indeks2+1].nr]='2';

    for(int i=1;i<=n;i++){
        if(wyniki[i]=='1'){
            cout<<'C'<<" ";
            cout<<fixed<<setprecision(11)<<mnoznik1<<endl;
        }else{
            if(wyniki[i]=='2'){
                cout<<'C'<<" ";
                cout<<fixed<<setprecision(11)<<mnoznik2<<endl;
            }else{
                cout<<wyniki[i]<<endl;
            }
        }
    }
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int q;
    cin>>q;
    while(q--){
        solve();
    }

    return 0;
}