#include <iostream>

using namespace std;
int main()
{
    long long int a,b,NWD,SCD;
    int S,WS=0;
    cin>>S;
    while (SCD!=0)
    {
        cin>>SCD;
        WS=WS+SCD;
    }

a=S;
b=WS;

{
    while(a!=b)
       if(a>b)
           a-=b;
       else
           b-=a;

}

NWD=a;

    WS=WS/NWD;
    S=S/NWD;

    cout<<WS<<"/"<<S<<endl;

    return 0;
}