//Karol Dziekan
#include <bits/stdc++.h>
#include "krelib.hpp"

using namespace std;

#define endl '\n'
#define LL long long int

vector<pair<int,int>> polaczenia;
void robimy_drzewo_wariacie(int rodzic,vector<int> wierzcholki,int n,int poziom){
    if(wierzcholki.size()==0)return;
    if(rodzic!=0 && wierzcholki.size()==1)polaczenia.push_back({rodzic,wierzcholki[0]});
    if(wierzcholki.size()==1)return;
    
    int lisc1,lisc2;
    vector<int> ja_pytalem;
    while((int)ja_pytalem.size()!=(poziom*2-1)){
        ja_pytalem.clear();

        lisc1=rand()%wierzcholki.size();
        lisc2=rand()%wierzcholki.size();
        if(lisc1==lisc2)continue;
        lisc1=wierzcholki[lisc1];
        lisc2=wierzcholki[lisc2];
        
        for(int i=0;i<wierzcholki.size();i++){
            if(wierzcholki[i]==lisc1 || wierzcholki[i]==lisc2)continue;

            bool zmienna=query(lisc1,wierzcholki[i],lisc2);

            if(zmienna)ja_pytalem.push_back(wierzcholki[i]);
        }
    }

    vector<int> sciezka((int)ja_pytalem.size());

    for(int i=0;i<ja_pytalem.size();i++){
        int odleglosc=0;
        for(int j=0;j<ja_pytalem.size();j++){
            if(i==j)continue;
            if(query(lisc1,ja_pytalem[j],ja_pytalem[i]))odleglosc++;
        }
        sciezka[odleglosc]=ja_pytalem[i];
    }

    vector<int> uzyte(n+1,0);
    int wierzcholek=sciezka[sciezka.size()/2];
    if(rodzic!=0)polaczenia.push_back({rodzic,wierzcholek});

    uzyte[lisc1]=1;
    uzyte[lisc2]=1;
    for(int i=0;i<sciezka.size();i++){
        uzyte[sciezka[i]]=1;
    }

    polaczenia.push_back({lisc1,sciezka[0]});
    polaczenia.push_back({sciezka[sciezka.size()-1],lisc2});

    for(int i=0;i<sciezka.size()-1;i++){
        if(sciezka[i]!=sciezka[i+1]);
        polaczenia.push_back({sciezka[i],sciezka[i+1]});
    }

    //Brut
    int licznik=0;
    vector<int> poddrzewo;

    //Lewo
    for(int i=0;i<sciezka.size()/2;i++){

        for(int j=0;j<wierzcholki.size();j++){
            if(uzyte[wierzcholki[j]])continue;

            if(query(wierzcholek,sciezka[i],wierzcholki[j])){
                poddrzewo.push_back(wierzcholki[j]);
                uzyte[wierzcholki[j]]=1;
            }
        }

        robimy_drzewo_wariacie(sciezka[i],poddrzewo,n,licznik);
        poddrzewo.clear();
        licznik++;
    }

    //Prawo
    licznik=0;
    for(int i=sciezka.size()-1;i>sciezka.size()/2;i--){

        for(int j=0;j<wierzcholki.size();j++){
            if(uzyte[wierzcholki[j]])continue;

            if(query(wierzcholek,sciezka[i],wierzcholki[j])){
                poddrzewo.push_back(wierzcholki[j]);
                uzyte[wierzcholki[j]]=1;
            }
        }
        robimy_drzewo_wariacie(sciezka[i],poddrzewo,n,licznik);
        poddrzewo.clear();
        licznik++;
    }
    return;
}

int main(){
    //std::ios_base::sync_with_stdio(0);
    //cout.tie(0);
    //cin.tie(0);

    srand(2137);

    int k,l;
    start(k,l);

    int liczba_wierzcholkow=(1<<(k+1))-1;

    int rodzic=0;
    vector<int> wierzcholki;
    for(int i=1;i<=liczba_wierzcholkow;i++){
        wierzcholki.push_back(i);
    }

    robimy_drzewo_wariacie(rodzic,wierzcholki,liczba_wierzcholkow,k);

    /*for(int i=0;i<polaczenia.size();i++){
        cout<<polaczenia[i].first<<" "<<polaczenia[i].second<<endl;
    }*/

    answer(polaczenia);
    return 0;
}
