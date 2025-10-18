//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<pair<int,int>> polaczenia;

long long int dfs(int nie,int s,int p)
{
    long long int rozmiar=0;
    for(const int &v :g[s])
    {
        if(v!=p && v!=nie)
        {
            rozmiar=rozmiar+dfs(nie,v,s);
        }
    }

    return rozmiar+1;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    g.resize(n+1);

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        
        g[a].push_back(b);
        g[b].push_back(a);
        polaczenia.push_back({a,b});
    }

    long long int wynik=0;
    for(int i=0;i<polaczenia.size();i++)
    {
        wynik=max(wynik,dfs(polaczenia[i].second,polaczenia[i].first,0)*dfs(polaczenia[i].first,polaczenia[i].second,0));
    }

    cout<<wynik;

    
    return 0;
}
 