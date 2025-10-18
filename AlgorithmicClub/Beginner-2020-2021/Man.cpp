#include <iostream>

using namespace std;
long long int nwd(long long int a, long long int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return nwd(b, a % b);
}
int main()
{
   long long  int a,a1,b,c,wynik;
    cin>>a;
    a1=a-1;
    if (a==2)
    {
        cout<<"4";
    }
    else
    {
        if (a==1)
        {
            cout<<"2";
        }
        else
        {
            b=nwd(a,a1);
            c=(a*a1)/b;
            cout<<c+b;





        }
    }
    return 0;
}