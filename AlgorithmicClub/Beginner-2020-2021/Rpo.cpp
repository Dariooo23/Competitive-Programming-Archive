#include <iostream>
#include <iomanip>
using namespace std;

float potega (float x, float n)
{
      if (n <= 0)
         return 1;

      else
          return x * potega(x, n-1);
}
int main()
{
   float a,b;
   while(cin>>a>>b)
   {
       cout<<fixed<<setprecision(2)<<potega(a,b)<<endl;
   }
    return 0;
}