#include <iostream>

using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int j=0;j<n;j++)
    {
       int x=0;
    for (int i=0;i<3;i++)
    {
        int a;
        cin>>a;
        x^=a;

    }
    if (x!=0)
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