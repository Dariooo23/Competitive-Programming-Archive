#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int a,b,wynik=0;
    cin>>a>>b;
    while (a!=b)
    {
        wynik++;
        if (a<b)
        {
           b=b/2;
        }
        else
        {
            a=a/2;
        }
    }
    cout<<wynik;
    return 0;
}