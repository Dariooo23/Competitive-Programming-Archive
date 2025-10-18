#include <iostream>

using namespace std;

int main()
{
    int a,wynikg=0,wynikp=0;
    cin>>a;
    int tab[a];
    for (int i=0;i<a;i++)
    {
        cin>>tab[i];
    }
    for (int i=0;i<a;i++)
    {
        if (tab[i]==1)
        {
            wynikp=wynikp+1;
        }
        if (tab[i]==0)
        {

            if (wynikp>wynikg)
            {
                wynikg=wynikp;
                wynikp=0;
            }
            wynikp=0;
        }
        if (wynikp>wynikg)
            {
                wynikg=wynikp;
            }
    }
    cout<<wynikg;
    return 0;
}