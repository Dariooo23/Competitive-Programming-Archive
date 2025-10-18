//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<vector<int>> g(N); //Graf skierowany
vector<vector<int>> gT(N); //Odwrócony graf skierowany
vector<vector<int>> dag(N); //Graf Silnie Spójnych Składowych
vector<int> topSort; //Sortowanie Topologiczne
vector<int> nrSCC(N,-1); //Tablica mówiąca do jakiej silnie spójnej składowej należy dany punkt
vector<bool> visited(N); //Tablica odwiedzin do dfs1
vector<int> visited2(N); //Tablica odwiedzin do dfs2 aby zniwelować powtarzanie
                         //się numerów silnie spójnych składowych w ich grafie
vector<int> rozmiar; //Tablica zapamiętująca rozmiar i-tej silnie spójnej składowej na indeksie i-1
int ilosc;


void dfs1(int s)
{
    visited[s]=1;
    for(int v : g[s])
    {
        if(!visited[v])
        {
            dfs1(v);
        }
    }
    //Sortowanie topologiczne tworzy się za pomocą zwyczajnego dfs'a wrzucając wierzchołki w kolejności postorder
    topSort.push_back(s);
}

void dfs2(int s, int nr)
 {
    //Zwiększenie ilości czyli rozmiaru aktualnie tworzonej silnie spójnej składowej
    ilosc++;

    //Przypisanie aktualnie sprawdzanemu punktowi numeru silnie spójnej składowej do której od teraz należy
    nrSCC[s]=nr;

    //Sprawdzanie następnych punktów w odwróconym grafie
    for(int v : gT[s])
    {
        //Jeżeli punkt do teraz przeglądając sortowanie topologiczne nie został odwiedzony
        //To oznacza że będzie należał do silnie spójnej składowej o numerze nr
        if(nrSCC[v]==-1)
        {
            dfs2(v,nr);
        }
        else
        {
            //Jeżeli punkt został już wcześniej odwiedzony a istnieje połączenie do niego w odwróconym grafie
            //To oznacza że z silnie spójnej składowej w której ten punkt się znajduje da się dojść do tej
            //Która jest aktualnie tworzona

            //Ustawiamy w visited2 na indeksie o numerze tej silni spójnej składowej z której połączenie istnieje
            //Do dopiero tworzonej silnie spójnej składowej numer tej tworzonej aby zapobiec powtórzenią się tej samej
            //Silnie spójnej składowej w grafie silnie spójnie składowych jeżeli byłoby więcej niż jedno połaczenie między nimi
            if(nrSCC[v]!=nr && visited2[nrSCC[v]]<nr)
            {
                visited2[nrSCC[v]]=nr;
                dag[nrSCC[v]].push_back(nr);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,a,b;
    cin >>n>>m;

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        //Wczytanie Grafu
        g[a].push_back(b);
        //Tworzenie grafu odwróconego
        gT[b].push_back(a);
    }

    //Tworzenie ułomnego sortowania topologicznego
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs1(i);
        }
    }

    //Tworzenie silnie spójnych składowych na podstawie sortowania topologicznego
    int nr=0;
    for(int i=1;i<=n;i++)
    {
        ilosc=0;
        int v = topSort.back();
        topSort.pop_back();
        if(nrSCC[v] == -1)
        {
            nr++;
            dfs2(v,nr);
            rozmiar.push_back(ilosc);
        }

    }

    for(int i=1;i<=n;i++)
    {
        cout<<"Silnie Spojna Skladowa o numerze "<<i<<" laczy sie z silnie spojnymi skladowymi o numerach: ";
        for(int j=0;j<dag[i].size();j++)
        {
            cout<<dag[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}