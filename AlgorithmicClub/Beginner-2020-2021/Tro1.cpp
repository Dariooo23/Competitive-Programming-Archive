#include <iostream>

using namespace std;

int main()
{
    int t,lt=1;
    cin>>t;
    for (int i=0;i<t;i++)
    {
        for (int j=0;j<lt;j++)
        {
             cout<<"T";
        }
        cout<<endl;
        lt=lt+1;

    }
lt=lt-1;
    for (int i=0;i<t-1;i++)
    {
        lt=lt-1;
        for (int j=0;j<lt;j++)
        {
             cout<<"T";
        }
        cout<<endl;


    }
    return 0;
}