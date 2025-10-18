#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;
stack <long double> S;
 long double stringToInt(string x)
 {
     long double d=0;
     for (int i=0;i<x.size();i++)
     {
         d=d*10+(int)(x[i]-'0');
     }
     return d;
 }

int main()
{
    string z;
    long double x,y;

    for (int i=0;cin>>z;i++)
    {
        if (!(z=="+"||z=="-"||z=="*"||z=="/"))
        {
            S.push(stringToInt(z));
        }
        else
        {
            if (!S.empty())
            {
              x=S.top();
            S.pop();
            }
            if (!S.empty())
            {
             y=S.top();
            S.pop();
            }
              if (z=="+")
              {
                  x=x+y;
              }
              if (z=="-")
              {
                  x=y-x;
              }
              if (z=="*")
              {
                  x=x*y;
              }
              if (z=="/")
              {
                  x=y/x;
              }
              S.push(x);
        }

    }
    cout.precision(2);
    cout<<fixed<<S.top()<<endl;
    return 0;
}