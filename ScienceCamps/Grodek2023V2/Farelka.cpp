//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<long long int> wyniki;
vector<long long int> wejscie;
vector<long long int> pierwsze;
vector<long long int> pierwsze2;
vector<vector<long long int>> indeksy;

void sito(long long int n){
    pierwsze.resize(1000100);

    pierwsze[1]=0;
    for(long long int i=2;i<=n;i++){
        pierwsze[i]=i;
    }

    for(long long int i=4;i<=n;i=i+2){
        pierwsze[i]=2;
    }

    if(n>=2)pierwsze2.push_back(2); 
    for(long long int i=3;i<=n;i++){
        if(pierwsze[i]){
            if(pierwsze[i]==i)pierwsze2.push_back(i);
            for (long long int j=i*i;j<=n;j=j+i){
                if (pierwsze[j]==j){
                    pierwsze[j]=i;
                }
            }
        }
    }

    return;
}

void rozklad(long long int indeks,long long int liczba){
    if(liczba==1){
        return;
    }
    while(liczba>1){
        if(indeksy[pierwsze[liczba]].size()==0){
            indeksy[pierwsze[liczba]].push_back(indeks);
        }else{
            if(indeksy[pierwsze[liczba]][indeksy[pierwsze[liczba]].size()-1]!=indeks){
                indeksy[pierwsze[liczba]].push_back(indeks);
            }
        }
        liczba=liczba/pierwsze[liczba];
    }
    return;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,maks=0;
    cin>>n;

    sito(1000009);
    wyniki.resize(n+1);
    wejscie.resize(n+1);
    indeksy.resize(1000000+9);

    for(int i=1;i<=n;i++){
        cin>>wejscie[i];
        maks=max(wejscie[i],maks);
        rozklad(i,wejscie[i]);
    }

    for(int i=0;i<pierwsze2.size();i++){
        if(indeksy[pierwsze2[i]].size()==0)continue;
        long long int suma=0,poczatek=0;

        for(int j=0;j<indeksy[pierwsze2[i]].size();j++){
            suma=suma+wejscie[indeksy[pierwsze2[i]][j]];
            if(j==indeksy[pierwsze2[i]].size()-1 || indeksy[pierwsze2[i]][j]+1!=indeksy[pierwsze2[i]][j+1]){
                for(int k=poczatek;k<=j;k++){
                    wyniki[indeksy[pierwsze2[i]][k]]=max(wyniki[indeksy[pierwsze2[i]][k]],suma);
                }
                poczatek=j+1;
                suma=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<wyniki[i]<<" ";
    }

    return 0;
}