//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

vector<vector<int>> dlugosci;

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int dlugosc;
    cin>>dlugosc;

    string slowo1,slowo2;
    cin>>slowo1>>slowo2;

    dlugosci.resize(dlugosc,vector<int>(dlugosc+1));

    for(int i=0;i<dlugosc;i++){
        dlugosci[i][0]=0;
        dlugosci[i][1]=0;
    }
    for(int dl=2;dl<=dlugosc;dl++){
        for(int pocz=0;pocz<dlugosc-dl+1;pocz++){
            int dodajnik=0;
            int lewo,prawo;

            lewo=pocz;
            prawo=pocz+dl-1;

            if(slowo1[lewo]==slowo2[lewo])dodajnik--;
            if(slowo1[prawo]==slowo2[prawo])dodajnik--;
            if(slowo1[lewo]==slowo2[prawo])dodajnik++;
            if(slowo1[prawo]==slowo2[lewo])dodajnik++;

            dlugosci[pocz][dl]=dlugosci[pocz+1][dl-2]+dodajnik;
        }
    }

    int wynikg=0;
    for(int dl=2;dl<=dlugosc;dl++){
        for(int pocz=0;pocz<dlugosc-dl+1;pocz++){
            wynikg=max(wynikg,dlugosci[pocz][dl]);
        }
    }

    int wynikp=0;
    for(int i=0;i<dlugosc;i++){
        if(slowo1[i]==slowo2[i]){
            wynikp++;
        }
    }

    cout<<wynikg+wynikp;
    return 0;
}