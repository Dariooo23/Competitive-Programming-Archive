#include <iostream>

using namespace std;

int main()
{
    int a,b,a1,b1;
    cin>>a>>b;
b1=b;
a1=a;


      while (a!=b)
      {
          if (a>b)
          {
              b=b+b1;
          }
          else
          {
              a=a+a1;
          }
      }
      cout<<a;
    return 0;
}