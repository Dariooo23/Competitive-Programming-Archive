#include <bits/stdc++.h>

using namespace std;



vector<vector<pair<int,int>>> g(200009);
vector<vector<int>> przodkowie(200009,vector<int>(20));
vector<vector<int>> minimum(200009,vector<int> (20,200009));
vector<int> wysokosc(200009);



void dfs(int s, int parent)
{
    przodkowie[s][0]=parent;
    wysokosc[s]=wysokosc[parent]+1;
    for(pair<int,int> p : g[s])
    {
        int v=p.first;
        int c=p.second;
        if(v!=parent)
        {
            dfs(v,s);
            minimum[v][0]=c;
        }
    }
}



void przo()
{
    for(int k=1;k<20;k++)
    {
        for(int i=1;i<200009;i++)
        {
            przodkowie[i][k]=przodkowie[przodkowie[i][k-1]][k-1];
            minimum[i][k]=min(minimum[i][k-1],minimum[przodkowie[i][k-1]][k-1]);
        }
    }
}



int LCA(int a,int b)
{
    int wynik=2e9;
    if(wysokosc[a]<wysokosc[b])
    {
        swap(a,b);
    }



    for(int k=19;k>=0 && wysokosc[a]>wysokosc[b];k--)
    {
        if(wysokosc[przodkowie[a][k]]>=wysokosc[b])
        {
            wynik=min(wynik,minimum[a][k]);
            a=przodkowie[a][k];
        }
    }



    if(a==b)
    {
        return wynik;
    }



    for(int k=19;k>=0;k--)
    {
        if(przodkowie[a][k]!=przodkowie[b][k])
        {
            wynik=min(wynik,minimum[a][k]);
            wynik=min(wynik,minimum[b][k]);
            a=przodkowie[a][k];
            b=przodkowie[b][k];
        }
    }

    wynik=min(wynik,minimum[a][0]);
    wynik=min(wynik,minimum[b][0]);
    return wynik;
}



int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }



    wysokosc[0]=-1;
    dfs(1,0);
    przo();



    for(int i=0;i<m;i++)
    {
        int d,e;
        cin>>d>>e;
        cout<<LCA(d,e)<<endl;
    }


    return 0;
}