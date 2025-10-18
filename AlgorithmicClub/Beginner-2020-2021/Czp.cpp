#include <iostream>

using namespace std;

int main()
{
    int n,g=0,m=0,s=0;
    int g2[2],m2[2],s2[2];
    cin>>n;
    for (int j=0;j<n;j++)
    {
    for (int i=0;i<2;i++)
    {

        cin>>g2[i];
        cin>>m2[i];
        cin>>s2[i];
    }

    g=g2[1]-g2[0]+g;
    m=m2[1]-m2[0]+m;
    s=s2[1]-s2[0]+s;
    if (s>=60)
    {
        s=s-60;
        m=m+1;
    }
     if (m>=60)
    {
        m=m-60;
        g=g+1;
    }
    }
    cout<<g<<":";

    if (m<10)
    {
       cout<<0<<m<<":";
    }
    else
    {
        cout<<m<<":";
    }

    if (s<10)
    {
       cout<<0<<s;
    }
    else
    {
        cout<<s;
    }







    return 0;
}