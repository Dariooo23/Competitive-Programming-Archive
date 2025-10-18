//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<vector<int>> przodkowie;
vector<long long int> glebokosc;

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

long long int odleglosc(int a,int b)
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

    g.resize(n+9);
    glebokosc.resize(n+9);
    przodkowie.resize(n+9,vector<int> (21));

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    glebokosc[0]=0;
    ojcowie(1,1);
    stworz_przodkow(n);
   
    int m,punkt1,punkt2;
    long long int wynik=0;

    cin>>m>>punkt1;

    while(m>1)
    {
        cin>>punkt2;

        wynik=wynik+odleglosc(punkt1,punkt2);
        punkt1=punkt2;
        m--;
    }

    cout<<wynik;

    return 0;
}
 