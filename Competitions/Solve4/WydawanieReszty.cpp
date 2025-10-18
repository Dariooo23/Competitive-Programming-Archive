//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<long long int> nominaly1;
vector<long long int> nominaly2;
map<long long int,int> kwoty1;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    long long int k;
    cin>>n>>k;


    for(int i=0;i<n/2;i++){
        long long int a;
        cin>>a;
        nominaly1.push_back(a);
    }
    for(int i=0;i<(n-1)/2+1;i++){
        long long int a;
        cin>>a;
        nominaly2.push_back(a);
    }
    for(int i=0;i<(1<<nominaly1.size());i++){
        long long int kwota=0;
        int licznik=0;
        for(int j=nominaly1.size()-1;j>=0;j--){
            if(((i&(1<<j))>>j)){
                kwota=kwota+nominaly1[j];
                licznik++;
            }
        }
        if(kwoty1.find(kwota)==kwoty1.end()){
            kwoty1[kwota]=licznik;
        }else{
            kwoty1[kwota]=min(kwoty1[kwota],licznik);
        }
    }


    int wynik=1e9+9;
    for(int i=0;i<(1<<nominaly2.size());i++){
        long long int kwota=0;
        int licznik=0;
        for(int j=nominaly2.size()-1;j>=0;j--){
            if(((i&(1<<j))>>j)){
                kwota=kwota+nominaly2[j];
                licznik++;
            }
        }
        if(kwoty1.find(k-kwota)!=kwoty1.end()){
            wynik=min(wynik,kwoty1[k-kwota]+licznik);
        }
    }


    if(wynik==1e9+9){
        cout<<"NIE";
    }else{
        cout<<wynik;
    }
    return 0;
}