#include <iostream>
#include <algorithm>

using namespace std;
int tab[1000000];
int main()
{
    std::ios_base::sync_with_stdio(0);

     int n=0;
     while (cin>>tab[n])
     {
         n++;
     }
     sort (tab,tab+n);
     for (int i=0;i<n;i++)
     {
         cout<<tab[i]<<" ";
     }
     cout<<endl;
    return 0;
}