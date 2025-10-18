//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> rangi;

int find(int a){
    if(parent[a]!=a){
        parent[a]=find(parent[a]);
    }
    return parent[a];
}
void uni(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)return;

    if(rangi[a]>rangi[b]){
        swap(a,b);
    }

    parent[a]=b;
    if(rangi[a]==rangi[b])rangi[a]++;
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<vector<int>> mapa(n+1,vector<int> (n+1,0));
    vector<vector<int>> numer(n+1,vector<int> (n+1,0));
    parent.resize(n*n+1);
    rangi.resize(n*n+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mapa[i][j];
            numer[i][j]=(i-1)*n+j;
        }
    }

    for(int i=1;i<=n*n;i++){
        parent[i]=i;
        rangi[i]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mapa[i][j]==0)continue;

            if(j!=1){
                if(mapa[i][j-1]==1)uni(numer[i][j],numer[i][j-1]);
            }
            if(j!=n){
                if(mapa[i][j+1]==1)uni(numer[i][j],numer[i][j+1]);
            }
            if(i!=1){
                if(mapa[i-1][j]==1)uni(numer[i][j],numer[i-1][j]);
            }
            if(i!=n){
                if(mapa[i+1][j]==1)uni(numer[i][j],numer[i+1][j]);
            }
        }
    }

    int wynik=0;
    vector<int> bylo(n*n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mapa[i][j]==0)continue;
            int rodzic=find(numer[i][j]);
            if(bylo[rodzic])continue;
            bylo[rodzic]=1;
            wynik++;
        }
    }

    cout<<wynik;
    return 0;
}