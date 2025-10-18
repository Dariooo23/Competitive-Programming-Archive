//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long

vector<long long int> robociki;
vector<long long int> plecak,plecak2;
vector<pair<long long int,long long int>> suma,grupy;

struct Fau{
    vector<int> parent,rank;
    Fau(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        suma.resize(n+1);
        for (int i=1;i<=n;i++){
            parent[i]=i;
        }

        return;
    }

    int find(int a){
        if(parent[a]!=a)parent[a]=find(parent[a]);
        return parent[a];
    }

    void uni(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b)return;

        if(rank[a]<rank[b])swap(a,b);
        parent[b]=a;

        if(rank[a]==rank[b])rank[a]++;
        return;
    }
};

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,m,k;
    cin>>n>>m>>k;

    Fau fau(n);
    robociki.resize(n+1);
    
    for(int i=1;i<=n;i++){
        cin>>robociki[i];
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        fau.uni(a,b);
    }

    for(int i=1;i<=n;i++){
        int rodzic=fau.find(i);

        suma[rodzic].second++;
        suma[rodzic].first+=robociki[i];
    }

    grupy.push_back({0,0});
    for(int i=0;i<suma.size();i++){
        if(suma[i].first!=0){
            grupy.push_back(suma[i]);
        }
    }

    plecak2.resize(k+1);
    for(LL i=1;i<grupy.size();i++)
    {
        plecak=plecak2;
        for(LL j=1;j<=k;j++){
            if(j-grupy[i].second>=0){
                plecak2[j]=max(plecak[j],plecak[j-grupy[i].second]+grupy[i].first);
            }else{
                plecak2[j]=plecak[j];
            }
        }
    }

    cout<<plecak2[k];
    return 0;
}