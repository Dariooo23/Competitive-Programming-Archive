//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const long long int m=1<<20;
vector<long long int> visited;
vector<vector<long long int>> graf;
vector<pair<long long int,long long int>> preorder;
vector<long long int> tree(2*m,0);

long long int akt_punkt=0;
void dfs(long long int s){
    akt_punkt++;
    preorder[s].first=akt_punkt;
    for(long long int v:graf[s]){
        if(visited[v])continue;
        visited[v]=1;
        dfs(v);
    }
    preorder[s].second=akt_punkt;
    return;
}

void update(long long int x,long long int y){
    x=x+m;
    tree[x]=tree[x]+y;
    while(x!=1){
        x=x/2;
        tree[x]=tree[x*2]+tree[x*2+1];
    }
    return;
}
long long int querry(long long int a,long long int b){
    a=a+m;
    b=b+m;
    long long int wynik=tree[a];
    if(a!=b)wynik=wynik+tree[b];
    while(a/2!=b/2){
        if(a%2==0){
            wynik=wynik+tree[a+1];
        }
        if(b%2==1){
            wynik=wynik+tree[b-1];
        }
        a=a/2;
        b=b/2;
    }

    return wynik;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,q;
    cin>>n>>q;

    graf.resize(n+1);
    visited.resize(n+1);
    preorder.resize(n+1);

    for(long long int i=1;i<n;i++){
        long long int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    visited[1]=1;
    dfs(1);

    while(q--){
        string polecenie;
        cin>>polecenie;

        long long int a,b;
        if(polecenie=="Add"){
            cin>>a>>b;
            update(preorder[a].first,b);
        }else{
            cin>>a;
            cout<<querry(preorder[a].first,preorder[a].second)<<endl;
        }
    }
    return 0;
}