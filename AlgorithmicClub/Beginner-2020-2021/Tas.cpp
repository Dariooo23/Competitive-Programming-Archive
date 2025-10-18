#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int a,sl=0,sp=0,wynikg=0,wynikz=0,czw=0;
    cin>>a;
    int tab[a];
    for (int i=0;i<a;i++)
    {
        cin>>tab[i];
    }
sl=tab[0];
for (int i=1;i<a;i++)
{
    sp=sp+tab[i];
}
for (int i=1;i<a;i++)
{
   wynikz=sl-sp;
    if (wynikz<0)
   {
       wynikz=wynikz*-1;
   }
   if (wynikz<wynikg ||czw==0)
   {
       wynikg=wynikz;
       czw=1;
   }
   sl=sl+tab[i];
   sp=sp-tab[i];
}









    cout<<wynikg;
    return 0;
}