//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dist;
const int maks=1e9+7;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //Algorytm liczacy odleglosc kazdego punktu od kazdego w zlozonosci O(n^3)
    int n,m;
    cin>>n>>m;

    dist.resize(n+1,vector<int> (n+1,0));

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i!=j)
            {
                dist[i][j]=maks;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
    }

    for(int k=1;k<=n;k++)
         for(int i=1;i<=n;i++)
             for(int j=1;j<=n;j++)
                 dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
 