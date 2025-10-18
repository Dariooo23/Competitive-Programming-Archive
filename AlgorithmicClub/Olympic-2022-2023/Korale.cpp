//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const long long int mod1=1e9+696969;
const long long int potega1=1e9+7;
const long long int potega2=1e9+9;

vector<long long int> potegi1;
vector<long long int> potegi2;
vector<long long int> wejscie;
vector<long long int> podzial_k;
map<pair<long long int,long long int>,int> hashe;
vector<pair<long long int,long long int>> sufiks_hashy;
vector<pair<long long int,long long int>> prefiks_hashy;

void oblicz_potegi(int n){
    potegi1.resize(n);
    potegi2.resize(n);

    potegi1[0]=1;
    potegi2[0]=1;

    for(int i=1;i<n;i++){
        potegi1[i]=(potegi1[i-1]*potega1)%mod1;
        potegi2[i]=(potegi2[i-1]*potega2)%mod1;
    }

    return;
}
void policz_hashe(int n){
    sufiks_hashy.resize(n+10);
    prefiks_hashy.resize(n+10);

    sufiks_hashy[n+1]={0,0};
    prefiks_hashy[0]={0,0};

    for(int i=1;i<=n;i++){
        prefiks_hashy[i].first=(prefiks_hashy[i-1].first+(wejscie[i]*potegi1[i])%mod1)%mod1;
        prefiks_hashy[i].second=(prefiks_hashy[i-1].second+(wejscie[i]*potegi2[i])%mod1)%mod1;

        sufiks_hashy[(n-i+1)].first=(sufiks_hashy[(n-i+2)].first+(wejscie[(n-i+1)]*potegi1[i])%mod1)%mod1;
        sufiks_hashy[(n-i+1)].second=(sufiks_hashy[(n-i+2)].second+(wejscie[(n-i+1)]*potegi2[i])%mod1)%mod1;
    }

    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,k;
    cin>>n;

    oblicz_potegi(n+10);
    wejscie.resize(n+10);
    podzial_k.resize(n+10);

    for(int i=1;i<=n;i++){
        cin>>wejscie[i];
    }policz_hashe(n);

    long long int maks=0;
    long long int ilosc=0;
    for(int k=1;k<=n;k++){
        long long int wynik=0;
        for(int i=k;i<=n;i=i+k){
            pair<long long int,long long int> suf_hash;
            pair<long long int,long long int> pref_hash;

            pref_hash.first=(((prefiks_hashy[i].first-prefiks_hashy[i-k].first+mod1)%mod1)*potegi1[n-(i-k+1)])%mod1;
            pref_hash.second=(((prefiks_hashy[i].second-prefiks_hashy[i-k].second+mod1)%mod1)*potegi2[n-(i-k+1)])%mod1;
            suf_hash.first=(((sufiks_hashy[i-k+1].first-sufiks_hashy[i+1].first+mod1)%mod1)*potegi1[i-1])%mod1;
            suf_hash.second=(((sufiks_hashy[i-k+1].second-sufiks_hashy[i+1].second+mod1)%mod1)*potegi2[i-1])%mod1;

            if(hashe.find(pref_hash)==hashe.end() && hashe.find(suf_hash)==hashe.end()){
                hashe[pref_hash]=1;
                hashe[suf_hash]=1;
                wynik++;
            }
        }
        podzial_k[k]=wynik;
        if(wynik>maks){
            maks=wynik;
            ilosc=1;
        }else{
            if(wynik==maks){
                ilosc++;
            }
        }

        hashe.clear();
    }

    cout<<maks<<" "<<ilosc<<endl;
    for(int i=1;i<=n;i++){
        if(podzial_k[i]==maks){
            cout<<i<<" ";
        }
    }
    return 0;
}
 