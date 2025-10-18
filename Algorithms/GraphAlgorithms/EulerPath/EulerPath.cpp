//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n,m;

vector<set<int>> graf;
vector<int> wynik;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>m;
    int punktstart;

    graf.resize(n+1);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        punktstart=a;
        graf[a].insert(b);
        graf[b].insert(a);
    }
    for(int i=1;i<=n;i++){
        if(graf[i].size()%2==1)punktstart=i;
    }

    stack<int> stos;
    stos.push(punktstart);

    while(!stos.empty()){
        int v=stos.top();
        if(graf[v].size()==0){
            wynik.push_back(v);
            stos.pop();
        }else{
            stos.push((*graf[v].begin()));
            graf[*graf[v].begin()].erase(v);
            graf[v].erase(graf[v].begin());
            
        }
    }

    for(int i=1;i<=n;i++){
        if(graf[i].size()!=0){
            cout<<-1;
            return 0;
        }
    }

    for(int i=0;i<wynik.size();i++){
        cout<<wynik[i]<<" ";
    }

    return 0;
}