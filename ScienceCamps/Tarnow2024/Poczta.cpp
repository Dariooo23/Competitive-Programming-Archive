//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

long long int n,humor;
vector<vector<long long int>> kolejki;
priority_queue<pair<pair<long long int,long long int>,pair<int,int>>> oplacalnosc;

pair<pair<long long int,long long int>,pair<int,int>> oblicz_przedzial(int numer,int indeksg){
    long long int minimum=0,suma=0;
    pair<pair<long long int,long long int>,pair<int,int>> przedzial={{-1,-1},{-1,-1}};

    for(int j=indeksg;j<kolejki[numer].size();j++){
        suma+=kolejki[numer][j];
        minimum=min(suma,minimum);
        if(suma>=0){
            przedzial={{minimum,suma},{numer,j+1}};
            break;
        }
    }

    return przedzial;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>humor;

    kolejki.resize(n);

    for(int i=0;i<n;i++){
        int dlugosc;
        cin>>dlugosc;
        for(int j=0;j<dlugosc;j++){
            long long int a;
            cin>>a;
            kolejki[i].push_back(a);
        }
    }

    for(int i=0;i<n;i++){
        pair<pair<long long int,long long int>,pair<int,int>> przedzial=oblicz_przedzial(i,0);
        if(przedzial.second.first!=-1)oplacalnosc.push(przedzial);
    }

    while(!oplacalnosc.empty()){
        pair<pair<long long int,long long int>,pair<int,int>>przedzial=oplacalnosc.top();
        oplacalnosc.pop();

        if(humor+przedzial.first.first>=0){
            humor+=przedzial.first.second;
        }else{
            break;
        }

        pair<pair<long long int,long long int>,pair<int,int>> przedzial_nowy=oblicz_przedzial(przedzial.second.first,przedzial.second.second);
        if(przedzial_nowy.second.first!=-1)oplacalnosc.push(przedzial_nowy);
    }

    cout<<humor;
    return 0;
}