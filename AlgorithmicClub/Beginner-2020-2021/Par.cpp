#include <iostream>

using namespace std;

int main()
{
    int a,wynik=0;
    while (cin>>a)
    {
        if(a%2==0)
        {
            wynik=wynik+1;
        }
    }
    cout<<wynik;
    return 0;
}