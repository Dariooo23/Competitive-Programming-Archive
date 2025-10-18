//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> graf;
vector<int> dist;
int wynikg=0;

void dfs(int s,int p){
    for(const pair<int,int> v:graf[s]){
        if(v.first==p)continue;

        dist[v.first]=dist[s]^v.second;
        dfs(v.first,s);
    }
    return;
}

struct punkt_trie{
    punkt_trie* dziecko[2];
    bool lisc;
};
punkt_trie* stworz_punkt(char znak){
    punkt_trie* punkt=(punkt_trie*)calloc(1,sizeof(punkt_trie));

    punkt->dziecko[0]=NULL;
    punkt->dziecko[1]=NULL;

    punkt->lisc=0;
    return punkt;
}
punkt_trie* dodaj(punkt_trie* korzen,int liczba){
    punkt_trie* temp=korzen;

    for(int j=31;j>=0;j--)
    {
        int indeks=((liczba&(1<<j))>>j);
        if (temp->dziecko[indeks]==NULL){
            temp->dziecko[indeks]=stworz_punkt(char(indeks));
        }
        temp=temp->dziecko[indeks];
    }

    temp->lisc=1;
    return korzen;
}

int znajdz(punkt_trie* korzen,int liczba){
    punkt_trie* temp=korzen;

    int wynik=0;

    for(int j=31;j>=0;j--)
    {
        int indeks=!((liczba&(1<<j))>>j);

        if(temp->dziecko[indeks]==NULL){
            temp=temp->dziecko[!indeks];
        }else{
            wynik=wynik+(1<<j);
            temp=temp->dziecko[indeks];
        }
    }

    return wynik;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    graf.resize(n+1);
    dist.resize(n+1,0);

    for(int i=1;i<n;i++){
        int a,b;
        int waga;
        cin>>a>>b>>waga;
        graf[a].push_back({b,waga});
        graf[b].push_back({a,waga});
    }

    dist[1]=0;
    dfs(1,0);

    punkt_trie* korzen=stworz_punkt('\0');

    for(int i=1;i<=n;i++){
        dodaj(korzen,dist[i]);
    }
    for(int i=1;i<=n;i++){
        wynikg=max(wynikg,znajdz(korzen,dist[i]));
    }

    cout<<wynikg;
    return 0;

}
 