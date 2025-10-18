//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int x,y,z;
struct punkt{
    int x,y,z;
};

vector<vector<vector<int>>> windy;
vector<vector<vector<char>>> wejscie;
vector<vector<vector<bool>>> visited;
vector<vector<vector<long long int>>> odleglosci;

void bfs(punkt start){
    queue<punkt> kolejka;
    kolejka.push(start);
    visited[start.z][start.y][start.x]=1;
    odleglosci[start.z][start.y][start.x]=0;
    while(!kolejka.empty()){
        punkt s=kolejka.front();
        kolejka.pop();
        if(s.x-1>=1 && wejscie[s.z][s.y][s.x-1]!='X' && visited[s.z][s.y][s.x-1]==0){
            odleglosci[s.z][s.y][s.x-1]=odleglosci[s.z][s.y][s.x]+1;
            visited[s.z][s.y][s.x-1]=1;
            kolejka.push({s.x-1,s.y,s.z});
            if(windy[s.z][s.y][s.x-1]!=0){
                int wejscie_do_windy=windy[s.z][s.y][s.x-1];
                int wskaznik=s.z-1;
                while(wskaznik>=1){
                    if(windy[wskaznik][s.y][s.x-1]==wejscie_do_windy && wejscie[wskaznik][s.y][s.x-1]!='X' && visited[wskaznik][s.y][s.x-1]==0){
                        odleglosci[wskaznik][s.y][s.x-1]=odleglosci[s.z][s.y][s.x-1];
                        visited[wskaznik][s.y][s.x-1]=1;
                        kolejka.push({s.x-1,s.y,wskaznik});
                    }
                    wskaznik--;
                }

                wskaznik=s.z+1;
                while(wskaznik<=z){
                    if(windy[wskaznik][s.y][s.x-1]==wejscie_do_windy && wejscie[wskaznik][s.y][s.x-1]!='X'&& visited[wskaznik][s.y][s.x-1]==0){
                        odleglosci[wskaznik][s.y][s.x-1]=odleglosci[s.z][s.y][s.x-1];
                        visited[wskaznik][s.y][s.x-1]=1;
                        kolejka.push({s.x-1,s.y,wskaznik});
                    }
                    wskaznik++;
                }
            }
        }
        if(s.x+1<=x && wejscie[s.z][s.y][s.x+1]!='X' && visited[s.z][s.y][s.x+1]==0){
            odleglosci[s.z][s.y][s.x+1]=odleglosci[s.z][s.y][s.x]+1;
            visited[s.z][s.y][s.x+1]=1;
            kolejka.push({s.x+1,s.y,s.z});
            if(windy[s.z][s.y][s.x+1]!=0){
                int wejscie_do_windy=windy[s.z][s.y][s.x+1];
                int wskaznik=s.z-1;
                while(wskaznik>=1){
                    if(windy[wskaznik][s.y][s.x+1]==wejscie_do_windy && wejscie[wskaznik][s.y][s.x+1]!='X' && visited[wskaznik][s.y][s.x+1]==0){
                        odleglosci[wskaznik][s.y][s.x+1]=odleglosci[s.z][s.y][s.x+1];
                        visited[wskaznik][s.y][s.x+1]=1;
                        kolejka.push({s.x+1,s.y,wskaznik});
                    }
                    wskaznik--;
                }

                wskaznik=s.z+1;
                while(wskaznik<=z){
                    if(windy[wskaznik][s.y][s.x+1]==wejscie_do_windy && wejscie[wskaznik][s.y][s.x+1]!='X'&& visited[wskaznik][s.y][s.x+1]==0){
                        odleglosci[wskaznik][s.y][s.x+1]=odleglosci[s.z][s.y][s.x+1];
                        visited[wskaznik][s.y][s.x+1]=1;
                        kolejka.push({s.x+1,s.y,wskaznik});
                    }
                    wskaznik++;
                }
            }
        }
        if(s.y-1>=1 && wejscie[s.z][s.y-1][s.x]!='X' && visited[s.z][s.y-1][s.x]==0){
            odleglosci[s.z][s.y-1][s.x]=odleglosci[s.z][s.y][s.x]+1;
            visited[s.z][s.y-1][s.x]=1;
            kolejka.push({s.x,s.y-1,s.z});
            if(windy[s.z][s.y-1][s.x]!=0){
                int wejscie_do_windy=windy[s.z][s.y-1][s.x];
                int wskaznik=s.z-1;
                while(wskaznik>=1){
                    if(windy[wskaznik][s.y-1][s.x]==wejscie_do_windy && wejscie[wskaznik][s.y-1][s.x]!='X' && visited[wskaznik][s.y-1][s.x]==0){
                        odleglosci[wskaznik][s.y-1][s.x]=odleglosci[s.z][s.y-1][s.x];
                        visited[wskaznik][s.y-1][s.x]=1;
                        kolejka.push({s.x,s.y-1,wskaznik});
                    }
                    wskaznik--;
                }

                wskaznik=s.z+1;
                while(wskaznik<=z){
                    if(windy[wskaznik][s.y-1][s.x]==wejscie_do_windy && wejscie[wskaznik][s.y-1][s.x]!='X'&& visited[wskaznik][s.y-1][s.x]==0){
                        odleglosci[wskaznik][s.y-1][s.x]=odleglosci[s.z][s.y-1][s.x];
                        visited[wskaznik][s.y-1][s.x]=1;
                        kolejka.push({s.x,s.y-1,wskaznik});
                    }
                    wskaznik++;
                }
            }
        }
        if(s.y+1<=y && wejscie[s.z][s.y+1][s.x]!='X' && visited[s.z][s.y+1][s.x]==0){
            odleglosci[s.z][s.y+1][s.x]=odleglosci[s.z][s.y][s.x]+1;
            visited[s.z][s.y+1][s.x]=1;
            kolejka.push({s.x,s.y+1,s.z});
            if(windy[s.z][s.y+1][s.x]!=0){
                int wejscie_do_windy=windy[s.z][s.y+1][s.x];
                int wskaznik=s.z-1;
                while(wskaznik>=1){
                    if(windy[wskaznik][s.y+1][s.x]==wejscie_do_windy && wejscie[wskaznik][s.y+1][s.x]!='X' && visited[wskaznik][s.y+1][s.x]==0){
                        odleglosci[wskaznik][s.y+1][s.x]=odleglosci[s.z][s.y+1][s.x];
                        visited[wskaznik][s.y+1][s.x]=1;
                        kolejka.push({s.x,s.y+1,wskaznik});
                    }
                    wskaznik--;
                }

                wskaznik=s.z+1;
                while(wskaznik<=z){
                    if(windy[wskaznik][s.y+1][s.x]==wejscie_do_windy && wejscie[wskaznik][s.y+1][s.x]!='X'&& visited[wskaznik][s.y+1][s.x]==0){
                        odleglosci[wskaznik][s.y+1][s.x]=odleglosci[s.z][s.y+1][s.x];
                        visited[wskaznik][s.y+1][s.x]=1;
                        kolejka.push({s.x,s.y+1,wskaznik});
                    }
                    wskaznik++;
                }
            }
        }
        
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>x>>y>>z;

    windy.resize(z+9,vector<vector<int>> (y+9,vector<int> (x+9,0)));
    wejscie.resize(z+9,vector<vector<char>> (y+9,vector<char> (x+9,0)));
    visited.resize(z+9,vector<vector<bool>> (y+9,vector<bool> (x+9,0)));
    odleglosci.resize(z+9,vector<vector<long long int>> (y+9,vector<long long int> (x+9,-1)));

    for(int i=1;i<=z;i++){
        for(int j=y;j>=1;j--){
            for(int l=1;l<=x;l++){
                cin>>wejscie[i][j][l];
            }
        }
    }

    /*cout<<endl;
    for(int i=1;i<=z;i++){
        for(int j=1;j<=y;j++){
            for(int l=1;l<=x;l++){
                cout<<wejscie[i][j][l];
            }cout<<endl;
        }cout<<endl<<endl;
    }*/

    int q,nr_windy=1;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        for(int j=c;j<=d;j++){
            if(wejscie[j][b][a]!='X'){
                windy[j][b][a]=nr_windy;
            }
        }
        nr_windy++;
    }

    /*cout<<endl;
    for(int i=1;i<=z;i++){
        for(int j=1;j<=y;j++){
            for(int l=1;l<=x;l++){
                cout<<windy[i][j][l];
            }cout<<endl;
        }cout<<endl<<endl;
    }*/

    int e,f,g;
    cin>>e>>f>>g;
    punkt dziobak;
    dziobak.x=e; dziobak.y=f; dziobak.z=g;

    cin>>e>>f>>g;
    punkt dundersztyc;
    dundersztyc.x=e; dundersztyc.y=f; dundersztyc.z=g;

    bfs(dziobak);
    cout<<odleglosci[dundersztyc.z][dundersztyc.y][dundersztyc.x];

    return 0;
}
 