//Karol Dziekan
#include<bits/stdc++.h>
using namespace std;

const long long int M=1<<20;

vector<int> indeksy;
vector<int> tree(M*2);

long long int query(int pocz,int kon){
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

void update(int x,long long int y){
    x=x+M;
    tree[x]=tree[x]+y;
    while(x!=1){
        x=x/2;
        tree[x]=tree[2*x]+tree[2*x+1];
    }

}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    indeksy.resize(n+1);
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        indeksy[a]=i;
    }
    for(int i=1;i<=n;i++){
        update(i,1);
    }

    long long int inwersje=0;
    for(int i=1;i<=n;i++){
        inwersje=inwersje+min(query(1,indeksy[i]),query(indeksy[i],n))-1;
        update(indeksy[i],-1);
    }

    cout<<inwersje;
	return 0;
}