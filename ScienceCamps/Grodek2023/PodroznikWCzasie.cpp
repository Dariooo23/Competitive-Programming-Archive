//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

struct krawedz 
{
    int a,b,waga;
};

LL n,m,q;
int nowa_krawedz;
LL aktualny_punkt=1;

vector<LL> rodzice;
vector<LL> preorder;
vector<LL> poddrzewa;
vector<LL> glebokosc;
vector<vector<LL>> graf;
vector<krawedz> krawedzie;
vector<LL> rodzice_krawedzi_hld;
vector<pair<LL,LL>> aktualizacje;

void oblicz_poddrzewa(LL s,LL p){
    poddrzewa[s]++;
    rodzice[s]=p;
    glebokosc[s]=glebokosc[p]+1;

    for(const LL &v:graf[s]){
        if(v==p)continue;
        oblicz_poddrzewa(v,s);
        poddrzewa[s]=poddrzewa[s]+poddrzewa[v];
    }
    return;
}

const LL M=1<<20;
vector<LL> tree(2*M,0);
vector<LL> tree2(2*M,0);

long long int query2(int pocz,int kon){
    pocz=pocz+M;
    kon=kon+M;

    long long int wynik=tree2[pocz];
    if(pocz!=kon)wynik=max(wynik,tree2[kon]);
    
    while(pocz/2!=kon/2){
        if(pocz%2==0){
            wynik=max(wynik,tree2[pocz+1]);
        }
        if(kon%2==1){
            wynik=max(wynik,tree2[kon-1]);
        }
        pocz=pocz/2;
        kon=kon/2;
    }
    return wynik;
}
void update2(int x,long long int y){
    x=x+M;
    tree2[x]=max(tree2[x],y);

    while(x!=1){
        x=x/2;
        tree2[x]=max(tree2[2*x],tree2[2*x+1]);
    }

}


//Aktualizacja HLD na drzewie przedzialowym w punkcie i zapytania na przedziale o maksymalna wartosc w drzewie
long long int query(int pocz,int kon){
    pocz=pocz+M;
    kon=kon+M;

    long long int wynik=tree[pocz];
    if(pocz!=kon)wynik=max(wynik,tree[kon]);
    
    while(pocz/2!=kon/2){
        if(pocz%2==0){
            wynik=max(wynik,tree[pocz+1]);
        }
        if(kon%2==1){
            wynik=max(wynik,tree[kon-1]);
        }
        pocz=pocz/2;
        kon=kon/2;
    }
    return wynik;
}
void update(int x,long long int y){
    x=x+M;
    tree[x]=max(tree[x],y);

    while(x!=1){
        x=x/2;
        tree[x]=max(tree[2*x],tree[2*x+1]);
    }

}
long long int query_hld(LL lewo,LL prawo){
    LL a,b;
    long long int czas=0;
    while(rodzice_krawedzi_hld[lewo]!=rodzice_krawedzi_hld[prawo]){

        if(glebokosc[rodzice_krawedzi_hld[lewo]]>glebokosc[rodzice_krawedzi_hld[prawo]]){

            a=preorder[lewo],b=preorder[rodzice_krawedzi_hld[lewo]];
            if(a>b)swap(a,b);
            czas=max(czas,query(a,b));
            lewo=rodzice[rodzice_krawedzi_hld[lewo]];

        }else{

            a=preorder[prawo],b=preorder[rodzice_krawedzi_hld[prawo]];
            if(a>b)swap(a,b);
            czas=max(czas,query(a,b));
            prawo=rodzice[rodzice_krawedzi_hld[prawo]];

        }
    }

    a=preorder[lewo],b=preorder[prawo];
    if(a>b)swap(a,b);
    czas=max(czas,query(a,b));
    
    return czas;
}
void hld(LL s){
    preorder[s]=aktualny_punkt;
    aktualny_punkt++;
    if(rodzice_krawedzi_hld[s]==0){
        rodzice_krawedzi_hld[s]=s;
    }

    LL dziecko=0,maks=0;
    for(int i=0;i<graf[s].size();i++){
        if(poddrzewa[graf[s][i]]>maks && graf[s][i]!=rodzice[s]){
            maks=poddrzewa[graf[s][i]];
            dziecko=graf[s][i];
        }
    }
    if(dziecko!=0){
        rodzice_krawedzi_hld[dziecko]=rodzice_krawedzi_hld[s];
        hld(dziecko);
    }

    for(int i=0;i<graf[s].size();i++){
        if(graf[s][i]==rodzice[s] || graf[s][i]==dziecko)continue;
        hld(graf[s][i]);
    }

    return;
}


