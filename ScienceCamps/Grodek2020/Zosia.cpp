#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
 int n,x,a,p;
 cin>>n>>x;
 cin>>p;
 for (int i=2;i<=n;i++)
 {
     cin>>a;
     if(abs(a-p)>=x)
     {
         cout<<i<<" ";
     }
 }

    return 0;
}