#include <iostream>

using namespace std;

int main()
{
    long long int x1,x2,x3,wynik=0;
    cin>>x1>>x2>>x3;
    for (int i=0;i<3;i++)
    {

    if (x1>x2)
    {
        swap(x1,x2);
    }
    if (x2>x3)
    {
        swap(x2,x3);
    }
    }
    if (x1<0)
    {
        wynik=x1*-1;
    }
    if (x3>wynik)
    {

       wynik=(x3-x1);
       
       if (wynik%2==0)
       {
           wynik=wynik/2;
       }
       else
       {
           wynik=wynik/2+1;
       }
        }


cout<<wynik;


    return 0;
}