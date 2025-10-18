#include <bits/stdc++.h>

using namespace std;

const long long int maks=2e9;
long long int wynik=maks,wynik2=maks;
long long int tab[309][309];


int main( )
{
  std::ios_base::sync_with_stdio(0);
  long long int n,m;
  //WCZYTYWANIE
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
       tab[i][j]=maks;
    }
    tab[i][i]=0;
  }
  for(int i=1;i<=m;i++)
  {
    long long int x,y,w;
    cin>>x>>y>>w;
    if(x==y)
    {
        wynik2=min(wynik2,w);
    }
    tab[x][y]=min(tab[x][y],w);
  }


  //ALGORYTM FLOYDA WARSHALLA
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
      {
        if(tab[i][j]>tab[i][k]+tab[k][j])
        {
           tab[i][j]=tab[i][k]+tab[k][j];
        }
      }
  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=n;j++)
      {
          if(i!=j)
          {
              wynik=min(wynik,tab[i][j]+tab[j][i]);
          }
      }
  }
  wynik=min(wynik,wynik2);
  if(wynik!=maks)
  {
      cout<<wynik;
  }
  else
  {
      cout<<"NIE";
  }
  return 0;
}