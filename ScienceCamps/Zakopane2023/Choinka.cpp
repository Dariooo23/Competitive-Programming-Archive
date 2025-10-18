//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graf;
vector<int> kolory;

vector<set<int>> oznaczone_kolor;
vector<int> wyniki;

void dfs2(int s){
    oznaczone_kolor[s].insert(kolory[s]);

    for(int v:graf[s]){
        dfs2(v);
        if(oznaczone_kolor[v].size()<oznaczone_kolor[s].size()){
            for(auto it=oznaczone_kolor[v].begin();it!=oznaczone_kolor[v].end();++it){
                oznaczone_kolor[s].insert(*it);
            }
        }else{
            for(auto it=oznaczone_kolor[s].begin();it!=oznaczone_kolor[s].end();++it){
                oznaczone_kolor[v].insert(*it);
            }
            swap(oznaczone_kolor[s],oznaczone_kolor[v]);
        }
    }

    wyniki[s]=oznaczone_kolor[s].size();
    return;
}

void wzorcowka(int n){
    wyniki.resize(n+1);
    oznaczone_kolor.resize(n+1);

    dfs2(1);
    for(int i=1;i<=n;i++){
        cout<<wyniki[i]<<" ";
    }
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    graf.resize(n+1);
    kolory.resize(n+1);

    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        graf[a].push_back(i);
    }

    for(int i=1;i<=n;i++){
        cin>>kolory[i];
    }

    wzorcowka(n);
    return 0;
}