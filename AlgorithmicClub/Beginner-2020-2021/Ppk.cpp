#include <iostream>

using namespace std;

int main()
{
    int ip,a,b,s=0;
    cin>>ip;
    for (int i=0;i<ip;i++)
    {
        cin>>a>>b;
        if (a+b>s)
        {
            s=a+b;
        }
        else
        {
            continue;
        }
    }
    cout<<s;
    return 0;
}