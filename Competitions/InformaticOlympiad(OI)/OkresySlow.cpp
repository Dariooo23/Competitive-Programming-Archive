//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int,int> PII;

string tekst;
LL rozmiar,wynik=0;
vector<int> prefsuf;
vector<int> minprefsuf;

void kmp(){
    prefsuf[0]=0;

    for(int i=1;i<rozmiar;i++){
        int prefiks=prefsuf[i-1];

        while(prefiks>0 && tekst[prefiks]!=tekst[i]){
            prefiks=prefsuf[prefiks-1];
        }

        if(tekst[prefiks]==tekst[i])prefiks++;
        prefsuf[i]=prefiks;
    }

    return;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>rozmiar>>tekst;
    minprefsuf.resize(rozmiar+10);
    prefsuf.resize(rozmiar+10);

    kmp();

    for(int i=0;i<rozmiar;i++){
        minprefsuf[i]=0;
    }

    for(int i=0;i<rozmiar;i++){
        if(prefsuf[i]>0){
            if(prefsuf[prefsuf[i]-1]==0){
                minprefsuf[i]=prefsuf[i];
            }else{
                minprefsuf[i]=minprefsuf[prefsuf[i]-1];
            }

            wynik=wynik+i+1-minprefsuf[i];
        }
    }

    cout<<wynik;
    return 0;
}