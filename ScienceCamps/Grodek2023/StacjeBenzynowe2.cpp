//Karol Dziekan
#include <iostream>
#include <vector>
#include <algorithm>
#include <new>
#include <set>

using namespace std;

int aktualny=1;
long long int wynikg=0;
vector<int> wierzcholki;
vector<int> trie_liczba(2e6);
vector<pair<int,int>> trie(2e6,{-1,-1});

void dodaj(int wskaznik,int potega,int liczba){
    if(potega==-1){
        trie_liczba[wskaznik]=liczba;
        return;
    }

    if((liczba>>potega)&1){
        if(trie[wskaznik].second==-1){
            trie[wskaznik].second=aktualny;
            trie[aktualny]={-1,-1};
            aktualny++;
        }
        dodaj(trie[wskaznik].second,potega-1,liczba);
    }else{
        if(trie[wskaznik].first==-1){
            trie[wskaznik].first=aktualny;
            trie[aktualny]={-1,-1};
            aktualny++;
        }
        dodaj(trie[wskaznik].first,potega-1,liczba);
    }
}
long long int znajdz(int wskaznik,int potega,int liczba){
    if(potega==-1)return trie_liczba[wskaznik]^liczba;

    if((liczba>>potega)&1){
        if(trie[wskaznik].second!=-1){
            return znajdz(trie[wskaznik].second,potega-1,liczba);
        }else{
            if(trie[wskaznik].first!=-1){
                return znajdz(trie[wskaznik].first,potega-1,liczba);
            }else{
                return liczba;
            }
        }
    }else{
        if(trie[wskaznik].first!=-1){
            return znajdz(trie[wskaznik].first,potega-1,liczba);
        }else{
            if(trie[wskaznik].second!=-1){
                return znajdz(trie[wskaznik].second,potega-1,liczba);
            }else{
                return liczba;
            }
        }
    }
}
void rek(int potega,int poczatek,int koniec){
    int srodek=-1;
    bool flaga1=0,flaga2=0;
    if(((wierzcholki[poczatek]&(1<<potega))>>potega)==1){
        flaga1=1;
    }
    if(((wierzcholki[koniec]&(1<<potega))>>potega)==0){
        flaga2=1;
    }
    for(int i=poczatek;i<=koniec;i++){
        if(((wierzcholki[i]&(1<<potega))>>potega)==0){
            srodek=i;
            break;
        }
    }

    aktualny=1;
    trie[0]={-1,-1};
    if(srodek!=-1){
        long long int wynikp=1e18;
        for(int i=srodek;i<=koniec;i++){
            dodaj(0,31,wierzcholki[i]);
        }
        for(int i=poczatek;i<srodek;i++){
            wynikp=min(wynikp,znajdz(0,31,wierzcholki[i]));
        }
        if(wynikp!=1e18){
            wynikg=wynikg+wynikp;
        }
    }

    if(flaga1 && potega-1>=0){
        if(srodek==-1)srodek=koniec+1;
        rek(potega-1,poczatek,srodek-1);
    }
    if(flaga2 && potega-1>=0)rek(potega-1,srodek,koniec);

    return;
}

bool cmp(const int &a, const int &b){
    return a>b;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    set<int> zbior;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        zbior.insert(a);
    }
    for(auto it=zbior.begin();it!=zbior.end();++it){
        wierzcholki.push_back(*it);
    }

    sort(wierzcholki.begin(),wierzcholki.end(),cmp);
    rek(30,0,wierzcholki.size()-1);
    cout<<wynikg;

    return 0;
}