//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

vector<long long int> drwa;
map<long long int,long long int> licznik_drew;
void polacz_drwa(int rozmiar){
    licznik_drew[rozmiar]=1;
    licznik_drew[rozmiar*2]++;
    if(licznik_drew[rozmiar*2]==3)polacz_drwa(rozmiar*2);

    return;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,suma=0;
    cin>>n;

    for(int i=0;i<n;i++){
        long long int a;
        cin>>a;
        suma+=a;
        drwa.push_back(a);
    }

    sort(drwa.begin(),drwa.end());

    long long int najwieksza=drwa[drwa.size()-1];
    suma-=najwieksza;

    for(int i=0;i<n-1;i++){
        licznik_drew[drwa[i]]++;
        if(licznik_drew[drwa[i]]==3){
            polacz_drwa(drwa[i]);
        }
    }

    vector<long long int> nowe_drwa;
    for(auto it=licznik_drew.begin();it!=licznik_drew.end();++it){
        if(it->second==2){
            nowe_drwa.push_back(it->first);
            nowe_drwa.push_back(it->first);
        }else{
            nowe_drwa.push_back(it->first);
        }
    }

    bitset<5000009> plecak;
    plecak[0]=1;
    for(int i=0;i<nowe_drwa.size();i++){
        long long int przesuniecie=nowe_drwa[i];
        plecak=(plecak|(plecak<<przesuniecie));
    }

    for(int i=suma/2;i>=0;i--){
        if(plecak[i]==1){
            cout<<i+najwieksza;
            return 0;
        }
    }
    return 0;
}