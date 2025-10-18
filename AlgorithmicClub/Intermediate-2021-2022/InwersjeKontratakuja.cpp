//Karol Dziekan
#include<bits/stdc++.h>

using namespace std;

int liczby[2000009];
int scalasort[2000009];
long long int wynik=0;

void scal(int lewy, int srodek, int prawy)
{
	int i=lewy,j=srodek+1;


  for(int i=lewy;i<=prawy;i++)
  {
          scalasort[i]=liczby[i];
  }
  for(int k=lewy;k<=prawy;k++)
  {
  if(i<=srodek)
  {
     if(j<=prawy)
     {
          if(scalasort[j]<scalasort[i])
          {
               liczby[k]=scalasort[j++];
               wynik=wynik+srodek-i+1;
          }
          else
             {
                liczby[k]=scalasort[i++];
             }
     }
     else
        {
            liczby[k]=scalasort[i++];
        }
  }
  else
     {
       liczby[k]=scalasort[j++];
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
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>liczby[i];
    }

	sortowanie(0,n-1);
   
    cout<<wynik;

	return 0;
}