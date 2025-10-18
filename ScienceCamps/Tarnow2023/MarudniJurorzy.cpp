//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int pierwiastek;

struct pytanie{
    int first,second,nr;
};

set<int> czy_jest;
vector<pytanie> zapytania;
vector<long long int> liczby;
vector<long long int> odpowiedzi;
vector<long long int> ilosc_liczb;

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
            ilosc_liczb[liczby[akt_l]]--;
            if(ilosc_liczb[liczby[akt_l]]==0){
                czy_jest.insert(liczby[akt_l]);
            }
            akt_l++;
        }
        while(l<akt_l){
            ilosc_liczb[liczby[akt_l-1]]++;
            if(ilosc_liczb[liczby[akt_l-1]]==1){
                czy_jest.erase(liczby[akt_l-1]);
            }
            akt_l--;
        }
        while(akt_r<=r){
            ilosc_liczb[liczby[akt_r]]++;
            if(ilosc_liczb[liczby[akt_r]]==1){
                czy_jest.erase(liczby[akt_r]);
            }
            akt_r++;
        }
        while(r+1<akt_r){
            ilosc_liczb[liczby[akt_r-1]]--;
            if(ilosc_liczb[liczby[akt_r-1]]==0){
                czy_jest.insert(liczby[akt_r-1]);
            }
            akt_r--;
        }

        odpowiedzi[zapytania[i].nr]=*czy_jest.begin();
    }

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int n,m,maks=0;
    cin>>n;

    pierwiastek=sqrt(n);
    liczby.resize(n+1,0);
    ilosc_liczb.resize(1e6+9,0);

    for(int i=1;i<=n;i++){
        cin>>liczby[i];
        maks=max(maks,liczby[i]);
    }
    for(int i=0;i<=maks+10;i++){
        czy_jest.insert(i);
    }

    cin>>m;
    odpowiedzi.resize(m+1,0);
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
 