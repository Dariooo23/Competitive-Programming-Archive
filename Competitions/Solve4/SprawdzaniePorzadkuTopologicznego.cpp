//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graf;
vector<int> visited;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    graf.resize(n);
    visited.resize(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graf[b].push_back(a);
    }

    for(int i=n-1;i>=0;i--){
        int a;
        cin>>a;
        int flaga=0;
        visited[a]=1;
        for(int j:graf[a]){
            if(visited[j]==0)flaga=1;
        }

        if(flaga){
            cout<<a;
            return 0;
        }
    }

    cout<<"OK";
    return 0;
}