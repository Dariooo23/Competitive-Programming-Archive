#include <iostream>
#include<iomanip>
using namespace std;
int n;
int tab[1000001];
int fib[100];
void preprocess()
{
    fib[0]=1;
    fib[1]=1;
     n=2;
    while (fib[n-1]+fib[n-2]<=1000000)
    {
        fib[n]=fib[n-1]+fib[n-2];
        n++;
    }
    for (int i=0;i<n;i++)
    {
        tab[fib[i]]=1;
    }
}
bool isSumOfTwoFib (int x)
{
    for (int i=0;i<n;i++)
    {
        if (fib[i]>x)
        {
            break;
        }
        if (tab[x-fib[i]])
        {
            return true;
        }

    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cout<<fixed<<setprecision(2);
    preprocess();
    int z;
    cin>>z;
    for (int i=0;i<z;i++)
    {
        int x;
        cin>>x;
        if (isSumOfTwoFib(x))
        {
            cout<<1<<" ";
        }
        else
        {
            cout<<0<<" ";
        }
    }
    return 0;
}