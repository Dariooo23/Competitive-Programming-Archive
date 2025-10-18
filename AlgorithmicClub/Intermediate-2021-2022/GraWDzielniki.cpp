#include <iostream>

using namespace std;

int main()
{
    long long int a;
    cin>>a;
    if(a==0)
    {
        cout<<"NIE";
    }
    else
    {
        if(a%2==0)
        {
            cout<<"TAK";
        }
        else
        {
            cout<<"NIE";
        }
    }
    return 0;
}