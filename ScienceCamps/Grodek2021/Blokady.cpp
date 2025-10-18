#include <bits/stdc++.h>

using namespace std;
int rodzaje[2000009];
int wynik=0;
void DFS(int punkt,vector<int>  W[],int parent)
{
    for(int v : W[punkt] )
    {
             if(v==parent)
             {
                 continue;
             }
            DFS(v,W,punkt);
    }
    if(rodzaje[punkt]==0 && rodzaje[parent]==0)
    {
        rodzaje[punkt]=true;
        rodzaje[parent]=true;
        wynik++;
    }
}
int main()
{

    int m;
    cin>>m;
    vector<int> W[m+1];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        W[a].push_back(b);
        W[b].push_back(a);
    }
    rodzaje[0]=true;
    DFS(1,W,0);
    cout<<wynik;



    return 0;
}