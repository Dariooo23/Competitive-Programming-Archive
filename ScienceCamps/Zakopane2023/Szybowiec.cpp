//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> pref_sum;
vector<pair<int,int>> przedzialy;
set<pair<int,int>, greater<pair<int,int>>> strzal;

int powietrze(int wysokosc,int poczatek,int koniec,int indeks){
    int suma=wysokosc;
    auto punkt=strzal.lower_bound({koniec,213769420});

    suma=wysokosc+pref_sum[punkt->second]-pref_sum[indeks-1]-koniec+poczatek;
    if(koniec>=przedzialy[punkt->second].first && koniec<przedzialy[punkt->second].second){
        suma=suma-(przedzialy[punkt->second].second-koniec);
    }

    return suma;
}

int beansearch(int wysokosc,int poczatek,int indeks){
    long long int l=poczatek,r=2000000009,mid;
    while(l<r){
        mid=(l+r+1)/2;
        if(powietrze(wysokosc,poczatek,mid,indeks)>=0){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    return l-poczatek;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,h;
    cin>>n>>h;

    long long int suma=0;
    pref_sum.push_back(0);
    przedzialy.push_back({0,0});

    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        przedzialy.push_back({a,b});

        suma=suma+(b-a);
        strzal.insert({a,i});
        pref_sum.push_back(suma);
    }

    int wynik=0;
    for(int i=0;i<n;i++){
        int liczba=beansearch(h,przedzialy[i].first,i);
        wynik=max(wynik,liczba);
    }

    cout<<wynik;
    return 0;
}