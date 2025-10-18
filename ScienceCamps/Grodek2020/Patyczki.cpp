#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
 int a,b,c;
 cin>>a>>b>>c;
 if(a+b==c)
 {
     cout<<"TAK"<<endl;
 }
 else
 {
     if(b+c==a)
     {
         cout<<"TAK"<<endl;
     }
     else
     {
         if (c+a==b)
         {
             cout<<"TAK"<<endl;
         }
         else
         {
             cout<<"NIE"<<endl;
         }
     }
 }

    return 0;
}