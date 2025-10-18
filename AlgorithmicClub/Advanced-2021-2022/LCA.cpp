#include <iostream>

using namespace std;

int main()
{
    cout << "Zrobione" << endl;
    return 0;
}


//KOD W KOMENTARZU

/*
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g(1009);
vector<vector<int>> przodkowie(1009,vector<int>(20));
vector<int> wysokosc(1009);

void dfs(int s, int parent)
{
    przodkowie[s][0]=parent;
    wysokosc[s]=wysokosc[parent]+1;
    for(int v : g[s])
    {
        if(v!=parent)
        {
            dfs(v,s);
        }
    }
}

void przo()
{
    for(int k=1;k<20;k++)
    {
        for(int i=1;i<1009;i++)
        {
            przodkowie[i][k]=przodkowie[przodkowie[i][k-1]][k-1];
        }
    }
}

int LCA(int a,int b)
{
    if(wysokosc[a]<wysokosc[b])
    {
        swap(a,b);
    }

    for(int k=19;k>=0;k--)
    {
        if(wysokosc[przodkowie[a][k]]>=wysokosc[b])
        {
            a=przodkowie[a][k];
        }
    }

    if(a==b)
    {
        return a;
    }

    for(int k=19;k>=0;k--)
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
    ios_base::sync_with_stdio(0);
    int testyg;
    cin>>testyg;


    for(int i=0;i<testyg;i++)
    {

       int n,wynik=0;
    cin>>n;
    for(int j=1;j<=n;j++)
    {
        //cout<<"lol";
        int a;
        cin>>a;
        for(int k=0;k<a;k++)
        {
            int b;
            cin>>b;
            g[j].push_back(b);
            g[b].push_back(j);
        }
    }



    wysokosc[0]=-1;
    dfs(1,0);
    przo();



    int testy;
    cin>>testy;
    cout<<"Case "<<i+1<<":"<<endl;
    for(int j=0;j<testy;j++)
    {
        int lol1,lol2;
        cin>>lol1>>lol2;
        cout<<LCA(lol1,lol2)<<endl;
    }



    for(int i=0;i<g.size();i++)
    {
      g[i].erase(g[i].begin(),g[i].end());
    }
    for(int i=0;i<g.size();i++)
    {
      przodkowie[i].erase(przodkowie[i].begin(),przodkowie[i].end());
    }
    wysokosc.erase(wysokosc.begin(),wysokosc.end());
    //g.clear();
    //przodkowie.clear();
    //wysokosc.clear();
    }

    return 0;
}
*/