#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int L,pierw,wy=1;
    cin>>L;
    pierw=sqrt(L);

    for (int i=2;i<pierw+1;i++)
    {

             if (L%i==0)
         {
             wy=0;
             break;
         }
         else
         {
             wy=1;

         }

    }
    if (wy==0 && L!=2)
    {
        cout<<"Z";
    }
    else
    {
        if (L==2 || wy==1)
        cout<<"P";
    }

    return 0;
}