//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int a;
set<pair<long long int,long long int>> wyniki;

long long int czyPier(long long int x)
{
    if(x==0 || x==1)
    {
        return -1;
    }
    long long int x2=x;
    long long int t=-1;
    for(long long int i=2;i*i<=x;i++)
    {
        if(x2%i==0)
        {
            if(t==-1)
            {
                t=i;
            }
            else
            {
                return -1;
            }
            while(x2%i==0)
            {
                x2=x2/i;
            }
        }
    }
    if(t==-1 || t==x2)
    {
        return x2;
    }
    if(x2==1)
    {
        return t;
    }
    
    return -1;
}

void sprawdz(long long int d)
{
    long long int t=-1;
    if((d*(d+2))%a==0)
    {
         t=czyPier((d*(d+2))/a);
    }
    if(t!=-1)
    {
        wyniki.insert({d+1,t});
    }
        
    t=-1;
    if((d*(d-2))%a==0)
    {
        t=czyPier((d*(d-2))/a);
    } 
    if(t!=-1)
    {
        wyniki.insert({d-1,t});
    }
        
}

void solve()
{
    cin>>a;
    
    for(long long int i=1;i*i<=2*a;i++)
    {
        if((2*a)%i==0)
        {
            sprawdz(i);
            sprawdz((2*a)/i);
        }
    }
    cout<<wyniki.size()<<endl;
    wyniki.clear();
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int q;
    cin>>q;
    while(q--)
    {
        solve();
    }

    return 0;
}
 