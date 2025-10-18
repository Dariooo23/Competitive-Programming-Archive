#include <iostream>
using namespace std;

int main()
{
   int n;
   int W;
   cin>>n;
   cin>>W;
   int c[n+1];
   int w[n+1];
   int A[n+1][W+1];
   for(int i = 1; i <=n; i++)
   {
       cin>>c[i];
       w[i]=c[i];
   }
   for(int i=1;i<=n;i++)
   {
       A[i][0]=0;
   }
   for(int i=0;i<=W;i++)
   {
       A[0][i]=0;
   }

 for(int i=1;i<=n;i++)
 {
     for (int j=0;j<=W;j++)
        {
            if(w[i]>j)
            {
                A[i][j]=A[i-1][j];
            }
            else
            {
                A[i][j]=max(A[i-1][j],A[i-1][j-w[i]]+c[i]);
            }
        }
 }


 cout<<A[n][W];







   return 0;
}