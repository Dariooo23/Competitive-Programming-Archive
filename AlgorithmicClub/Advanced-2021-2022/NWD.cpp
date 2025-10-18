//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int M=1<<18;

long long int tab[2*M+1];

long long int NWD(long long int a,long long int b)
{
    long long int c=0;
	while(b!=0)
    {
		c=b;
		b=a%b;
		a=c;
	}
    return a;
}

long long int  query(long long int a,long long int b)
{
    a=a+M;
    b=b+M;
    long long int  res=tab[a];
    if(a!=b)
    {
        res=NWD(res,tab[b]);
    }
    while(a/2!=b/2)
    {
        if(a%2==0)
        {
            res=NWD(res,tab[a+1]);
        }
        if(b%2==1)
        {
            res=NWD(res,tab[b-1]);
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
        tab[x]=NWD(tab[2*x],tab[2*x+1]);
    }

}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,q,a,b,c;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        update(i,a);
    }
    for(int i=0;i<q;i++)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c;
            update(b,c);
        }
        else
        {
            cin>>b>>c;
            cout<<query(b,c)<<endl;
        }
    }
    

    return 0;
}