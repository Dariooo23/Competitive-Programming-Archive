//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int M=1<<20;
int tree[M*2+1];
int lazy[M*2+1];


void dodaj(int punkt,int ile)
{
    lazy[punkt]=max(lazy[punkt],ile);
    tree[punkt]=max(tree[punkt],ile);
}

void przekaz(int punkt)
{
    dodaj(2*punkt,lazy[punkt]);
    dodaj(2*punkt+1,lazy[punkt]);
    lazy[punkt]=0;
}

void update(int gdzie,int pocz,int kon,int x,int y,int ile)
{
    if(x<=pocz && y>=kon)
    {
        dodaj(gdzie,ile);
        return;
    }

    przekaz(gdzie);

    int mid=(pocz+kon)/2;
    if(x<=mid)
    {
        update(2*gdzie,pocz,mid,x,y,ile);
    }
    if(y>mid)
    {
        update(2*gdzie+1,mid+1,kon,x,y,ile);
    }

    tree[gdzie]=max(tree[2*gdzie],tree[2*gdzie+1]);
}

int query(int gdzie, int pocz, int kon, int x,int y)
{
   if(x<=pocz && y>=kon)
   {
       return tree[gdzie];
   }
  
   przekaz(gdzie);

   int mid=(pocz+kon)/2,wynik=0;
   if(x<=mid)
   {
       wynik=max(wynik,query(2*gdzie,pocz,mid,x,y));
   }
   if(y>mid)
   {
       wynik=max(wynik,query(2*gdzie+1,mid+1,kon,x,y));
   }

   tree[gdzie]=max(tree[2*gdzie],tree[2*gdzie+1]);
   return wynik;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;

    while(q--)
    {
        int a,b;
        cin>>a>>b;
        update(1,1,M,b+1,b+a,query(1,1,M,b+1,b+a)+1);
    }

    cout<<query(1,1,M,1,1e6);


    return 0;
}