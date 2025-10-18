#include <bits/stdc++.h>

using namespace std;

vector<long double> x(100009);
vector<long double> y(100009);
vector<long double> dx(100009);
vector<long double> dy(100009);

long double  test(long double  rozmiar,long double czas)
{
    long double minx=1e18,miny=1e18,maxx=-1e18,maxy=-1e18;
    for(int i=0;i<rozmiar;i++)
    {
        maxx=max(maxx,x[i]+(dx[i]*czas));
        minx=min(minx,x[i]+(dx[i]*czas));
        maxy=max(maxy,y[i]+(dy[i]*czas));
        miny=min(miny,y[i]+(dy[i]*czas));
    }

    return max(maxx-minx,maxy-miny);
}

int main()
{
    std:ios_base::sync_with_stdio(0);
    long double  huragany;
    cin>>huragany;
    for(int i=0;i<huragany;i++)
    {
        cin>>x[i]>>y[i]>>dx[i]>>dy[i];
    }

    long double L=0,R=1e18,sr1,sr2,mini=1e-7;

    while(fabs(R-L)>mini)
   {
        sr1=(L+L+R)/3;
        sr2=(L+R+R)/3;
       if(test(huragany,sr1)>test(huragany,sr2))
       {
           L=sr1+mini;
       }
       else
       {
           R=sr2;
       }
   }
   cout<<fixed<<setprecision(10)<<test(huragany,L)<<" "<<L;
    return 0;
}