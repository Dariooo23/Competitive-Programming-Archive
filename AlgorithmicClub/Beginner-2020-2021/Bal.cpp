#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int is,k,wynik=0;
    cin>>is>>k;
    if (is>=7*k)
    {
        wynik=7000*k;
    }
    else
    {
        if (2*is>=7*k)
        {
            wynik=3500*k;
        }
        else
        {
            if (4*is>=7*k)
            {
                wynik=1750*k;
            }

        }
    }
    cout<<wynik;
    return 0;
}