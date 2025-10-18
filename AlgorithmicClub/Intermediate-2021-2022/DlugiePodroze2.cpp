#include <bits/stdc++.h>

using namespace std;

const int maxx = 1e9+7;
int dist[400][400];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q; cin >> n >> m >> q;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i != j)
                dist[i][j] = maxx;
        }
    }

    for(int i=1;i<=m;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
    }

     for(int k=1;k<=n;k++)
         for(int i=1;i<=n;i++)
             for(int j=1;j<=n;j++)
                 dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    long long out;
    bool flag;
    for(int i=0;i<q;i++)
    {
        out = 0;
        flag = true;
        int k; cin >> k;
        int a; cin >> a;
        int poprzedni = a;
        for(int j=1;j<k;j++)
        {
            cin >> a;
            out += (long long)dist[poprzedni][a];
            if(dist[poprzedni][a] == maxx)
            {
                out = -1;
                flag = false;
            }

            poprzedni = a;
        }

        if(flag)
            cout << out << endl;
        else
            cout << -1 << endl;
    }


    return 0;
}