#include <iostream>

using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(0);
    int a,e,d=0;
    bool b[100001]={0},c=0;
    cin>>a;

    for (int i=0;i<a;i++)
    {
        cin>>e;
        b[e]=1;
    }
    for (int i=1;i<=100001;i++)
    {
       c=0;
       d=i;
       while (d<100001)
       {
           if (b[d]==1)
           {
               c=1;
           }
           d=d+i;
       }
        if (c==0)
           {
               cout<<i;
               break;
           }
    }

    return 0;
}