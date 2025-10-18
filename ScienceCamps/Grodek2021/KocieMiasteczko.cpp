#include <bits/stdc++.h>

using namespace std;
int visited[10000];
int rodzaje[10000];
void DFS(int punkt,vector<int>  W[])
{
    visited[punkt]=1;
    for(int v : W[punkt] )
    {
        if(rodzaje[v]==rodzaje[punkt])
        {
            cout<<"NIE";
            exit(0);
        }
        else
        {
            if(visited[v]==0)
            {
             if(rodzaje[punkt]==1)
            {
                rodzaje[v]=2;
            }
            else
            {
                rodzaje[v]=1;
            }
            DFS(v,W);
            }

        }

    }
}
int main()
{

    int n,m;
    cin>>m>>n;
    vector<int> W[m+1];
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        W[a].push_back(b);
        W[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
            {
              rodzaje[i]=1;
              DFS(i,W);
            }
    }

    cout<<"TAK";
    return 0;
}