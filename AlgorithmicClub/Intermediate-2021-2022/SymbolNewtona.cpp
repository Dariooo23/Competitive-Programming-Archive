#include <iostream>

using namespace std;
unsigned long long int tab[70][70];

int main()
{
    std::ios_base::sync_with_stdio(0);
   int n,k,a;
   cin>>n>>k;
   tab[0][0]=1;
   for (int i=1;i<=n;i++)
   {
       for (int j=0;j<=k;j++)
       {
           if (j==0)
           {
               tab[i][j]=1;

           }
           else
           {
               tab[i][j]=tab[i-1][j]+tab[i-1][j-1];
           }
       }
   }
   cout<<tab[n][k];
  return 0;
}