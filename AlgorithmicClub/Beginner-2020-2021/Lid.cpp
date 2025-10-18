#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int wynikw=0,lll=1,wl=0,ll,wnr;

    cin>>ll;
    int tab[ll];
    wnr=ll/2;
    for (int i=0;i<ll;i++)
    {
        cin>>tab[i];
    }
    wnr=ll/2;
    sort(tab,tab+ll);
    //for (int i=0;i<ll;i++)
    //{
    //    cout<<tab[i]<<" ";
    //}
    for (int i=1;i<ll;i++)
    {
        if(tab[i]==tab[i-1])
        {
           lll=lll+1;
        }
        else
        {
            if (lll>wynikw)
            {
                wynikw=lll;
                wl=tab[i-1];
            }
            lll=1;

        }
        if (lll>wynikw)
            {
                wynikw=lll;
                wl=tab[i-1];
            }
    }

    if (wynikw>wnr)
    {
        cout<<wl;
    }
    else
    {
        cout<<"brak";
    }
    return 0;
}