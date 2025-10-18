//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int pierwiastek;

struct pytanie{
    int first,second,nr;
};

vector<long long int> mlecznosc;
vector<long long int> ilosc_liczb;
vector<pytanie> zapytania;
vector<long long int> odpowiedzi;

//Zapytania są sortowane najpierw po przedziałach względem l, których rozmiar wynosi pierwiastek(n), jeżeli zapytania znajdują się w tym samym przedziale
//To sortujemy je rosnąco po r.
bool comp(const pytanie &a, const pytanie &b){
    if((a.first/pierwiastek)!=(b.first/pierwiastek)){
        return (a.first/pierwiastek)<(b.first/pierwiastek);
    }else{
        return a.second<b.second;
    }
}

void algorytm_mo(){
    long long int akt_l=1,akt_r=1,akt_suma=0;

    for(int i=0;i<zapytania.size();i++){
        int l=zapytania[i].first,r=zapytania[i].second;

        //Usuń nadmierne indeksy po lewej
        while(akt_l<l){
            akt_suma=(long long int)(akt_suma-mlecznosc[akt_l]*(ilosc_liczb[mlecznosc[akt_l]]*ilosc_liczb[mlecznosc[akt_l]]));
            ilosc_liczb[mlecznosc[akt_l]]--;
            akt_suma=(long long int)(akt_suma+mlecznosc[akt_l]*(ilosc_liczb[mlecznosc[akt_l]]*ilosc_liczb[mlecznosc[akt_l]]));
            akt_l++;
        }
        //Dodaj brakujące indeksy z lewej
        while(l<akt_l){
            akt_suma=(long long int)(akt_suma-mlecznosc[akt_l-1]*(ilosc_liczb[mlecznosc[akt_l-1]]*ilosc_liczb[mlecznosc[akt_l-1]]));
            ilosc_liczb[mlecznosc[akt_l-1]]++;
            akt_suma=(long long int)(akt_suma+mlecznosc[akt_l-1]*(ilosc_liczb[mlecznosc[akt_l-1]]*ilosc_liczb[mlecznosc[akt_l-1]]));
            akt_l--;
        }

        //Dodaj brakujące indeksy z prawej
        while(akt_r<=r){
            akt_suma=(long long int)(akt_suma-mlecznosc[akt_r]*(ilosc_liczb[mlecznosc[akt_r]]*ilosc_liczb[mlecznosc[akt_r]]));
            ilosc_liczb[mlecznosc[akt_r]]++;
            akt_suma=(long long int)(akt_suma+mlecznosc[akt_r]*(ilosc_liczb[mlecznosc[akt_r]]*ilosc_liczb[mlecznosc[akt_r]]));
            akt_r++;
        }
        //Usun nadmierne indeksy po prawej
        while(r+1<akt_r){
            akt_suma=(long long int)(akt_suma-mlecznosc[akt_r-1]*(ilosc_liczb[mlecznosc[akt_r-1]]*ilosc_liczb[mlecznosc[akt_r-1]]));
            ilosc_liczb[mlecznosc[akt_r-1]]--;
            akt_suma=(long long int)(akt_suma+mlecznosc[akt_r-1]*(ilosc_liczb[mlecznosc[akt_r-1]]*ilosc_liczb[mlecznosc[akt_r-1]]));
            akt_r--;
        }

        //Zapisz odpowiedz
        odpowiedzi[zapytania[i].nr]=akt_suma;
    }

    return;
}

int main()
{
    //Kod wziety z zadania Mleczna Tablica
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    //Algorytm ten jest w stanie w czasie O(n*sqrt(n)) odpowiedzieć na wszystkie zapytania o ilość różnych wartości na przedziale, dzięki odpowiedniemu
    //Sortowaniu danych wejściowych, przez co wynik następnego zapytania jest obliczany częściowo na podstawie poprzedniego.
    int n,m;
    cin>>n>>m;

    pierwiastek=sqrt(n);
    mlecznosc.resize(n+1,0);
    ilosc_liczb.resize(1e6+9,0);
    odpowiedzi.resize(m+1,0);

    //Wczytujemy wartosci na indeksach
    for(int i=1;i<=n;i++){
        cin>>mlecznosc[i];
    }

    //Wczytujemy zapytania na przedziale
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        zapytania.push_back({a,b,i});
    }

    //Sortujemy zapytania
    sort(zapytania.begin(),zapytania.end(),comp);
    algorytm_mo();

    //Wypisz wszystkie odpowiedzi
    for(int i=1;i<=m;i++){
        cout<<odpowiedzi[i]<<endl;
    }
    return 0;
}
 