//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

struct krawedz{
    int a,b,c;
};

bool cmp1(const krawedz &a, const krawedz &b){
    return a.c<b.c;
}
bool cmp2(const krawedz &a, const krawedz &b){
    return a.c>b.c;
}

vector<int> rang;
vector<int> parent;
vector<krawedz> krawedzie;

int fin(int x){
    if(parent[x]==x){
        return x;
    }else{
        parent[x]=fin(parent[x]);
        return parent[x];
    }
}
void uni(int a,int b){
    a=fin(a);
    b=fin(b);
    if(a==b)return;

    if(rang[a]>rang[b])swap(a,b);
    parent[a]=b;
    if(rang[a]==rang[b])rang[b]++;
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    rang.resize(n+1);
    parent.resize(n+1);

    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        krawedzie.push_back({a,b,c});
    }

    int minimum=0;
    for(int i=0;i<=n;i++){
        rang[i]=0;
        parent[i]=i;
    }
    sort(krawedzie.begin(),krawedzie.end(),cmp1);
    for(int i=0;i<m;i++){
        if(fin(krawedzie[i].a)!=fin(krawedzie[i].b)){
            uni(krawedzie[i].a,krawedzie[i].b);
            minimum=minimum+krawedzie[i].c;
        }
    }

    int maksimum=0;
    for(int i=0;i<=n;i++){
        rang[i]=0;
        parent[i]=i;
    }
    sort(krawedzie.begin(),krawedzie.end(),cmp2);
    for(int i=0;i<m;i++){
        if(fin(krawedzie[i].a)!=fin(krawedzie[i].b)){
            uni(krawedzie[i].a,krawedzie[i].b);
            maksimum=maksimum+krawedzie[i].c;
        }
    }

    cout<<maksimum-minimum+1;
    return 0;
}