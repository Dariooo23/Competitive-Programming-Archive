//Karol Dziekan
#include <iostream>
#include <vector>
#include <algorithm>
#include <new>
#include <set>

using namespace std;

int wynikg=0;
vector<int> wierzcholki;

struct punkt_trie{
    punkt_trie* dziecko[2];
};

struct Drzewo_Trie{
    punkt_trie* stworz_punkt(){
        punkt_trie* punkt=new(punkt_trie);

        punkt->dziecko[0]=NULL;
        punkt->dziecko[1]=NULL;

        return punkt;
    }
    punkt_trie* dodaj(punkt_trie* korzen,int liczba){
        punkt_trie* temp=korzen;

        for(short int j=31;j>=0;j--)
        {
            bool indeks=((liczba&(1<<j))>>j);
            if (temp->dziecko[indeks]==NULL){
                temp->dziecko[indeks]=stworz_punkt();
            }
            temp=temp->dziecko[indeks];
        }

        return korzen;
    }
    int znajdz(punkt_trie* korzen,int liczba){
        punkt_trie* temp=korzen;
        int wynikpp=0;
        for(short int j=31;j>=0;j--)
        {
            int indeks=((liczba&(1<<j))>>j);
            if(temp->dziecko[indeks]==NULL){
                wynikpp=wynikpp+(1<<j);
                temp=temp->dziecko[!indeks];
            }else{
                temp=temp->dziecko[indeks];
            }
        }
        return wynikpp;
    }
    bool czy_puste(punkt_trie* korzen)
    {
        if(korzen->dziecko[0])return false;
        if(korzen->dziecko[1])return false;
        return true;
    }
    punkt_trie* usun(punkt_trie* korzen,int liczba,short int glebokosc=31){
        if(!korzen)return 0;
    
        if(glebokosc==0){
            if (czy_puste(korzen)){
                delete(korzen);
                korzen=NULL;
            }
    
            return korzen;
        }

        bool indeks=((liczba&(1<<glebokosc))>>glebokosc);
        korzen->dziecko[indeks]=usun(korzen->dziecko[indeks],glebokosc-1);
    
        if(czy_puste(korzen)){
            delete(korzen);
            korzen=NULL;
        }
    
        return korzen;
    }
};

void rek(short int potega,int poczatek,int koniec){
    Drzewo_Trie drzewo;
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

    if(srodek!=-1){
        int wynikp=1e9;
        punkt_trie* korzen=drzewo.stworz_punkt();
        for(int i=srodek;i<=koniec;i++){
            drzewo.dodaj(korzen,wierzcholki[i]);
        }
        for(int i=poczatek;i<srodek;i++){
            wynikp=min(wynikp,drzewo.znajdz(korzen,wierzcholki[i]));
        }
        for(int i=srodek;i<=koniec;i++){
            drzewo.usun(korzen,wierzcholki[i]);
        }
        if(wynikp!=1e9){
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