#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);

    long long int a,wynik=1,c;
    cin>>a;
    if (a%2==0)
    {
        c=2;
        a=a/2;
        for (int i=0;i<a;i++)
        {
            wynik=wynik*c;
            c=c+2;

        }
    }
    else
    {
        c=1;
        a=a/2+1;
        for (int i=0;i<a;i++)
        {
            wynik=wynik*c;
            c=c+2;

        }
    }
    cout<<wynik;
    return 0;
}