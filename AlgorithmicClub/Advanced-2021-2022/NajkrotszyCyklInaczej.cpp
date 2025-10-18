//Karol Dziekan
#include<bits/stdc++.h>

using namespace std;


long double graf[109][109];
long double dist[109][109];
const long long int maksimum=1e9;


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    int n,m,ctr=50,dziala=0,dziala2=0;
    cin>>n>>m;


    for(int i=0;i<=101;i++)
    {
      for(int j=0;j<=101;j++)
      {
        graf[i][j]=maksimum;
      }
    }
    for(int i=1;i<=m;i++)
    {
      long long int a,b;
      long double c;
      cin>>a>>b>>c;
      graf[a][b]=min(graf[a][b],c);
    }


    long double poczatek=0,koniec=1e6,mid;
    while(ctr>0)
    {
        mid=(poczatek+koniec)/2;
        for(int i=0;i<=101;i++)
        {
          for(int j=0;j<=101;j++)
          {
            if(graf[i][j]!=maksimum)
            {
              dist[i][j]=graf[i][j]-mid;
            }
            else
            {
              dist[i][j]=graf[i][j];
            }
          }
        }


        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(dist[i][j]>dist[i][k]+dist[k][j])
                    {
                       dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }


        dziala=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j]+dist[j][i]<=0.0)
                {
                    dziala2=1;
                    dziala=1;
                }
            }
        }


        
        
          
          
            
       
        


       
        if(dziala==1)
        {
            koniec=mid;
        }
        else
        {
            poczatek=mid;
        }
        ctr--;
    }
    
if(!dziala2)
{
    cout<<"NIE"<<endl;
    exit(0);
}         cout<<fixed<<setprecision(6)<<poczatek;
    

    return 0;
}