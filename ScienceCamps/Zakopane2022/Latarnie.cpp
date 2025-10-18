//Karol Dziekan
#include <bits/stdc++.h>
#define odleglosc(a,b) glebokosc[a]+glebokosc[b]-2*glebokosc[lca(a,b)]
using namespace std;

int n,m;
vector<vector<int>> g;
vector<vector<int>> przodkowie;
vector<int> glebokosc;
vector<int> latarnie;
vector<int> odleglosc;

void bfs()
{
    vector<bool> visited;
    odleglosc.clear();
    odleglosc.resize(n+1);
    visited.clear();
    visited.resize(n+1);
    queue<int> kolejka;
    for(int i=0;i<latarnie.size();i++)
    {
            kolejka.push(latarnie[i]);
            visited[latarnie[i]]=1;
            odleglosc[latarnie[i]]=0;

    }    
    while(!kolejka.empty())
    {
        int s=kolejka.front();
        kolejka.pop();
        for(const int &v:g[s])
        {
            if(visited[v]==0)
            {
                visited[v]=1;
                odleglosc[v]=odleglosc[s]+1;
                kolejka.push(v);
            }
        }
    }

}

void ojcowie(int s,int p)
{
    przodkowie[s][0]=p;
    glebokosc[s]=glebokosc[p]+1;
    for(const int &v:g[s])
    {
        if(v!=p)
        {
            ojcowie(v,s);
        }
    }
}

void stworz_przodkow(int n)
{
    for(int k=1;k<=20;++k)
    {
        for(int x=1;x<=n;++x)
        {
            przodkowie[x][k]=przodkowie[przodkowie[x][k-1]][k-1];
        }
    }
}

int lca(int a,int b)
{
    if(glebokosc[a]>glebokosc[b])
    {
        swap(a,b);
    }
    for(int k=20;k>=0;--k)
    {
        if(glebokosc[przodkowie[b][k]]>=glebokosc[a])
        {
            b=przodkowie[b][k];
        }
    }
    if(a==b)
    {
        return a;
    }
    for(int k=20;k>=0;--k)
    {
        if(przodkowie[a][k]!=przodkowie[b][k])
        {
            a=przodkowie[a][k];
            b=przodkowie[b][k];
        }
    }
    return przodkowie[a][0];
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>m;

    g.resize(n+1);
    glebokosc.resize(n+1);
    przodkowie.resize(n+1,vector<int> (21));

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    glebokosc[0]=0;
    ojcowie(1,0);
    stworz_przodkow(n);

    int aktualizacje=0,przejrzyj=0;
    latarnie.push_back(1);
    bfs();


    for(int i=0;i<m;i++)
    {
        int a,b,wynik=0;
        cin>>a>>b;
        if(a==1)
        {
            aktualizacje++;
            latarnie.push_back(b);
            if(aktualizacje*aktualizacje>=m)
            {
                aktualizacje=0;
                przejrzyj=latarnie.size();
                bfs();
            }
        }
        else
        {
            wynik=odleglosc[b];
            for(int i=przejrzyj;i<latarnie.size();i++)
            {
                wynik=min(wynik,odleglosc(b,latarnie[i]));
            }
            cout<<wynik<<'\n';
        }
    }
    return 0;
}
 