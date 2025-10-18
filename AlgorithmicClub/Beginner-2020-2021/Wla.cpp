#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a,wynik=0;
    cin>>a;
    int tab[a];
    for (int i=0;i<a;i++)
    {
        cin>>tab[i];
    }
    sort (tab,tab+a);

   for (int i=1;i<a;i++)
    {
        wynik=wynik+tab[i]-tab[i-1]-1;
    }
    cout<<wynik;
    return 0;
}