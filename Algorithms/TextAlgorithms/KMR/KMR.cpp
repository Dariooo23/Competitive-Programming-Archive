//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> lcp;
vector<int> rang;
vector<int> sufiksy;
vector<vector<int>> kmr;

void fkmr(string slowo,int n){
    vector<pair<int, pair<int,int>>> pomoc(n);
    kmr.resize(n+1,vector<int> (21));
    sufiksy.resize(n+1);
    rang.resize(n+1);
    lcp.resize(n+1);

    int potega=1;

    for(int i=0;i<n;i++){
        kmr[i][0]=slowo[i]-'a'+1;
    }

    
    for(int i=1;i<=20;i++){
        for(int j=0;j<n;j++){
            if(j+potega>=n){
                pomoc[j]={kmr[j][i-1],{-1,j}};
            }
            else{
                pomoc[j]={kmr[j][i-1],{kmr[j+potega][i-1],j}};
            }
        }

        sort(pomoc.begin(),pomoc.end());
        pair<int,int> pomoc2={-1,-1};
        int ile=-1;

        for(int j=0;j<n;j++){
            if(pomoc2.first!=pomoc[j].first || pomoc2.second!=pomoc[j].second.first){
                pomoc2={pomoc[j].first,pomoc[j].second.first};
                ile++;
            }
            kmr[pomoc[j].second.second][i]=ile;
        }
        potega=potega*2;
    }

    for(int i=0;i<n;i++){
        sufiksy[kmr[i][20]]=i;
    }
    for(int i=0;i<n;i++){
        rang[sufiksy[i]]=i;
    }

    int indeks=0;
    for(int i=0;i<n;i++){
        if(rang[i]==n-1){
            indeks=0;
            continue;
        }
        int pozycja1=i;
        int pozycja2=sufiksy[rang[i]+1];
        while(pozycja1+indeks<n && pozycja2+indeks<n && slowo[pozycja1+indeks]==slowo[pozycja2+indeks]){
            indeks++;
        }
        lcp[rang[i]]=indeks;
        if(indeks)indeks--;
    }
    for(int i=0;i<n;i++){
        cout<<lcp[i]<<" ";
    }
    return;
}


int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //Funkcja KMR obliczajaca slownik podslow bazowych, tablice sufiskowa oraz najdluzszy spojny prefiks sufiksow w kolejnosci leksykograficznej
    string slowo;
    cin>>slowo;

    fkmr(slowo,slowo.size());

    return 0;
}
 