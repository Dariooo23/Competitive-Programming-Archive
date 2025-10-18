//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g1,rg1,g2;
vector<int> stopnie;
vector<int> wynik;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;
    
    g1.resize(n+1);
    g2.resize(n+1);
    rg1.resize(n+1);
    wynik.resize(n+1);
    stopnie.resize(n+1);

    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a==i || b==i)
        {
            cout<<"NIE";
            return 0;
        }
        g1[i].push_back(a);
        g1[i].push_back(b);
        rg1[b].push_back(i);
        rg1[a].push_back(i);
    }


    for(int i=1;i<=n;i++)
    {
        if(g1[g1[i][0]][0]==i || g1[g1[i][1]][0]==i || g1[g1[i][0]][1]==i || g1[g1[i][1]][1]==i)
        {
            cout<<"NIE";
            return 0;
        }
    }

    set<pair<int,int>> nowe_krawedzie;
    for(int i=1;i<=n;i++)
    {
        nowe_krawedzie.insert({min(i,g1[i][0]),max(i,g1[i][0])});
        nowe_krawedzie.insert({min(i,g1[i][1]),max(i,g1[i][1])});
        for(const int &v : rg1[i])
        {
            nowe_krawedzie.insert({min(i,v),max(i,v)});
            nowe_krawedzie.insert({min(v,g1[i][0]),max(v,g1[i][0])});
            nowe_krawedzie.insert({min(v,g1[i][1]),max(v,g1[i][1])});
        }
    }


    for(const auto &a : nowe_krawedzie)
    {
        g2[a.first].push_back(a.second);
        g2[a.second].push_back(a.first);
        stopnie[a.first]++;
        stopnie[a.second]++;
    }

    stack<int> kolejnosc;
    queue<int> kolejka;

    for(int i=1;i<=n;i++)
    {
        if(stopnie[i]<=12)
        {
            kolejka.push(i);
        }
    }

    while(!kolejka.empty())
    {
        int s=kolejka.front();
        kolejka.pop();
        for(const int &v : g2[s])
        {
            stopnie[v]--;
            if(stopnie[v]==12)
            {
                kolejka.push(v);
            }
        }
        kolejnosc.push(s);
    }

    vector<bool> kolory;
    while(!kolejnosc.empty())
    {
        kolory.resize(14,0);
        int s=kolejnosc.top();
        kolejnosc.pop();
        for(const int &v : g2[s])
        {
            kolory[wynik[v]]=1;
        }
        for(int i=1;i<=13;i++)
        {
            if(kolory[i]==0)
            {
                wynik[s]=i;
            }
        }
        kolory.clear();
    }

    cout<<"TAK"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<wynik[i]<<" ";
    }

    return 0;
}
 