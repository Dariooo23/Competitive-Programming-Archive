//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct pytanie{
    long long int ilosc,ulepszenia,nr;
};

long long int n,m;
const long long int M=1<<20;

vector<long long int> odpowiedzi;
vector<long long int> czy_fabryka;
vector<long long int> ilosc_fabryk;
vector<vector<long long int>> graf;
vector<vector<pytanie>> pytania;
vector<long long int> tree(M*2,0);

long long int query(long long int pocz,long long int kon){
    pocz=pocz+M;
    kon=kon+M;
    long long int wynik=tree[pocz];
    if(pocz!=kon){
        wynik=wynik+tree[kon];
    }
    while(pocz/2!=kon/2){
        if(pocz%2==0){
            wynik=wynik+tree[pocz+1];
        }
        if(kon%2==1){
            wynik=wynik+tree[kon-1];
        }
        pocz=pocz/2;
        kon=kon/2;
    }
    return wynik;
}
void update(long long int x,long long int y){
    x=x+M;
    tree[x]=tree[x]+y;
    while(x!=1){
        x=x/2;
        tree[x]=tree[2*x]+tree[2*x+1];
    }
    return;
}
void sprawdz(pytanie wejscie){
    long long int l=1,r=m+1,mid;
    while(l<r){
        mid=(l+r)/2;
        long long int min_fabryk=(((wejscie.ulepszenia*2)-1)/mid)+1;
                      min_fabryk=(min_fabryk-1)/(mid+1)+1;
        if(query(min_fabryk,n)<wejscie.ilosc){
            l=mid+1;
        }else{
            r=mid;
        }
    }

    odpowiedzi[wejscie.nr]=l;
    return;
}
void dfs(long long int s,long long int p){
    update(ilosc_fabryk[s],1);
    for(int i=0;i<pytania[s].size();i++){
        sprawdz(pytania[s][i]);
    }
    for(const long long int &v:graf[s]){
        if(v==p)continue;
        dfs(v,s);
    }
    update(ilosc_fabryk[s],-1);
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n>>m;

    graf.resize(n+9);
    pytania.resize(n+9);
    czy_fabryka.resize(n+9,0);
    ilosc_fabryk.resize(n+9,0);

    for(int i=1;i<=n;i++){
        cin>>czy_fabryka[i];
    }
    for(int i=1;i<n;i++){
        long long int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(czy_fabryka[i]){
            ilosc_fabryk[i]=1;
        }else{
            ilosc_fabryk[i]=0;
        }
        for(int j=0;j<graf[i].size();j++){
            if(czy_fabryka[graf[i][j]]){
                ilosc_fabryk[i]++;
            }
        }
    }

    long long int q;
    cin>>q;
    odpowiedzi.resize(q+9);

    for(int i=1;i<=q;i++){
        long long int x,t,k;
        cin>>x>>t>>k;
        pytania[x].push_back({t,k,i});
    }

    dfs(1,1);

    for(int i=1;i<=q;i++){
        if(odpowiedzi[i]==m+1){
            cout<<"-1"<<endl;
        }else{
            cout<<odpowiedzi[i]<<endl;
        }
    }

    return 0;
}
 