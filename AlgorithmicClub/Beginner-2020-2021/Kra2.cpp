#include <iostream>

using namespace std;
int tab2[10000];
int tab1[10000];
int main()
{
   std::ios_base::sync_with_stdio(0);
    int a=0,a1=0,p,k,nds=1,cz0=0,wynik=0;

    cin>>a>>a1;



    for (int i=0;i<a;i++)
    {
        cin>>tab1[i];
        if (tab1[i]==1)
        {
            wynik++;
        }
    }


    for (int i=0;i<a;i++)
  {
      p=0;
      k=0;
      if (tab1[i]==1)
      {

          p=i-a1+1;
          k=i+a1;
          if (p<0)
          {
              p=0;
          }
          if (k>a)
          {
              k=a;
          }
          for (int j=p;j<k;j++)
          {
              tab2[j]++;
          }
      }
  }

/*for (int i=0;i<a;i++)
{
    cout<<tab2[i]<<" ";
}*/


for (int i=0;i<a;i++)
{
    if (tab2[i]<=0)
    {
        nds=0;
    }
}
if (nds==0)
{
    cout<<"-1";
    return 0;
}

  for (int i=0;i<a;i++)
  {
      p=0;
      k=0;
      if (tab1[i]==1)
      {

          p=i-a1+1;
          k=i+a1;
          if (p<0)
          {
              p=0;
          }
          if (k>a)
          {
              k=a;
          }
          for (int j=p;j<k;j++)
          {
              if (tab2[j]-1<=0)
              {
                  cz0=1;
              }
          }
          if (cz0==0)
          {
              for (int j=p;j<k;j++)
          {
              tab2[j]--;
          }

              wynik--;
          }
          cz0=0;
      }
  }


     cout<<wynik<<endl;




/*for (int i=0;i<a;i++)
{
    cout<<tab2[i]<<" ";
}*/


    return 0;
}