//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

int roznica=0;
vector<vector<int>> pozycje;

void solve(int litera1,int litera2){
    vector<int> ciag;
    int indeks1=0,indeks2=0;

    while(pozycje[litera1][indeks1]!=pozycje[litera2][indeks2]){
        if(pozycje[litera1][indeks1]<pozycje[litera2][indeks2]){
            ciag.push_back(1);
            indeks1++;
        }else{
            ciag.push_back(-1);
            indeks2++;
        }
    }

    int minimum=1e9,suma=0,suma2=0;
    for(int i=0;i<ciag.size();i++){
        suma=suma+ciag[i];
        if(ciag[i]==-1){
            minimum=min(minimum,suma2);
            suma2=suma;
        }
        roznica=max(roznica,suma-minimum);
    }

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;
    string slowo;
    cin>>slowo;

    pozycje.resize(26);

    for(int i=0;i<n;i++){
        pozycje[slowo[i]-'a'].push_back(i);
    }
    for(int i=0;i<26;i++){
        pozycje[i].push_back(1000000);
    }

    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(i==j)continue;
            solve(i,j);
        }
    }

    cout<<roznica;
    return 0;
}