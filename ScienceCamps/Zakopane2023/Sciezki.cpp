//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int n,m,k,wynik=0;
vector<vector<long long int>> tablica;
vector<vector<map<long long int,long long int>>> ksory1;
vector<vector<map<long long int,long long int>>> ksory2;

void rek1(int x,int y,long long int ksor,long long int odleglosc){
    
    if(odleglosc+1==(n+m)/2){
        if(ksory1[x][y].find(ksor)==ksory1[x][y].end()){
            ksory1[x][y][ksor]=1;
        }else{
            ksory1[x][y][ksor]++;
        }
    }else{
        if(x!=n){
            rek1(x+1,y,(ksor^tablica[x+1][y]),odleglosc+1);
        }
        if(y!=m){
            rek1(x,y+1,(ksor^tablica[x][y+1]),odleglosc+1);
        }
    }

    return;
}

void rek2(int x,int y,long long int ksor,long long int odleglosc){
    if(odleglosc+1==((n+m-1)/2+1)){
        
        if(ksory2[x][y].find(ksor)==ksory2[x][y].end()){
            ksory2[x][y][ksor]=1;
        }else{
            ksory2[x][y][ksor]++;
        }
    }else{
        if(x!=1){
            rek2(x-1,y,(ksor^tablica[x-1][y]),odleglosc+1);
        }
        if(y!=1){
            rek2(x,y-1,(ksor^tablica[x][y-1]),odleglosc+1);
        }
    }

    return;
}

int main()
{
    //std::ios_base::sync_with_stdio(0);
    //cout.tie(0);
    //cin.tie(0); 

    cin>>n>>m>>k;

    tablica.resize(n+1,vector<long long int> (m+1));
    ksory1.resize(n+1,vector<map<long long int,long long int>> (m+1));
    ksory2.resize(n+1,vector<map<long long int,long long int>> (m+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>tablica[i][j];
        }
    }

    rek1(1,1,tablica[1][1],0);
    rek2(n,m,tablica[n][m],0);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i+j-1==(n+m)/2){
                for(auto it=ksory2[i][j].begin();it!=ksory2[i][j].end();++it){
                    long long int dopelnienie=(k^(it->first)^tablica[i][j]);
                    if(ksory1[i][j].find(dopelnienie)!=ksory1[i][j].end()){
                        wynik=wynik+(ksory1[i][j][dopelnienie]*(it->second));
                    }
                }
            }

        }
    }

    cout<<wynik;

    return 0;
}
 