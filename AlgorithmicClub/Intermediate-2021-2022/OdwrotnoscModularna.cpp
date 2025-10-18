#include <iostream>

using namespace std;

int main( )
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int a,b=1e9+9,u,w,x,z,q;

    cin>>a;

    u=1;
    w=a;
    x=0;
    z=b;

    while(w)
    {
        if(w<z)
        {
            q=u;
            u=x;
            x=q;

            q=w;
            w=z;
            z=q;
        }
        q=w/z;
        u=u-q*x;
        w=w-q*z;
    }
    
    if(x<0) 
    {
        x=x+b;
    }
    cout<<x<<endl;
    

    return 0;
}