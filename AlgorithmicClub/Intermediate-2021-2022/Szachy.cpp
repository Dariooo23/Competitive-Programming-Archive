#include <iostream>

using namespace std;

int main()
{
   int n,maks,maks2=0,wynik=0;
   cin>>n;
   for (int i=0;i<n;i++)
   {
       for (int j=0;j<n;j++)
       {
       cin>>maks;
       if (maks>maks2)
       {
           maks2=maks;
       }

       }
       wynik=maks2+wynik;
       maks2=0;
       maks=0;
   }
   cout<<wynik;
    return 0;
}