#include <iostream>

using namespace std;

int main()
{

    long long int n,L,a,pp,kp,wynik=0,lwm=0;
    cin>>n>>L>>a;
    bool ZM[L];
    for (int i=0;i<L;i++)
    {
        ZM[i]=0;
    }
    for (int i=0;i<n;i++)
    {
        cin>>pp>>kp;
        for (int j=pp;j<pp+kp;j++)
        {
            ZM[j]=1;
        }
    }

    for (int i=0;i<L;i++)
    {


        if (ZM[i]==0)
        {
            lwm=lwm+1;
        }



        if (ZM[i]!=0)
        {
            lwm=0;
        }

        if (lwm==a)
        {
            wynik=wynik+1;
            lwm=0;
        }


    }
cout<<wynik;
    return 0;
}