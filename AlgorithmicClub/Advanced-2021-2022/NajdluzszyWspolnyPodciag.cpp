#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g(2009);
vector<vector<int>> gT(2009);
vector<int> topSort;
vector<bool> visited(2009);
vector<int> wynik(2009,0);

void dfs1(int s)
{
    visited[s]=true;
    for(int v:g[s])
    {
        if(!visited[v])
        {
            dfs1(v);
        }
    }
    topSort.push_back(s);
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    int n,k,a;
    cin>>n>>k;
    int tab[n+1][k+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            cin>>a;
            tab[i][a]=j;
        }
    }
    for(int i=1;i<=k;i++)
    {

        for(int j=1;j<=k;j++)
        {
            bool flaga=1;
            for(int l=0;l<n;l++)
            {
                if(tab[l][i]>tab[l][j])
                {
                    flaga=0;
                    break;
                }
            }
            if(flaga==1 && i!=j)
            {
                g[i].push_back(j);
                gT[j].push_back(i);
            }
        }
    }
    for(int i=1;i<=k;i++)
    {
        if(!visited[i])
        {
            dfs1(i);
        }
    }
   /* cout<<"TOPSORT"<<endl;
    for(int i=0;i<topSort.size();i++)
    {
        cout<<topSort[i]<<" ";
    }
    cout<<endl;
    cout<<"Zwykly Graf"<<endl;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Odwrocony Graf"<<endl;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<gT[i].size();j++)
        {
            cout<<gT[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=0;i<k;i++)
    {
       for(int j=0;j<gT[topSort[i]].size();j++)
       {
         wynik[gT[topSort[i]][j]]=max(wynik[gT[topSort[i]][j]],wynik[topSort[i]]+1);
       }
    }
    int wynik1=0;
    for(int i=1;i<=k;i++)
    {
        wynik1=max(wynik1,wynik[i]);
    }
    cout<<wynik1+1;
    return 0;
}