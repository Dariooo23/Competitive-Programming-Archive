//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

long long int wynik=0;
long long int max_wysokosc=0;
long long int modulo=1000000007;

struct krawedz{
    long long int x,y,wysokosc;
};

vector<krawedz> krawedzie;
vector<long long int> rangi;
vector<long long int> parent;
vector<long long int> sposoby;
vector<long long int> wysokosci;

long long int find(long long int x){
    if(parent[x]==x){
        return parent[x];
    }else{
        parent[x]=find(parent[x]);
        return parent[x];
    }
}

void uni(long long int x,long long int y,long long int wysokosc){
    x=find(x);
    y=find(y);

    if(x==y)return;

    if(rangi[x]>rangi[y])swap(x,y);

    sposoby[y]=(((sposoby[x]+wysokosc-wysokosci[x]+modulo)%modulo)*((sposoby[y]+wysokosc-wysokosci[y]+modulo)%modulo))%modulo;

    wynik=sposoby[y]%modulo;
    wysokosci[y]=wysokosc%modulo;
    max_wysokosc=max(max_wysokosc,wysokosci[y]);

    parent[x]=y;
    if(rangi[x]==rangi[y])rangi[y]++;
    
    return;
}

bool cmp(const krawedz &a,const krawedz &b){
    return a.wysokosc<b.wysokosc;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int m,n,H;
    cin>>m>>n>>H;

    rangi.resize(n*m+10);
    parent.resize(n*m+10);
    sposoby.resize(n*m+10);
    wysokosci.resize(n*m+10);

    for(int i=1;i<=n*m;i++){
        rangi[i]=1;
        parent[i]=i;
        sposoby[i]=1;
        wysokosci[i]=0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<n;j++){
            long long int wysokosc;
            cin>>wysokosc;
            //cout<<(i-1)*n+j<<" "<<(i-1)*n+j+1<<"      ";
            krawedzie.push_back({(i-1)*n+j,(i-1)*n+j+1,wysokosc});
        }//cout<<endl;
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<=n;j++){
            long long int wysokosc;
            cin>>wysokosc;
            //cout<<(i-1)*n+j<<" "<<i*n+j<<"       ";
            krawedzie.push_back({(i-1)*n+j,i*n+j,wysokosc});
        }//cout<<endl;
    }

    sort(krawedzie.begin(),krawedzie.end(),cmp);

    for(int i=0;i<krawedzie.size();i++){
        uni(krawedzie[i].x,krawedzie[i].y,krawedzie[i].wysokosc);
    }

    cout<<(wynik+H-max_wysokosc)%modulo;
    return 0;
}