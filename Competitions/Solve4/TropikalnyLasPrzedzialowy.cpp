//Karol Dziekan
#include <iostream>
#include <vector>

using namespace std;

const int M=1<<20;
vector<long long int> tree(M*2+1);
vector<long long int> lazy(M*2+1,-1);
void dodaj(int punkt,int ilosc,long long int ile){
    if(ile!=-1){
        lazy[punkt]=ile;
        tree[punkt]=ile*ilosc;
    }
}

void przekaz(int punkt,int ilosc){
    dodaj(2*punkt,ilosc/2,lazy[punkt]);
    dodaj(2*punkt+1,ilosc/2,lazy[punkt]);
    lazy[punkt]=-1;
}

void update(int gdzie,int pocz,int kon,int x,int y,long long int ile){
    if(x<=pocz && y>=kon){
        dodaj(gdzie,kon-pocz+1,ile);
        return;
    }
    przekaz(gdzie,kon-pocz+1);

    int mid=(pocz+kon)/2;
    if(x<=mid){
        update(2*gdzie,pocz,mid,x,y,ile);
    }
    if(y>mid){
        update(2*gdzie+1,mid+1,kon,x,y,ile);
    }

    tree[gdzie]=tree[2*gdzie]+tree[2*gdzie+1];
    return;
}

long long int query(int gdzie, int pocz, int kon, int x,int y){

   if(x<=pocz && y>=kon){
       return tree[gdzie];
   }
   przekaz(gdzie,kon-pocz+1);

   long long int mid=(pocz+kon)/2,wynik=0;
   if(x<=mid){
       wynik=wynik+query(2*gdzie,pocz,mid,x,y);
   }
   if(y>mid){
       wynik=wynik+query(2*gdzie+1,mid+1,kon,x,y);
   }
   tree[gdzie]=tree[2*gdzie]+tree[2*gdzie+1];
   return wynik;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int q;
    cin>>q;

    while(q>0){
        long long int a,b,c;
        string t;
        cin>>t;
        if(t=="update"){
            cin>>a>>b>>c;
            update(1,1,M,a,b,c);
        }else{
            cin>>a>>b;
            cout<<query(1,1,M,a,b)<<'\n';
        }
        q--;
    }

    return 0;
}
 