//Struktura FindUnion i Comparator do stworzenia MST
struct FindUnion{
    long long int n;
    vector<long long int> parent;
    vector<long long int> rank;

    FindUnion(long long int x){
        n=x;
        parent.resize(n);
        rank.resize(n);
        for(long long int i=0;i<n;i++){
            rank[i]=0;
            parent[i]=i;
        }
        return;
    }

    long long int find(long long int x){
        if(parent[x]==x){
            return x;
        }

        parent[x]=find(parent[x]);

        return parent[x];
    }

    void uni(long long int x,long long int y){
        long long int a=find(x);
        long long int b=find(y);
        if(a==b)return;

        if(rank[a]>rank[b]) {
            parent[b]=a;
        }else{
            parent[a]=b;
        }

        if(rank[a]==rank[b]){
            rank[a]++;
        }
        return;
    }

    long long int operator[](long long int x){
        return find(x);
    }
    long long int operator()(long long int x){
        return find(x);
    }
    void operator()(long long int a,long long int b){
        uni(a,b);
        return;
    }
};
bool cmp(krawedz &a,krawedz &b){
    if(a.waga==b.waga){
        return a.a<b.a;
    }else{
        return a.waga<b.waga;
    }
}


int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    LL a,b,c;
    cin>>n>>m>>q;
    nowa_krawedz=n+1;

    //Wczytaj poczatkowe krawedzie
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        krawedzie.push_back({a,nowa_krawedz,i});
        krawedzie.push_back({b,nowa_krawedz,i});
        nowa_krawedz++;
    }

    //Tablice do HLD
    graf.resize(nowa_krawedz+100);
    rodzice.resize(nowa_krawedz+100,0);
    preorder.resize(nowa_krawedz+100,0);
    glebokosc.resize(nowa_krawedz+100,0);
    poddrzewa.resize(nowa_krawedz+100,0);
    rodzice_krawedzi_hld.resize(nowa_krawedz+100,0);

    //Stworz MST
    sort(krawedzie.begin(),krawedzie.end(),cmp);
    FindUnion fau(nowa_krawedz+100);

    for(int i=0;i<krawedzie.size();i++){
        if(fau.find(krawedzie[i].a)!=fau.find(krawedzie[i].b)){
            fau.uni(krawedzie[i].a,krawedzie[i].b);
            //cout<<krawedzie[i].a<<" "<<krawedzie[i].b<<" "<<krawedzie[i].waga<<endl;
            //Graf MST do HLD
            graf[krawedzie[i].a].push_back(krawedzie[i].b);
            graf[krawedzie[i].b].push_back(krawedzie[i].a);
            if(krawedzie[i].waga!=0 && krawedzie[i].a>=n+1){
                //cout<<krawedzie[i].a<<" "<<krawedzie[i].waga<<endl;
                aktualizacje.push_back({krawedzie[i].a,krawedzie[i].waga});
            }
            if(krawedzie[i].waga!=0 && krawedzie[i].b>=n+1){
                //cout<<krawedzie[i].b<<" "<<krawedzie[i].waga<<endl;
                aktualizacje.push_back({krawedzie[i].b,krawedzie[i].waga});
            }
        }
    }

    //Policz lekkie i ciezkie krawedzie oraz preorder pod aktualizacje w drzewie
    oblicz_poddrzewa(1,0);
    hld(1);

    //Zaktualizuj czas w ktorym powstaly polaczenia miedzy punktami
    for(int i=0;i<aktualizacje.size();i++){
        //cout<<preorder[aktualizacje[i].first]<<" "<<aktualizacje[i].second<<endl;
        update(preorder[aktualizacje[i].first],aktualizacje[i].second);
    }

    //Znajdz minimalny czas w ktorym istnieje polaczenie miedzy dwoma punktami
    for(int i=1;i<n;i++){
        update2(i,query_hld(i,i+1));
    }
    
    //Odpowiedz na pytania znajdujac minimalny czas w drugim drzewie przedzialowym
    for(int i=1;i<=q;i++){
        int a,b;
        cin>>a>>b;
        if(a==b){
            cout<<"0 ";
        }else{
            cout<<query2(a,b-1)<<" ";
        }
    }


    return 0;
}