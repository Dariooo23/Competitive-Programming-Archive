#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{

    int a;
    cin>>a;
    float tab[a],wynikp=1,wynikg[2];
    wynikg[0]=0;
    wynikg[1]=0.00;
    for (int i=0;i<a;i++)
    {
        cin>>tab[i];
    }

    sort (tab,tab+a);

    for (int i=0;i<a;i++)
    {
        if (tab[i]==tab[i+1])
        {
            wynikp=wynikp+1;
        }
        if (tab[i]!=tab[i+1])
        {
            if (wynikg[0]<wynikp)
            {
                wynikg[1]=tab[i];
                wynikg[0]=wynikp;
            }
            wynikp=0;
        }
    }
    if (wynikg[0]==1)
    {
        cout<<"0.00"<<endl;
    }
    else
    {
         cout<<setprecision(2)<<fixed<<wynikg[1];

    }



    return 0;
}