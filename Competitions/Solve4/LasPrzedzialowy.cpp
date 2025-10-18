//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const long long int m=1<<20;
vector<long long int> tree(m*2,0);

long long int query(long long int x){
    x=x+m;
    long long int wynik=0;

    while(x!=0){
        wynik=wynik+tree[x];
        x=x/2;
    }

    return wynik;
}
void update(long long int pocz,long long int kon,long long int val){
    pocz=pocz+m;
    kon=kon+m;

    tree[pocz]=tree[pocz]+val;
    if(pocz!=kon)tree[kon]=tree[kon]+val;

    while(pocz/2!=kon/2){
        if(pocz%2==0){
            tree[pocz+1]=tree[pocz+1]+val;
        }
        if(kon%2==1){
            tree[kon-1]=tree[kon-1]+val;
        }
        pocz=pocz/2;
        kon=kon/2;
    }

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        long long int a;
        cin>>a;
        update(i,i,a);
    }
    for(int i=1;i<=q;i++){
        string operacja;
        cin>>operacja;
        if(operacja=="update"){
            long long int a,b,c;
            cin>>a>>b>>c;
            update(a,b,c);
        }else{
            long long int a;
            cin>>a;
            cout<<query(a)<<'\n';
        }
    }

    return 0;
}