#include <bits/stdc++.h>

using namespace std;
int graf[200][200];
bool visited[200][200];
int odleglosc[200][200]={0};


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    pair<int,int> wspolrzedne;
    queue<pair<int,int>> kolejka;

    for(int i=1;i<=n;i++)
    {
        string slowo;
        cin>>slowo;
        for(int j=1;j<=m;j++)
        {
            if(slowo[j-1]=='1')
            {
                visited[i][j]=1;
                kolejka.push({i,j});
            }
        }
    }

    while(!kolejka.empty())
    {
        if(kolejka.front().first-1>0)
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

        if(kolejka.front().first+1<=n)
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

        if(kolejka.front().second-1>0)
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

        if(kolejka.front().second+1<=m)
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

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<odleglosc[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}