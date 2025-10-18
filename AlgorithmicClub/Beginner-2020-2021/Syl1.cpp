#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);

    int n,k,wynik=0,wynik2=0;
    cin>>n>>k;
    int tab[n];
    for (int i=0;i<n;i++)
    {
        cin>>tab[i];
    }
    for (int i=0;i<n;i++)
    {
       if (tab[i-1]==tab[i])
       {
           wynik=1;
       }
       else
       {
        wynik++;
       }
       if (wynik>wynik2)
       {
           wynik2=wynik;
       }

    }

        cout<<wynik2;

    return 0;
}