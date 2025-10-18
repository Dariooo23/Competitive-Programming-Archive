//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int,int> PII;

int n,q;
vector<vector<int>> graf;
vector<vector<int>> przodkowie;
vector<int> glebokosc;

void ojcowie(int s,int p)
{
    przodkowie[s][0]=p;
    glebokosc[s]=glebokosc[p]+1;
    for(const int &v:graf[s])
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

    cin>>n>>q;
    graf.resize(n+1);
    glebokosc.resize(n+1);
    przodkowie.resize(n+1,vector<int> (21));

    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    glebokosc[0]=0;
    ojcowie(1,0);
    stworz_przodkow(n);

    while(q--)
    {
        int a,b,ostatni=0,wynik1=0,wynik2=0,wynik3=0;
        cin>>a>>b;
        ostatni=lca(a,b);

        wynik1=glebokosc[ostatni]-glebokosc[a];
        if(wynik1<0)
        {
            wynik1=wynik1*-1;
        }
        wynik2=glebokosc[ostatni]-glebokosc[b];
        if(wynik2<0)
        {
            wynik2=wynik2*-1;
        }

        wynik3=wynik2+wynik1;
        cout<<wynik3<<endl;
    }
    return 0;
}