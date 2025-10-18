#include <iostream>
#include <algorithm>
unsigned long long tab[1000009];
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
   int n;
   long long int wynik=0;
   cin>>n;
   for (int i=0;i<n;i++)
   {
       cin>>tab[i];
   }
   wynik=wynik+tab[n-1];

   for (int i=n-2;i>=0;i--)
   {
       tab[i]=min(tab[i],tab[i+1]);
       {
           wynik=wynik+tab[i];
       }
   }
   cout<<wynik;
      return 0;
}