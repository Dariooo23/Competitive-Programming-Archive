#include <iostream>

using namespace std;

int main()
{
    long long int a,b,nlk1,nlk2,wynik;
    cin>>a>>b;
    if (a%2==0 || b%2==0)
    {
        cout<<"0"<<endl;
    }
    if (a%2==1 && b%2==1)
    {
      if (a>=b)
      {
          cout<<b;
      }
      else
      {
          cout<<a;
      }
    }


    return 0;
}