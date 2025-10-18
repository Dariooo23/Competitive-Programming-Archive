//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<vector<int>> g(N); //Graf skierowany
vector<int> topSort; //Sortowanie Topologiczne
vector<bool> visited(N); //Tablica odwiedzin do dfs1

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
    }

    //Tworzenie sortowania topologicznego czyli takiego w którym każdy punkt znajduję się w porządku przed dziećmi
    //Sortowania topologicznego nie da się więc stworzyć w grafach cyklicznych
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs1(i);
        }
    }

    cout<<"Sortowanie topologiczne dla tego grafu to "<<endl;
    for(int i=n-1;i>=0;i--)
    {
        cout<<topSort[i]<<" ";
    }
    return 0;
}