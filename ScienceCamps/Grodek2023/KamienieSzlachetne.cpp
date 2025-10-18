//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int wynik=0;
const long long int M=1<<20;
vector<long long int> tree(2*M,0);
vector<long long int> lazy(2*M,0);

void dodaj(int punkt,long long int ile){
    lazy[punkt]=lazy[punkt]+ile;
    tree[punkt]=tree[punkt]+ile;
}
void przekaz(int punkt){
    dodaj(2*punkt,lazy[punkt]);
    dodaj(2*punkt+1,lazy[punkt]);
    lazy[punkt]=0;
}

void update(int gdzie,int pocz,int kon,int x,int y,long long int ile){
    if(x<=pocz && y>=kon){
        dodaj(gdzie,ile);
        return;
    }

    przekaz(gdzie);
    int mid=(pocz+kon)/2;
    if(x<=mid){
        update(2*gdzie,pocz,mid,x,y,ile);
    }
    if(y>mid){
        update(2*gdzie+1,mid+1,kon,x,y,ile);
    }

    tree[gdzie]=min(tree[2*gdzie],tree[2*gdzie+1]);
    return;
}
long long int query(int gdzie, int pocz, int kon, int x,int y){
   if(x<=pocz && y>=kon){
       return tree[gdzie];
   }

   przekaz(gdzie);
   long long int mid=(pocz+kon)/2,wynik=1e18;
   if(x<=mid){
       wynik=min(wynik,query(2*gdzie,pocz,mid,x,y));
   }
   if(y>mid){
       wynik=min(wynik,query(2*gdzie+1,mid+1,kon,x,y));
   }

   tree[gdzie]=min(tree[2*gdzie],tree[2*gdzie+1]);
   return wynik;
}

bool cmp(const pair<long long int,long long int> &a,const pair<long long int,long long int> &b){
    if(a.second==b.second){
        return a.first<b.first;
    }else{
        return a.second<b.second;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int q;
    cin>>q;

    vector<pair<long long int,long long int>> kamienie;

    for(int i=1;i<=q;i++){
        int typ,a;

        cin>>typ;
        if(typ==0){
            cin>>a;
            update(1,1,M,i,q,a);
            if(query(1,1,M,i,q)<0){
                cout<<"-1";
                return 0;
            }
        }else{
            cin>>a;
            if(a>0){
                kamienie.push_back({i,a});
            }else{
                update(1,1,M,i,q,-a);
                wynik++;
            }
        }
    }

    sort(kamienie.begin(),kamienie.end(),cmp);
    for(int i=0;i<kamienie.size();i++){
        update(1,1,M,kamienie[i].first,q,-kamienie[i].second);
        if(query(1,1,M,kamienie[i].first,q)<0){
            update(1,1,M,kamienie[i].first,q,kamienie[i].second);
        }else{
            wynik++;
        }
    }

    cout<<wynik;
    return 0;
}
 