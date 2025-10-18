//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tab(1e6+9,vector<int> (3));
vector<long long int> dis(1e6+9);
const int maks=2e9+9;

void bellmanford(int v, int e,int s)
{
    for (int i=0;i<v;i++)
    {
         dis[i]=maks;
    }
    dis[s]=0;
    for (int i=0;i<v-1;i++)
    {
        for (int j=0;j<e;j++)
        {
            if (dis[tab[j][0]]!=maks && dis[tab[j][0]]+tab[j][2]<dis[tab[j][1]])
            {
                dis[tab[j][1]]=dis[tab[j][0]]+tab[j][2];
            }
        }
    }

    for (int i=0;i<e;i++)
    {
        int x=tab[i][0];
        int y=tab[i][1];
        int waga=tab[i][2];
        if (dis[x]!=maks && dis[x]+waga<dis[y])
        {
           cout <<"NIE";
           exit(0);
        }
    }

    for (int i=0;i<v;i++)
    {
        if(i!=s && dis[i]!=maks)
        {
             cout<<i<<" "<<dis[i]<<endl;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //Wprowadzasz ilosc wierzcholkow, krawedzi oraz punkt, na koncu zostana wypisane wszystkie odleglosci od tego puntu do innych
    //Albo zostanie wypisane "NIE" jezeli w grafie istnieje cykl ujemny
    
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
      int a,b,c;
      cin>>tab[i][0];
      cin>>tab[i][1];
      cin>>tab[i][2];

    }
    bellmanford(n,m,s);
    return 0;
}