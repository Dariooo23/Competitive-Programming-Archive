#include <iostream>

using namespace std;

int main()
{
    int a,b,c,x,y,z,nadk=0,brakk=0;
    cin>>a>>b>>c>>x>>y>>z;
    a=a-x;
    b=b-y;
    c=c-z;

    if (a>0)
    {
        nadk=nadk+a/2;
    }
    else
    {
        brakk=brakk+a;
    }
    
    
    
    
    if (b>0)
    {
        nadk=nadk+b/2;
    }
    else
    {
        brakk=brakk+b;
    }
    
    
    
    if (c>0)
    {
        nadk=nadk+c/2;
    }
    else
    {
        brakk=brakk+c;
    }
    
    
    
    brakk=brakk*-1;
    if(brakk<=nadk)
    {
        cout<<"Tak";
    }
    else
    {
        cout<<"Nie";
    }
    return 0;
}