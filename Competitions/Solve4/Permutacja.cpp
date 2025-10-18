//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int licznik=0;
vector<vector<int>> graf;
vector<int> visited;
vector<int> rozmiary;

void dfs(int s){
    licznik++;
    visited[s]=1;
    for(int v:graf[s]){
        if(visited[v])continue;
        dfs(v);
    }

    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int a,b;
    cin>>a>>b;

    graf.resize(a+1);
    visited.resize(a+1,0);

    for(int i=1;i<=a;i++){
        int c;
        cin>>c;
        graf[i].push_back(c);
        graf[c].push_back(i);
    }

    for(int i=1;i<=a;i++){
        if(visited[i])continue;
        licznik=0;
        dfs(i);
        rozmiary.push_back(licznik);
    }

    sort(rozmiary.begin(),rozmiary.end());
    long long int wynik=0,indeks=rozmiary.size()-1;
    while(b>=0 && indeks>=0){
        wynik=wynik+rozmiary[indeks];
        indeks--;
        b--;
    }

    cout<<wynik;
    return 0;
}