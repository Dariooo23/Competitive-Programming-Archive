#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
void solve()
{
    int a,b;
    cin>>a>>b;
    for (int d=2;d*d<=2e9;d++)
    {
        if ((a%d==0) !=(b%d==0))
        {
            cout<<"NIE"<<endl;
            return;
        }
        while(a%d==0)
        {
            a/=d;
        }
        while(b%d==0)
        {
            b/=d;
        }
    }
    if (a==b)
    {
        cout<<"TAK"<<endl;

    }
    else
    {
        cout<<"NIE"<<endl;
    }

}
int main()
{
    int z;
    cin>>z;
    for (int i=0;i<z;i++)
    {
       solve();
    }
    return 0;
}