//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

vector<vector<int>> graf;
vector<int> sasiedzi;
vector<int> warstwa1;
vector<int> warstwa2;

void dfs(int s,int p){
    sasiedzi[s]=graf[s].size();
    if(graf[s].size()==1)warstwa1.push_back(s);

    for(const int &v:graf[s]){
        if(v==p)continue;
        dfs(v,s);
    }

    return;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,l;
    cin>>n>>l;

    graf.resize(n+1);
    sasiedzi.resize(n+1);
    
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    dfs(1,-1);

    long long int wynik=0;
    while(warstwa1.size()!=0){
        wynik=wynik+min(2*l,(int)warstwa1.size());
        for(const int &v:warstwa1){
            for(const int &w:graf[v]){
                sasiedzi[w]--;
                if(sasiedzi[w]==1)warstwa2.push_back(w);
            }
        }
        warstwa1=warstwa2;
        warstwa2.clear();
    }

    cout<<wynik;
    return 0;
}