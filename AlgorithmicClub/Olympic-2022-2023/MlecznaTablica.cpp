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

        while(akt_l<l){
            akt_suma=(long long int)(akt_suma-mlecznosc[akt_l]*(ilosc_liczb[mlecznosc[akt_l]]*ilosc_liczb[mlecznosc[akt_l]]));
            ilosc_liczb[mlecznosc[akt_l]]--;
            akt_suma=(long long int)(akt_suma+mlecznosc[akt_l]*(ilosc_liczb[mlecznosc[akt_l]]*ilosc_liczb[mlecznosc[akt_l]]));
            akt_l++;
        }
        while(l<akt_l){
            akt_suma=(long long int)(akt_suma-mlecznosc[akt_l-1]*(ilosc_liczb[mlecznosc[akt_l-1]]*ilosc_liczb[mlecznosc[akt_l-1]]));
            ilosc_liczb[mlecznosc[akt_l-1]]++;
            akt_suma=(long long int)(akt_suma+mlecznosc[akt_l-1]*(ilosc_liczb[mlecznosc[akt_l-1]]*ilosc_liczb[mlecznosc[akt_l-1]]));
            akt_l--;
        }

        while(akt_r<=r){
            akt_suma=(long long int)(akt_suma-mlecznosc[akt_r]*(ilosc_liczb[mlecznosc[akt_r]]*ilosc_liczb[mlecznosc[akt_r]]));
            ilosc_liczb[mlecznosc[akt_r]]++;
            akt_suma=(long long int)(akt_suma+mlecznosc[akt_r]*(ilosc_liczb[mlecznosc[akt_r]]*ilosc_liczb[mlecznosc[akt_r]]));
            akt_r++;
        }
        while(r+1<akt_r){
            akt_suma=(long long int)(akt_suma-mlecznosc[akt_r-1]*(ilosc_liczb[mlecznosc[akt_r-1]]*ilosc_liczb[mlecznosc[akt_r-1]]));
            ilosc_liczb[mlecznosc[akt_r-1]]--;
            akt_suma=(long long int)(akt_suma+mlecznosc[akt_r-1]*(ilosc_liczb[mlecznosc[akt_r-1]]*ilosc_liczb[mlecznosc[akt_r-1]]));
            akt_r--;
        }

        odpowiedzi[zapytania[i].nr]=akt_suma;
    }

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,m;
    cin>>n>>m;

    pierwiastek=sqrt(n);
    mlecznosc.resize(n+1,0);
    ilosc_liczb.resize(1e6+9,0);
    odpowiedzi.resize(m+1,0);

    for(int i=1;i<=n;i++){
        cin>>mlecznosc[i];
    }

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        zapytania.push_back({a,b,i});
    }
    
    sort(zapytania.begin(),zapytania.end(),comp);
    algorytm_mo();

    for(int i=1;i<=m;i++){
        cout<<odpowiedzi[i]<<endl;
    }
    return 0;
}
 