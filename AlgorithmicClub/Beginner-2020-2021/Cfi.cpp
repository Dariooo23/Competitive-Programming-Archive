#include <iostream>

using namespace std;
long long int tab1[32];
int main()
{
    int a,tln=0;
    std::ios_base::sync_with_stdio(0);
    tab1[0]=0;
    tab1[1]=1;
    for (int i=2;i<32;i++)
    {
       tab1[i]=tab1[i-1]+tab1[i-2];

    }
   /*for (int i=2;i<32;i++)
    {
       cout<<tab1[i]<<" ";

    }*/
    tab1[1]=1;
    while(cin>>a)
    {
        for (int i=0;i<32;i++)
    {
       if (a==tab1[i])
       {
           tln=1;
       }

    }
    if(tln==1)
     {
         cout<<"1"<<'\n';

     }
     else
     {
         cout<<"0"<<'\n';
     }
     tln=0;
    }

    return 0;
}