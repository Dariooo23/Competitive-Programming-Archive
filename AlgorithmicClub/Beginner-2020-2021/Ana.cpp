#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int a;
    string b,c;
    cin>>a;

    for (int i=0;i<a;i++)
    {
       cin>>b>>c;
       sort (b.begin(),b.end());
       sort (c.begin(),c.end());
       if (b==c)
       {
           cout<<"TAK"<<endl;
       }
       else
       {
           cout<<"NIE"<<endl;
       }
    }

    return 0;
}