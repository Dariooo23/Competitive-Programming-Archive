//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<vector<int>> przodkowie;
vector<int> glebokosc;

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
    for(int x=1;x<=n;++x)
    {
        for(int k=1;k<=20;++k)
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

int odleglosc(int a,int b)
{
    return glebokosc[a]+glebokosc[b]-2*glebokosc[lca(a,b)];
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    g.resize(n+1);
    glebokosc.resize(n+1);
    przodkowie.resize(n+1,vector<int> (21));

    for(int i=2;i<=n;++i)
    {
        int a;
        cin>>a;

        g[a].push_back(i);
        g[i].push_back(a);
    }

    glebokosc[0]=0;
    ojcowie(1,1);
    stworz_przodkow(n);

    int punkt1=1,punkt2=2,lca1,lca2,wynik=0;

    for(int i=2;i<=n;i++)
    {
        lca1=odleglosc(punkt1,i);
        lca2=odleglosc(punkt2,i);

        if(lca1>=lca2 && lca1>wynik)
        {
            punkt2=i;
            wynik=lca1;
        }
        
        if(lca1<lca2 && lca2>wynik)
        {
            punkt1=i;
            wynik=lca2;
        }

        cout<<wynik<<endl;
    }
    
    return 0;
}
 