//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cout<<"AC";
    
    return 0;
}
//Karol Dziekan
/*#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

long long int M=(1<<20);
vector<long long int> tree(2*M,0);

long long int query(int a,int b){
    a+=M;
    b+=M;

    long long int wynik=tree[a];
    if(a!=b)wynik=max(wynik,tree[b]);

    while(a/2!=b/2){
        if(a%2==0){
            wynik=max(wynik,tree[a+1]);
        }
        if(b%2==1){
            wynik=max(wynik,tree[b-1]);
        }
        a/=2;
        b/=2;
    }

    return wynik;
}

void update(int a,int b){
    a+=M;
    tree[a]=b;
    while(a/2!=1){
        a/=2;
        tree[a]=max(tree[a*2],tree[a*2+1]);
    }

    return;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int q;
    cin>>q;
    while(q--){
        int operacja,a,b;
        cin>>operacja;
        if(operacja==0){
            cin>>a>>b;
            update(a,b);
        }else{
            cin>>a>>b;
            cout<<query(a,b)<<endl;
        }
    }
    return 0;
}*/