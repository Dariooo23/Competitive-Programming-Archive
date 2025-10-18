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
long long int modulo=1e9+7;

vector<int> tree(M*2,1);

void update(int a,int b,long long int c){
    a+=M;
    b+=M;

    tree[a]=(tree[a]*c)%modulo;
    if(a!=b)tree[b]=(tree[b]*c)%modulo;
    
    while(a/2!=b/2){
        if(a%2==0){
            tree[a+1]=(tree[a+1]*c)%modulo;
        }
        if(b%2==1){
            tree[b-1]=(tree[b-1]*c)%modulo;
        }
        a=a/2;
        b=b/2;
    }
}


long long int query(int a){
    a+=M;
    long long int wynik=tree[a];

    while(a!=1){
        a=a/2;
        wynik=(wynik*tree[a])%modulo;
    }

    return wynik;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int q;
    cin>>q;

    while(q--){
        int operacja,a,b,c;
        cin>>operacja;
        if(operacja==0){
            cin>>a>>b>>c;
            update(a,b,c);
        }else{
            cin>>a;
            cout<<query(a)<<endl;
        }
    }
    return 0;
}*/