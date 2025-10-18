#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long int a=0,c=0,plony=0;
    cin>>a;
    long long int b[a];
    for (int i=0;i<a;i++)
    {
        cin>>b[i];
    }
    sort(b,b+a);
    cin>>c;

    for (int i=a-1;i>-1;i=i-1)
    {

        if (c>=b[i])
        {
            plony=plony+b[i]*b[i];
            c=c-b[i];
        }
        else
        {
            plony=plony+c*c;
            c=0;
        }
    }
cout<<plony;
    return 0;
}