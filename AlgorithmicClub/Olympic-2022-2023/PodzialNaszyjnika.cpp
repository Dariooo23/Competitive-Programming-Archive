//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int n,k;

vector<long long int> korale;
vector<long long int> ostatni;
vector<long long int> kolejny_koral;
vector<long long int> ostatni_koral;
vector<pair<long long int,long long int>> przedzial_zabroniony;

const long long int M=1<<20;
vector<long long int> tree(M*2,0);
vector<long long int> tree2(M*2,0);

void update2(int punkt,int glebokosc){
    if(tree[punkt]>0){
        tree2[punkt]=(1<<(21-glebokosc));
    }else{
        if(punkt>=M){
            tree2[punkt]=0;
        }else{
            tree2[punkt]=tree2[punkt*2]+tree2[punkt*2+1];
        }
    }
}
void update1(long long int a,long long int b,long long int wartosc){
    a=a+M;
    b=b+M;

    int glebokosc=21;
    tree[a]=tree[a]+wartosc;
    if(a!=b)tree[b]=tree[b]+wartosc;

    update2(a,glebokosc);
    update2(b,glebokosc);

    while(a!=1){
        if(a/2!=b/2){
            if(a%2==0){
                tree[a+1]=tree[a+1]+wartosc;
                update2(a+1,glebokosc);
            }
            if(b%2==1){
                tree[b-1]=tree[b-1]+wartosc;
                update2(b-1,glebokosc);
            }
        }

        a=a/2;
        b=b/2;
        glebokosc--;
        update2(a,glebokosc);
        update2(b,glebokosc);
    }
}
long long int query(){
    return tree2[1];
}

long long int oblicz_sume_blokad(long long int j){
    long long int suma=tree[j];
    while(j>1){
        j=j/2;
        suma=suma+tree[j];
    }

    return suma;
}
long long int query_przod(long long int j){
    j=j+M;
    long long int punkt=-1;
    long long int glebokosc=21;
    long long int suma_blokad=oblicz_sume_blokad(j);
    if(suma_blokad==0)return j-M;

    while(j>1){
        suma_blokad=suma_blokad-tree[j];
        if(j%2==1){
            if(suma_blokad==0 && tree2[j-1]<(1<<(21-glebokosc))){
                punkt=j-1;
                break;
            }
        }

        j=j/2;
        glebokosc--;
    }

    if(punkt==-1)return -1;
    j=punkt;
    while(j<M){
        punkt=j*2+1;
        glebokosc++;
        if(tree2[punkt]<(1<<(21-glebokosc))){
            j=punkt;
        }else{
            j=j*2;
        }
    }

    return j-M;
}
long long int query_tyl(long long int j){
    if(j>=n)return -1;

    j=j+M;
    long long int punkt=-1;
    long long int glebokosc=21;
    long long int suma_blokad=oblicz_sume_blokad(j);
    if(suma_blokad==0)return j-M;

    while(j>1){
        suma_blokad=suma_blokad-tree[j];
        if(j%2==0){
            if(suma_blokad==0 && tree2[j+1]<(1<<(21-glebokosc))){
                punkt=j+1;
                break;
            }
        }

        j=j/2;
        glebokosc--;
    }

    if(punkt==-1)return -1;
    j=punkt;
    while(j<M){
        punkt=j*2;
        glebokosc++;
        if(tree2[punkt]<(1<<(21-glebokosc))){
            j=punkt;
        }else{
            j=j*2+1;
        }
    }

    return j-M;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n>>k;

    korale.resize(n+10);
    ostatni.resize(k+10,-1);
    kolejny_koral.resize(n+10,-1);
    ostatni_koral.resize(k+10,-1);
    przedzial_zabroniony.resize(k+10,{-1,-1});

    for(int i=0;i<n;i++){
        cin>>korale[i];
    }
    for(int i=n-1;i>=0;i--){
        kolejny_koral[i]=ostatni_koral[korale[i]];
        ostatni_koral[korale[i]]=i;

        if(ostatni[korale[i]]==-1){
            ostatni[korale[i]]=i;
        }
    }

   
    update1(n-1,n-1,1);
    for(int i=1;i<=k;i++){
        if(ostatni_koral[i]!=ostatni[i]){
            przedzial_zabroniony[i]={ostatni_koral[i],ostatni[i]-1};
            update1(przedzial_zabroniony[i].first,przedzial_zabroniony[i].second,1);
        }
    }

    long long int wynik1=0,wynik2=n;

    for(int i=0;i<n-1;i++){
        wynik1=wynik1+n-i-query();

        long long int koniec=min(i+n/2-1,n-1);

        long long int przod=query_przod(koniec);
        long long int tyl=query_tyl(koniec);

        if(przod!=-1 && przod>=i)wynik2=min(wynik2,max(przod-i+1,n-przod+i-1));
        if(tyl!=-1 && tyl<n)wynik2=min(wynik2,max(tyl-i+1,n-tyl+i-1));
        int kolor=korale[i];
        if(przedzial_zabroniony[kolor].first!=-1){
            update1(przedzial_zabroniony[kolor].first,przedzial_zabroniony[kolor].second,-1);
            if(kolejny_koral[i]!=-1){
                przedzial_zabroniony[kolor]={kolejny_koral[i],n-1};
                update1(przedzial_zabroniony[kolor].first,przedzial_zabroniony[kolor].second,1);
            }else{
                przedzial_zabroniony[kolor]={-1,-1};
            }
        }
    }

    cout<<wynik1<<" "<<wynik2*2-n;
    return 0;
}
 