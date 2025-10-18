#include <iostream>

using namespace std;
int l_pie[1000000];
int tab[1000000];
int main()
{
    cin.tie(0);
cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n=1000000;

   for(int i=2;i*i<=n;i++)
   {
       if(l_pie[i]==0)
       {
           for(int j=i+i;j<=n;j+=i)
           {
               l_pie[j]=1;
           }
       }
   }
   int k=0;
for(int i=2;i<=n;i++)
{
   if(l_pie[i]==0)
   {
       tab[k]=i;
       k++;
   }
}
int a;
int falango;
while(cin >>a)
{
    falango=0;
    if(a!=0)
    {
        for(int i=0;tab[i]<=a/2;i++)
        {
            if(l_pie[a-tab[i]]==0)
            {
                falango=1;
                break;
            }
        }
        if(falango==1) cout<<"T"<<endl;
        else
        {
            cout<<"N"<<endl;
        }

    }
}

return 0;
}