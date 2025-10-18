//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> g;
vector<int> rozmiar_poddrzew;
vector<bool> uzyte;
vector<char> rangi;

void oblicz_poddrzewa(int s,int p)
{
    rozmiar_poddrzew[s]=1;
    for(int v :g[s])
    {
        if(v!=p && uzyte[v]==0)
        {
            oblicz_poddrzewa(v,s);
            rozmiar_poddrzew[s]=rozmiar_poddrzew[s]+rozmiar_poddrzew[v];
        }
    }
}

int findCent(int w,int parent,int n)
{
    for(int v : g[w])
    {
        if(uzyte[v]==0 && v!=parent)
        {
             if(rozmiar_poddrzew[v]>n/2)
             {
                return findCent(v,w,n);
             }
        }
    }
    return w;
}

void decompose(int w,char litera)
{
    oblicz_poddrzewa(w,-1);
    int c=findCent(w,-1,rozmiar_poddrzew[w]);
    uzyte[c]=1;
    rangi[c]=litera;
    for(int v : g[c])
    {
        if(!uzyte[v])
        {
            decompose(v,litera+1);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;

    g.resize(n+1);
    uzyte.resize(n+1,0);
    rangi.resize(n+1);
    rozmiar_poddrzew.resize(n+1);

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    decompose(1,'A');

    for(int i=1;i<=n;i++)
    {
        cout<<rangi[i];
    }
    return 0;
}