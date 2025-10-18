#include <iostream>
#include <algorithm>
using namespace std;

long long H[1000000];
long long V[1000000];
int n;

long long counte (long long s)
{
    long long res=0;
    int x=-1;
    for (int i=n;i>=0;i--)
    {
        while (x<n && H[x+1]*V[i]<s)
        {
            x++;
        }
        res=res+n-x;
    }
    return res;
}

 long long bin(long long K)
 {
     long long p,k,s;
     p=H[0]*V[0];
     k=H[n]*V[n];
     while (p<k)
     {
         s=(p+k+1)>>1;
         if (counte(s)<K) k=s-1;
         else p=s;
     }
     return p;
 }
int main()
{
    ios_base::sync_with_stdio(0);

     long long k;
     int a,b,x,prev;
     cin>>a>>b>>n>>k;
     prev=0;
     for (int i=0;i<n;i++)
     {
         cin>>x;
         H[i]=x-prev;
         prev=x;
     }
     H[n]=a-prev;
     prev=0;
     for (int i=0;i<n;i++)
     {
         cin>>x;
         V[i]=x-prev;
         prev=x;
     }
     V[n]=b-prev;
     sort (H,H+n+1);
     sort (V,V+n+1);
     cout<<bin(k);
    return 0;
}