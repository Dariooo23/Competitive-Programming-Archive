//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> kolory;
vector<vector<int>> graf;
vector<long long int> odleglosc;

void dfs(int s,int p)
{
    odleglosc[s]=odleglosc[p]+1;
    for(const int &v:graf[s]){
        if(v==p)continue;
        dfs(v,s);
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n;

    odleglosc.resize(n+1);
    kolory.resize(n+1);
    graf.resize(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>kolory[i];
    }
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    int punkt1=1,punkt2,maks;
    long long int wynik=0;

    odleglosc.clear();
    odleglosc.resize(n+1);
    dfs(punkt1,0);
    maks=0;
    for(int i=1;i<=n;i++){
        if(odleglosc[i]>maks){
            maks=odleglosc[i];
            punkt2=i;
        }
    }

    odleglosc.clear();
    odleglosc.resize(n+1);
    dfs(punkt2,0);
    maks=0;
    for(int i=1;i<=n;i++){
        if(odleglosc[i]>maks){
            maks=odleglosc[i];
            punkt1=i;
        }
    }
    maks=0;
    for(int i=1;i<=n;i++){
        if(odleglosc[i]>maks && kolory[i]!=kolory[punkt2]){
            wynik=max(wynik,odleglosc[i]);
            maks=odleglosc[i];
        }
    }

    odleglosc.clear();
    odleglosc.resize(n+1);
    dfs(punkt1,0);
    maks=0;
    for(int i=1;i<=n;i++){
        if(odleglosc[i]>maks && kolory[i]!=kolory[punkt1]){
            wynik=max(wynik,odleglosc[i]);
            maks=odleglosc[i];
        }
    }

    cout<<wynik-1;
    return 0;
}
 