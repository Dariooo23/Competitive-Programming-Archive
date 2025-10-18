#include <bits/stdc++.h>

using namespace std;
char graf[1010][1010];
int grafteleportow[1010][1010]={0};
bool visited[1010][1010];
int odleglosc[1010][1010];


int main()
{
    std::ios_base::sync_with_stdio(0);
    int a,b;
    vector<pair<int,int>> teleporty(1000100);
    pair<int,int> wspolrzedne;
    queue<pair<int,int>> kolejka;
    pair<int,int> start,koniec;
    cin>>a>>b;
    cin>>start.second>>start.first;
    cin>>koniec.second>>koniec.first;
    start.first=start.first-1;    start.second=start.second-1;
    koniec.first=koniec.first-1;  koniec.second=koniec.second-1;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
           char c;
           cin>>c;
           graf[i][j]=c;
        }
    }
    int teleport;
    cin>>teleport;
    for(int i=1;i<=teleport;i++)
    {
        int d,e,f,g;
        cin>>d>>e>>f>>g;
        grafteleportow[e-1][d-1]=i;
        teleporty[i].first=g-1;
        teleporty[i].second=f-1;

    }


    wspolrzedne.first=start.first;
    wspolrzedne.second=start.second;
    kolejka.push(wspolrzedne);
    visited[start.first][start.second]=1;
    odleglosc[start.first][start.second]=0;
    odleglosc[koniec.first][koniec.second]=1e9;

 /*for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cout<<graf[i][j]<<" ";
        }
        cout<<endl;
    }*/
    while(!kolejka.empty())
    {
        if(graf[kolejka.front().first][kolejka.front().second]=='S')
        {
            kolejka.pop();
        }
        else
        {
        if(grafteleportow[kolejka.front().first][kolejka.front().second]>=0)
        {
              if(visited[ teleporty[ grafteleportow[ kolejka.front().first] [kolejka.front().second] ].first]   [teleporty [ grafteleportow [ kolejka.front().first] [kolejka.front().second] ].second]==0)
            {
                odleglosc[ teleporty[ grafteleportow[ kolejka.front().first] [kolejka.front().second] ].first]   [teleporty [ grafteleportow [ kolejka.front().first] [kolejka.front().second] ].second]=odleglosc[kolejka.front().first][kolejka.front().second]+1;
                wspolrzedne.first=teleporty[ grafteleportow[ kolejka.front().first] [kolejka.front().second] ].first;
                wspolrzedne.second=teleporty [ grafteleportow [ kolejka.front().first] [kolejka.front().second] ].second;
                visited [teleporty [grafteleportow [kolejka.front().first] [kolejka.front().second] ].first ] [teleporty [grafteleportow [kolejka.front().first] [kolejka.front().second] ].second]=1;
                kolejka.push(wspolrzedne);
            }
        }

        if(kolejka.front().first-1>=0)
        {
            if(visited[kolejka.front().first-1][kolejka.front().second]==0)
            {
                odleglosc[kolejka.front().first-1][kolejka.front().second]=odleglosc[kolejka.front().first][kolejka.front().second]+1;
                wspolrzedne.first=kolejka.front().first-1;
                wspolrzedne.second=kolejka.front().second;
                visited[kolejka.front().first-1][kolejka.front().second]=1;
                kolejka.push(wspolrzedne);
            }
        }
        if(kolejka.front().first+1<a)
        {
            if(visited[kolejka.front().first+1][kolejka.front().second]==0)
            {
                odleglosc[kolejka.front().first+1][kolejka.front().second]=odleglosc[kolejka.front().first][kolejka.front().second]+1;
                wspolrzedne.first=kolejka.front().first+1;
                wspolrzedne.second=kolejka.front().second;
                visited[kolejka.front().first+1][kolejka.front().second]=1;
                kolejka.push(wspolrzedne);
            }
        }
        if(kolejka.front().second-1>=0)
        {
            if(visited[kolejka.front().first][kolejka.front().second-1]==0)
            {
                odleglosc[kolejka.front().first][kolejka.front().second-1]=odleglosc[kolejka.front().first][kolejka.front().second]+1;
                wspolrzedne.first=kolejka.front().first;
                wspolrzedne.second=kolejka.front().second-1;
                visited[kolejka.front().first][kolejka.front().second-1]=1;
                kolejka.push(wspolrzedne);
            }
        }


        if(kolejka.front().second+1<b)
        {
            if(visited[kolejka.front().first][kolejka.front().second+1]==0)
            {
                odleglosc[kolejka.front().first][kolejka.front().second+1]=odleglosc[kolejka.front().first][kolejka.front().second]+1;
                wspolrzedne.first=kolejka.front().first;
                wspolrzedne.second=kolejka.front().second+1;
                visited[kolejka.front().first][kolejka.front().second+1]=1;
                kolejka.push(wspolrzedne);
            }
        }
        kolejka.pop();
        }
    }
    /*cout<<endl;
    cout<<endl;
    for(int i=0;i<=10;i++)
    {
        for(int j=0;j<=10;j++)
        {
            cout<<odleglosc[i][j]<<" ";
        }
        cout<<endl;
    }*/
    if(odleglosc[koniec.first][koniec.second]==1e9)
    {
        cout<<"-1";
    }
    else
    {
        cout<<odleglosc[koniec.first][koniec.second];
        //cout<<koniec.first<<" "<<koniec.second;
    }
    return 0;
}