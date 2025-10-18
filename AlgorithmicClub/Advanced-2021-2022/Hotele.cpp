#include <bits/stdc++.h>

using namespace std;

const int M=1<<20;

long long int tab[2*M];

long long int  query(int a,int b)
{
    a=a+M;
    b=b+M;
    long long int  res=tab[a];
    if(a!=b)
    {
        res=res+tab[b];
    }
    while(a/2!=b/2)
    {
        if(a%2==0)
        {
            res=res+tab[a+1];
        }
        if(b%2==1)
        {
            res=res+tab[b-1];
        }
        a=a/2;
        b=b/2;
    }
    return res;
}

void update(int x,int y)
{
    x=x+M;
    tab[x]=y;
    while(x!=1)
    {
        x=x/2;
        tab[x]=tab[2*x]+tab[2*x+1];
    }

}
int main()
{
    std::ios_base::sync_with_stdio(0);
    int n,q,a,b,t;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        update(i,a);
    }

    while(q>0)
    {
        cin>>t>>a>>b;
        if(t==1)
        {
            update(a,b);
        }
        else
        {
            if(b<a)
            {
                cout<<"0";
            }
            else
            {
                 cout<<query(a,b)<<endl;
            }

        }
        q--;
    }
    return 0;
}