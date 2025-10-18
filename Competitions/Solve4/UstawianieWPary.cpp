//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int czas=1;
vector<int> wejscie;
vector<int> wchodzi;
vector<int> visited;
vector<vector<int>> graf;

long long int dfs(int s,int p){
    long long int suma=0;
    visited[s]=1;

    for(const auto &v:graf[s]){
        if(v==p)continue;
        if(visited[v]==1)return suma+1;

        suma=dfs(v,s);
        if(suma>0)return suma+1;
    }

    return 0;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    graf.resize(n+1);
    wejscie.resize(n+1);
    wchodzi.resize(n+1,0);
    visited.resize(n+1,0);

    for(int i=1;i<=n;i++){
        cin>>wejscie[i];
        wchodzi[wejscie[i]]++;
        graf[i].push_back(wejscie[i]);
        graf[wejscie[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(wejscie[wejscie[i]]==i){
            wchodzi[i]--;
        }
        czas=max(czas,wchodzi[i]);
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            int ilosc=dfs(i,0);
            if(ilosc<3)continue;

            if(ilosc%2==0){
                czas=max(czas,2);
            }else{  
                czas=max(czas,3);
            }
        }
    }

    cout<<czas;
    
    
    return 0;
}
 