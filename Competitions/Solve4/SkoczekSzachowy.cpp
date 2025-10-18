//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector<vector<int>> dist;
vector<vector<int>> visited;
vector<vector<char>> plansza;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    pair<int,int> start,koniec;
    dist.resize(n+1,vector<int> (m+1,0));
    plansza.resize(n+1,vector<char> (m+1));
    visited.resize(n+1,vector<int> (m+1,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;
            cin>>a;
            if(a=='S'){
                start.first=i;
                start.second=j;
            }
            if(a=='K'){
                koniec.first=i;
                koniec.second=j;
            }
            plansza[i][j]=a;
        }
    }

    queue<pair<int,int>> kolejka;
    dist[start.first][start.second]=0;
    kolejka.push(start);
    while(!kolejka.empty()){
        pair<int,int> punkt=kolejka.front();
        kolejka.pop();

        if(punkt.first-2>=0 && punkt.second-1>=0){
            if(!(visited[punkt.first-2][punkt.second-1] || plansza[punkt.first-2][punkt.second-1]=='#')){
                visited[punkt.first-2][punkt.second-1]=1;
                dist[punkt.first-2][punkt.second-1]=dist[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first-2,punkt.second-1});
            }
        }
        if(punkt.first-2>=0 && punkt.second+1<m){
            if(!(visited[punkt.first-2][punkt.second+1] || plansza[punkt.first-2][punkt.second+1]=='#')){
                visited[punkt.first-2][punkt.second+1]=1;
                dist[punkt.first-2][punkt.second+1]=dist[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first-2,punkt.second+1});
            }
        }
        if(punkt.first+2<n && punkt.second-1>=0){
            if(!(visited[punkt.first+2][punkt.second-1] || plansza[punkt.first+2][punkt.second-1]=='#')){
                visited[punkt.first+2][punkt.second-1]=1;
                dist[punkt.first+2][punkt.second-1]=dist[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first+2,punkt.second-1});
            }
        }
        if(punkt.first+2<n && punkt.second+1<m){
            if(!(visited[punkt.first+2][punkt.second+1] || plansza[punkt.first+2][punkt.second+1]=='#')){
                visited[punkt.first+2][punkt.second+1]=1;
                dist[punkt.first+2][punkt.second+1]=dist[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first+2,punkt.second+1}); 
            }
        }
        if(punkt.first-1>=0 && punkt.second-2>=0){
            if(!(visited[punkt.first-1][punkt.second-2] || plansza[punkt.first-1][punkt.second-2]=='#')){
                visited[punkt.first-1][punkt.second-2]=1;
                dist[punkt.first-1][punkt.second-2]=dist[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first-1,punkt.second-2});
            }
        }
        if(punkt.first+1<n && punkt.second-2>=0){
            if(!(visited[punkt.first+1][punkt.second-2] || plansza[punkt.first+1][punkt.second-2]=='#')){
                visited[punkt.first+1][punkt.second-2]=1;
                dist[punkt.first+1][punkt.second-2]=dist[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first+1,punkt.second-2});
            }
        }
        if(punkt.first-1>=0 && punkt.second+2<m){
            if(!(visited[punkt.first-1][punkt.second+2] || plansza[punkt.first-1][punkt.second+2]=='#')){
                visited[punkt.first-1][punkt.second+2]=1;
                dist[punkt.first-1][punkt.second+2]=dist[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first-1,punkt.second+2});
            }
        }
        if(punkt.first+1<n && punkt.second+2<m){
            if(!(visited[punkt.first+1][punkt.second+2] || plansza[punkt.first+1][punkt.second+2]=='#')){
                visited[punkt.first+1][punkt.second+2]=1;
                dist[punkt.first+1][punkt.second+2]=dist[punkt.first][punkt.second]+1;
                kolejka.push({punkt.first+1,punkt.second+2});
            }
        }
    }

    if(dist[koniec.first][koniec.second]==0){
        cout<<"NIE";
    }else{
        cout<<dist[koniec.first][koniec.second];
    }
    return 0;
}