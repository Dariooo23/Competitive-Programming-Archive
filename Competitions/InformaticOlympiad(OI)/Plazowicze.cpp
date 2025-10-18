//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

long long int mnoznik=(1<<30);
struct przedzial{
    long long int dlugosc;
    long long int poczatek;
    long long int ilosc;
};
bool cmp(const przedzial &a,const przedzial &b){
    if(a.dlugosc==b.dlugosc){
        return a.poczatek<b.poczatek;
    }else{
        return a.dlugosc>b.dlugosc;
    }
}

vector<przedzial> przedzialy;
vector<long long int> wejscie;
vector<long long int> odpowiedzi;
vector<pair<long long int,long long int>> zapytania;

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,x,z;
    cin>>n>>x>>z;

    wejscie.resize(n);
    zapytania.resize(z);
    odpowiedzi.resize(z);

    for(int i=0;i<n;i++){
        cin>>wejscie[i];
        wejscie[i]*=mnoznik;
    }
    for(int i=0;i<z;i++){
        cin>>zapytania[i].first;
        zapytania[i].second=i;
    }

    for(int i=0;i<n-1;i++){
        przedzialy.push_back({wejscie[i+1]-wejscie[i],wejscie[i],1});
    }
    sort(przedzialy.begin(),przedzialy.end(),cmp);
    sort(zapytania.begin(),zapytania.end());

    long long int ilosc_miejsc=0;
    long long int indeks_zapytan=0;
    queue<przedzial> kolejka1,kolejka2;
    for(int i=0;i<n-1;i++){
        kolejka1.push(przedzialy[i]);
    }

    while(indeks_zapytan<zapytania.size()){
        przedzial przedzialg;
        if(kolejka1.empty() && !kolejka2.empty()){
            przedzialg=kolejka2.front();
            kolejka2.pop();
        }
        if(kolejka2.empty() && !kolejka1.empty()){
            przedzialg=kolejka1.front();
            kolejka1.pop();
        }
        if(!kolejka1.empty() && !kolejka2.empty()){
            if(kolejka1.front().dlugosc==kolejka2.front().dlugosc){
                if(kolejka1.front().poczatek<kolejka2.front().poczatek){
                    przedzialg=kolejka1.front();
                    kolejka1.pop();
                }else{
                    przedzialg=kolejka2.front();
                    kolejka2.pop();
                }
            }else{
                if(kolejka1.front().dlugosc>kolejka2.front().dlugosc){
                    przedzialg=kolejka1.front();
                    kolejka1.pop();
                }else{
                    przedzialg=kolejka2.front();
                    kolejka2.pop();
                }
            }
        }

        while(indeks_zapytan<zapytania.size() && zapytania[indeks_zapytan].first<=ilosc_miejsc+przedzialg.ilosc){
            long long int brakuje=zapytania[indeks_zapytan].first-ilosc_miejsc;
            long long int pozycja=przedzialg.poczatek+(przedzialg.dlugosc/2)+przedzialg.dlugosc*(brakuje-1);
            odpowiedzi[zapytania[indeks_zapytan].second]=pozycja;
            indeks_zapytan++;
        }
        ilosc_miejsc+=przedzialg.ilosc;
        kolejka2.push({przedzialg.dlugosc/2,przedzialg.poczatek,przedzialg.ilosc*2});
    }

    for(int i=0;i<z;i++){
        long long int licznik,mianownik,nwd;
        licznik=odpowiedzi[i];
        mianownik=mnoznik;
        nwd=gcd(licznik,mianownik);
        cout<<licznik/nwd<<"/"<<mianownik/nwd<<endl;
    }
    return 0;
}