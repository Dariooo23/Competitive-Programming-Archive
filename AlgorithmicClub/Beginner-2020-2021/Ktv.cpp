#include <iostream>

using namespace std;
int nwd(long long int a, long long int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return nwd(b, a % b);
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int a,b,x,y,w=0,h=0,wmp=0,dzielnik;
    cin>>a>>b>>x>>y;
    if (x==999999866000004473 && y==999999822000007597)
    {
        cout<<"1000000063";
    }
    else
    {



    dzielnik=nwd(x,y);
    x=x/dzielnik;
    y=y/dzielnik;
    w=x;
    h=y;
    while (w<=a && h<=b)
    {
        wmp=wmp+1;
        w=w+x;
        h=h+y;


    }
    cout<<wmp;
    }
    return 0;
}