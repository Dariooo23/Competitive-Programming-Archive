//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

//GRAF SKIEROWANY WAŻONY
vector<vector<pair<int,int>>> g;

//ODLEGŁOŚCI OD PUNKTU STARTOWEGO
vector<long long int> dist;


//UWAGA WERSJA DIJKSTRY NA KOLEJCE PRIORYTETOWEJ NIE DZIALA WE WSZYSTKICH PRZYPADKACH
//JEST TO BLAD NIENAPRAWIALNY W ZWIAZKU Z BRAKIEM MOZLIWOSCI USUWANIA PUNKTOW Z NIEAKTUALNYMI DYSTANSAMI Z KOLEJKI
//NIE DA SIE DOKLADNIE OKRESLIC W JAKICH PRZYPADKACH TEN BLAD WYSTEPUJE

//ALGORYTM DIJKSTRY OBLICZAJĄCY ODLEGŁOŚCI MIĘDZY PUNKTEM STARTOWYM A POZOSTAŁYMI PUNKTAMI
void dijkstra(int start)
{
  
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > kolejka;
    kolejka.push({0,start});
    dist[start]=0;

    while (!kolejka.empty()) {
        int punkt=kolejka.top().second;
        kolejka.pop();

        for(pair<int,int> v:g[punkt]){
 
            if (dist[v.first]>dist[punkt]+v.second){
                dist[v.first]=dist[punkt]+v.second;
                kolejka.push({dist[v.first], v.first});
            }
        }
    }
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //WCZYTYWANIE DANYCH 
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    dist.resize(n+1,1e18+9);
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].emplace_back(b,c);
    }

    //DIJKSTRA OBLICZAJĄCA ODLEGŁOŚĆI W GRAFIE WAŻONYM
    int start=1;
    dijkstra(start);


    cout<<"ODLEGLOSCI PUNKTOW OD PUNKTU "<<start<<'\n';
    for(int i=1;i<=n;++i)
    {
        cout<<"PUNKT "<<i<<" JEST ODLEGLY OD PUNKTU STARTOWEGO O "<<dist[i]<<'\n';
    }
    return 0;
}
 