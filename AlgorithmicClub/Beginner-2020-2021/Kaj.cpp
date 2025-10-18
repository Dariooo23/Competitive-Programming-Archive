#include <iostream>
#include <algorithm>
using namespace std;
int tab[1000000];
int scalasort[1000000];

void scal(int lewy, int srodek, int prawy)
{
	int i=lewy,j=srodek+1;


  for(int i=lewy;i<=prawy;i++)
  {
          scalasort[i]=tab[i];
  }
  for(int k=lewy;k<=prawy;k++)
  {
   if(i<=srodek)
  {
     if(j<=prawy)
     {
          if(scalasort[j]<scalasort[i])
          {
               tab[k]=scalasort[j++];
          }
          else
             {
                tab[k]=scalasort[i++];
             }
     }
     else
        {
            tab[k]=scalasort[i++];
        }
  }
  else
     {
       tab[k]=scalasort[j++];
     }
  }


}

void sortowanie(int lewy,int prawy)
{
	if(prawy<=lewy)
	{
	    return;
	}
	int srodek=(prawy+lewy)/2;
	sortowanie(lewy,srodek);
	sortowanie(srodek+1,prawy);
	scal(lewy,srodek,prawy);
}

int main()
{
   int a,b,kaj=0;
   cin>>a>>b;

   for(int i=0;i<b;i++)
   {
       cin>>tab[i];
   }
   sortowanie(0,b-1);
   int najm=0;
   int najw=b-1;
   while(najm<=najw)
   {
       if(tab[najw]+tab[najm]>a)
       {
       najw--;
       kaj++;
       }
       else
       {
       najw--;
       najm++;
       kaj++;
       }
   }
   cout<<kaj;
}
