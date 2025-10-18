#include <iostream>
#include <map>
using namespace std;
map<long long int,long long int> tab;
long long int F(long long int a)
{
    if(a>=1)
    {
        if(tab[a/2]==0)
        {
           tab[a/2]=F(a/2);
        }
        if(tab[a/3]==0)
        {
           tab[a/3]=F(a/3);
        }
        if(tab[a/4]==0)
        {
           tab[a/4]=F(a/4);
        }
        if(tab[a/5]==0)
        {
           tab[a/5]=F(a/5);
        }
        if(tab[a/6]==0)
        {
           tab[a/6]=F(a/6);
        }
        if(tab[a/7]==0)
        {
           tab[a/7]=F(a/7);

        }
       return tab[a/2]+tab[a/3]+tab[a/4]+tab[a/5]+tab[a/6]+tab[a/7];
    }
    else
    {
        return 1;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int a,wynik=0;
    cin>>a;
    wynik=F(a);
    cout<<wynik;
    return 0;
}