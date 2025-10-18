#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int a,wynik=0;
    cin>>a;
    int tab[a];
    for (int i=0;i<a;i++)
    {
        cin>>tab[i];
        if (tab[i]<0)
        {
            wynik=wynik+1;
        }


    }
    wynik=wynik*(a-1);
    cout<<wynik;
    return 0;
}