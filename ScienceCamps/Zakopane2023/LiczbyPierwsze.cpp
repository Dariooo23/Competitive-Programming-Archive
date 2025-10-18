//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<long long int > tab;
vector<long long int > pierwsze;
vector<long long int > pierwsze2;
vector<vector<long long int >> indeksy;

void sito(long long int  n){
    pierwsze.resize(1000009);

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

void rozklad(long long int  indeks,long long int  liczba)
{
    if(liczba==1){
        return;
    }
    while(liczba!=1){
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
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n;
    cin>>n;

    tab.resize(1000009);

    long long int  maksimum=0;
    for(long long int  i=1;i<=n;i++){
        cin>>tab[i];
        maksimum=max(maksimum,tab[i]);
    }

    sito(1000001);
    indeksy.resize(1000009);

    for(long long int  i=1;i<=n;i++){
        rozklad(i,tab[i]);
    }
    
    /*for(long long int  i=0;i<pierwsze2.size();i++){
        cout<<pierwsze2[i]<<" ";
    }*/
    /*for(long long int  i=0;i<pierwsze2.size();i++){
        cout<<pierwsze2[i]<<":"<<endl;
        for(long long int  j=0;j<indeksy[pierwsze2[i]].size();j++){
            cout<<indeksy[pierwsze2[i]][j]<<" ";
        }cout<<endl;
    }*/

    long long int  wynik=0;
    for(long long int  i=0;i<pierwsze2.size();i++){
        if(indeksy[pierwsze2[i]].size()==0)continue;

        wynik=wynik+(n*(n+1)/2);
        long long int  ostatnia=0,dlugosc;

        for(long long int  j=0;j<indeksy[pierwsze2[i]].size();j++){
            dlugosc=indeksy[pierwsze2[i]][j]-ostatnia-1;

            if(dlugosc<0)continue;

            ostatnia=indeksy[pierwsze2[i]][j];
            wynik=wynik-dlugosc*(dlugosc+1)/2;
            //cout<<pierwsze2[i]<<" "<<dlugosc<<endl;
        }
        if(indeksy[pierwsze2[i]].size()!=0){
            dlugosc=n-indeksy[pierwsze2[i]][indeksy[pierwsze2[i]].size()-1];

            if(dlugosc<0)continue;

            wynik=wynik-dlugosc*(dlugosc+1)/2;

            //cout<<pierwsze2[i]<<" "<<dlugosc<<endl;
        }
    }

    cout<<wynik;
    return 0;
}