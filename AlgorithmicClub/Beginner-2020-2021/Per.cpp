#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(2);


    int a,wynik=0;
    cin>>a;
    int tab[a];
    for (int i=0;i<a;i++)
    {
        cin>>tab[i];
    }
    sort (tab,tab+a);
    for (int i=0;i<a;i++)
    {
        if (tab[i]==i+1)
        {
            wynik=0;
        }
        else
        {
            wynik=1;
            break;
        }

    }
    if (wynik==0)
    {
        cout<<"TAK";
    }
    else
    {
        cout<<"NIE";
    }
    return 0;
}