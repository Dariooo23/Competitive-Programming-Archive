#include <iostream>

using namespace std;

int main()
{
    long long int a,b,s=0;
    cin>>a>>b;
    for (int i=a;i<b+1;i++)
    {
        s=a+s;
        a=a+1;
    }
    cout<<s<<endl;
    return 0;
}