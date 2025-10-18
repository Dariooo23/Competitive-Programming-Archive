//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int>wyniki;
vector<int> pytania;
vector<bool> zapytania;
vector<pair<int,int>> drogi;

struct FindUnion{
    long long int n;
    vector<long long int> parent;
    vector<long long int> rank;

    FindUnion(long long int n){
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

        if(a==b){
            return;
        }

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

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    drogi.resize(m+1);
    FindUnion fau(n+100);
    for(int i=1;i<=m;i++){
        cin>>drogi[i].first>>drogi[i].second;
    }

    int ilosc;
    cin>>ilosc;
    wyniki.resize(ilosc,0);
    pytania.resize(ilosc,0);
    zapytania.resize(1000009,0);
    for(int k=0;k<ilosc;k++){
        cin>>pytania[k];
        zapytania[pytania[k]]=1;
    }


    int wynik=n,odpowiedzi=0;
    for(int i=m;i>0;i--){
        if(zapytania[i]==0){
            if(fau.find(drogi[i].first)!=fau.find(drogi[i].second)){
                fau.uni(drogi[i].first,drogi[i].second);
                wynik--;
            }
        }
    }
    wyniki[odpowiedzi]=wynik;
    odpowiedzi++;

    for(int i=ilosc-1;i>0;i--){
        if(fau.find(drogi[pytania[i]].first)!=fau.find(drogi[pytania[i]].second)){    
            fau.uni(drogi[pytania[i]].first,drogi[pytania[i]].second);
            wynik--;
        }
        wyniki[odpowiedzi]=wynik;
        odpowiedzi++;
    }

    for(int i=ilosc-1;i>=0;i--){
        cout<<wyniki[i]<<" ";
    }
    return 0;
}