#include <bits/stdc++.h>

using namespace std;

const int M=1<<20;

long long int tab[2*M+9];

long long int  query(long long int a,long long int b)
{
    a=a+M;
    b=b+M;
    long long int  res=tab[a];
    if(a!=b)
    {
        res=min(res,tab[b]);
    }
    while(a/2!=b/2)
    {
        if(a%2==0)
        {
            res=min(res,tab[a+1]);
        }
        if(b%2==1)
        {
            res=min(res,tab[b-1]);
        }
        a=a/2;
        b=b/2;
    }
    return res;
}

void update(long long int x,long long int y)
{
    x=x+M;
    tab[x]=y;
    while(x!=1)
    {
        x=x/2;
        tab[x]=min(tab[2*x],tab[2*x+1]);
    }

}
int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int a,k;
    cin>>a>>k;
    if(k>a)
    {
        cout<<"0";
        exit(0);
    }
    long long int tab1[a+9];
    long long int wyn[a+9];
    for(int i=1;i<=a;i++)
    {
        cin>>tab1[i];
    }
    for(int i=1;i<=k;i++)
    {
        wyn[i]=tab1[i];
        update(i,wyn[i]);
    }
    for(int i=k+1;i<=a;i++)
    {
        wyn[i]=query(i-k,i-1)+tab1[i];
        update(i,wyn[i]);
    }
    long long int wynik=1e18+9;
    for(int i=a;i>a-k;i--)
    {
        wynik=min(wynik,wyn[i]);
    }
    cout<<wynik;
    return 0;
}
