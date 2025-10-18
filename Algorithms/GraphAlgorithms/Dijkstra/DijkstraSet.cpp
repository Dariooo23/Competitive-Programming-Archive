//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

//GRAF SKIEROWANY WAŻONY
vector<vector<pair<long long int,long long int>>> g;
//ODLEGŁOŚCI OD PUNKTU STARTOWEGO
vector<long long int> dist;

//ALGORYTM DIJKSTRY Z WYKORZYSTANIEM SET'A
void dijkstra(long long int start){
    //NASZA STRUKTURA SET SORTUJACA PO DYSTANSACH JAKO PIERWSZEJ ZMIENNEJ I NUMERACH PUNKTOW JAKO DRUGIEJ
    set<pair<long long int,long long int>> kolejka;

    //ODLEGLOSC DO PUNKTU STARTOWEGO USTAWIAMY NA 0 I WRZUCAMY NA SET'A
    dist[start]=0;
    kolejka.insert({dist[start],start});

    //POKI W SECIE SIE COS ZNAJDUJE TO PRZEGLADAMY GRAF I POPRAWIAMY ODLEGLOSCI
    while(!kolejka.empty()){
        //BIERZEMY KOLEJNE PUNKTY Z SET'A I JE USUWAMY
        pair<long long int,long long int> wierzcholek=*kolejka.begin();
        kolejka.erase(kolejka.begin());

        //PRZEGLADAMY KAZDEGO SASIADA SPRAWDZANEGO WIERZCHOLKA
        for(const pair<long long int,long long int> &krawedz:g[wierzcholek.second]){
            //JEZELI JESTESMY W STANIE POPRAWIC DYSTANS PRZECHODZAC Z WIERZCHOLKA DO DANEGO PUNKTU TO ZASTEPUJEMY AKTUALNY DYSTANS NOWYM
            if(dist[krawedz.first]>dist[wierzcholek.second]+krawedz.second){
                //ZANIM ZASTAPIMY AKTUALNY DYSTANS NOWYM MUSIMY SPRAWDZIC CZY NA KOLEJCE NIE ZNAJDUJE SIE TEN PUNKT
                //ABY SIE POZBYC JEGO WERSJI Z NIEAKTUALNYM JUZ DYSTANSEM
                if(kolejka.find({dist[krawedz.first],krawedz.first})!=kolejka.end()){
                    kolejka.erase({dist[krawedz.first],krawedz.first});
                }

                //OBLICZAMY NOWY DYSTANS I WRZUCAMY NA SET'A
                dist[krawedz.first]=dist[wierzcholek.second]+krawedz.second;
                kolejka.insert({dist[krawedz.first],krawedz.first});
            }
        }
    }

    return;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //WCZYTYWANIE DANYCH 
    long long int n,m;
    cin>>n>>m;
    g.resize(n+1);
    dist.resize(n+1,1e18);
    for(int i=1;i<=m;++i){
        long long int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }

    //DIJKSTRA OBLICZAJĄCA ODLEGŁOŚĆI W GRAFIE WAŻONYM
    long long int start=1;
    dijkstra(start);


    cout<<"ODLEGLOSCI PUNKTOW OD PUNKTU "<<start<<'\n';
    for(int i=1;i<=n;++i)
    {
        cout<<"PUNKT "<<i<<" JEST ODLEGLY OD PUNKTU STARTOWEGO O "<<dist[i]<<'\n';
    }
    return 0;
}
 