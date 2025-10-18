#include <iostream>

using namespace std;
int a, b, c;
int main()
{
   cin>>a;
   cin>>b;
   cin>>c;
   if (a<b && a<c) cout<<a<<endl;
   if (b<a && b<c) cout<<b<<endl;
   if (c<b && c<a) cout<<c<<endl;
   

    return 0;
}