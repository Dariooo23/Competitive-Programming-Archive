#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int a,wynik=0,najw;
    cin>>a;
    int tab[a];

    for (int i=0;i<a;i++)
    {
        cin>>tab[i];
    }

    najw=tab[0];

    for (int i=0;i<a;i++)
    {
        if (tab[i]>najw)
        {
            najw=tab[i];
        }
        if (wynik<najw-tab[i])
        {
            wynik=najw-tab[i];
        }
    }
    cout<<wynik;
    return 0;
}