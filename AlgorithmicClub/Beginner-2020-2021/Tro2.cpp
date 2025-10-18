#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int tab[45];
    int a=0,b=0,wynik=0;
    while(a<46)
    {
        cin>>tab[a];
         if (tab[a]==0)
        {
            break;
        }
        a=a+1;
    }
    b=min(a,45);
    sort (tab,tab+b);






    for (int i=2;i<b;i++)
    {
        if (tab[i]<tab[i-1]+tab[i-2])
        {
         cout<<tab[i]<<" "<<tab[i-1]<<" "<<tab[i-2]<<endl;
            wynik=i;
            break;
        }
    }
    if (wynik==0)
    {
        cout<<"NIE"<<endl;
    }



    return 0;
}
