//Karol Dziekan
#include <bits/stdc++.h>


using namespace std;

vector<int> tab; 
vector<int> depth;
vector<int> sekta;
vector<int> parent;
vector<int> visited;
vector<vector<int>> g;

pair<int,int> dfs(int s,int p,int d){

    if(depth[s]!=-1){
        return {d-depth[s],p};
    }

    depth[s]=d;
    parent[s]=p;
    pair<int,int> wynikg={1e9,0};

    for(auto i:g[s])if(i!=p){
        pair<int,int> wynik=dfs(i,s,d+1);
        if(wynik.first>0 && wynikg.first>wynik.first){
            wynikg=wynik;
        }
    }

    return wynikg;
}
void dfs2(int s,int t){
    if(t==1){
        for(auto i:g[s]){
            if(tab[i]==1){
                t=2;
            }
        }
        sekta.push_back(s);
    }

    tab[s]=t;
    for(auto i:g[s])if(!tab[i]){
        dfs2(i,t==1?2:1);
    }

    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    
    g.resize(n+1);
    tab.resize(n+1);
    parent.resize(n+1);
    visited.resize(n+1);
    depth.resize(n+1,-1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    pair<int,int> cykl=dfs(1,0,0);
    if(cykl.first<=k){
        cout<<2<<endl<<cykl.first<<endl;

        for(int i=0;i<cykl.first;i++) {
            cout<<cykl.second<<" ";
            cykl.second=parent[cykl.second];
        }
    }else{
        k+=k%2;
        k/=2;
        dfs2(1,1);

        cout<<1<<endl;
        if(sekta.size()>=k){
            for(int i=0;i<k;i++){
                cout<<sekta[i]<<" ";
            }
        }else{
            sekta.clear();
            dfs2(1,2);
            for(int i=0;i<k;i++){
                cout<<sekta[i]<<" ";
            }
        }
    }

}