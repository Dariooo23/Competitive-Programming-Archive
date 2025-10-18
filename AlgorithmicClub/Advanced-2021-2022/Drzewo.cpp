//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int,int> PII;

vector<vector<int>> graf;
vector<vector<int>> graf2;
vector<bool> visited;
vector<int> czarne;
int wynik=1e9+9,n,m;

pair<int,int> dfs(int punkt,int odleglosc)
{
    int lisc=0,dlugosc=0;

    if(graf2[punkt].size()==1 && visited[graf2[punkt][0]]==1)
    {
        return {odleglosc,punkt};
    }

    for(const int &v:graf2[punkt])
    {
        if(visited[v]==0)
        {
            visited[v]=1;
            pair<int,int> dane;
            dane=dfs(v,odleglosc+1);
            if(dlugosc<dane.first)
            {
                dlugosc=dane.first;
                lisc=dane.second;
            }
        }
    }

    return {dlugosc,lisc};
}

void licz(int punkt)
{
    int rozmiar=0;
    if(czarne[punkt]==1)
    {
        rozmiar++;
    }
    queue<int> kolejka;
    kolejka.push(punkt);
    visited[punkt]=1;
    while(!kolejka.empty())
    {
        int s=kolejka.front();
        kolejka.pop();
        for(const int &v:graf[s])
        {
            if(visited[v]==0)
            {
                graf2[v].push_back(s);
                graf2[s].push_back(v);
                if(czarne[v]==1)
                {
                    rozmiar++;
                }
                visited[v]=1;
                kolejka.push(v);
            }
        }
        if(rozmiar>=m)
        {
            break;
        }
    }

    while(!kolejka.empty())
    {
        kolejka.pop();
    }

    visited.clear();
    visited.resize(n+1);
    visited[punkt]=1;
    int punkt2=dfs(punkt,0).second;
    
    visited.clear();
    visited.resize(n+1);
    visited[punkt2]=1;
    int odleglosc=dfs(punkt2,0).first;

    wynik=min(wynik,odleglosc);

}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>m;
    
    if(m==1)
    {
        cout<<0<<endl;
        exit(0);
    }

    czarne.resize(n+1);
    graf.resize(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>czarne[i];
    }
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        visited.resize(n+1);
        graf2.resize(n+1);
        licz(i);
        visited.clear();
        graf2.clear();
    }

    cout<<wynik<<endl;
    return 0;
}