#include <bits/stdc++.h>

using namespace std;
char graf[1000][1000];
bool visited[1000][1000];
int odleglosc[1000][1000];


int main()
{
    std::ios_base::sync_with_stdio(0);
    int a,b;
    pair<int,int> wspolrzedne;
    queue<pair<int,int>> kolejka;
    pair<int,int> start,koniec;
    cin>>a>>b;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
           char c;
           cin>>c;
           if(c=='S')
           {
             start.first=i;
             start.second=j;
           }
           if(c=='M')
           {
               koniec.first=i;
               koniec.second=j;
           }
               graf[i][j]=c;
        }
    }


    wspolrzedne.first=start.first;
    wspolrzedne.second=start.second;
    kolejka.push(wspolrzedne);
    odleglosc[start.first][start.second]=0;
    odleglosc[koniec.first][koniec.second]=1e9;


    while(!kolejka.empty())
    {
        if(graf[kolejka.front().first][kolejka.front().second]=='#')
        {
            kolejka.pop();
        }
        else
        {
        

        if(kolejka.front().first-1>=0)
        {
            if(visited[kolejka.front().first-1][kolejka.front().second]==0)
            {
                odleglosc[kolejka.front().first-1][kolejka.front().second]=odleglosc[kolejka.front().first][kolejka.front().second]+1;
                wspolrzedne.first=kolejka.front().first-1;
                wspolrzedne.second=kolejka.front().second;
                visited[kolejka.front().first-1][kolejka.front().second]=1;
                kolejka.push(wspolrzedne);
                //cout<<"dziala";
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
                 //cout<<"dziala";
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
                 //cout<<"dziala";
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
                 //cout<<"dziala";
            }
        }


        kolejka.pop();
        }
    }

   /* for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cout<<odleglosc[i][j]<<" ";
        }
        cout<<endl;
    }*/

    if(odleglosc[koniec.first][koniec.second]==1e9)
    {
        cout<<"NIE";
    }
    else
    {
        cout<<odleglosc[koniec.first][koniec.second];
    }
    return 0;
}