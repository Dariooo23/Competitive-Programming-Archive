//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> prefiksy;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m,q;
    cin>>n>>m>>q;

    prefiksy.resize(n+1,vector<int> (m+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char znak;
            cin>>znak;
            if(znak=='#')
            {
                prefiksy[i][j]=1;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            prefiksy[i][j]=prefiksy[i][j]+prefiksy[i][j-1];
        }
    }

    for(int i=0;i<q;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        bool dziala=1;

        for(int j=x1;j<=x2;j++)
        {
            if(prefiksy[j][y2]-prefiksy[j][y1-1])
            {
                dziala=0;
            }
        }
        if(dziala)
        {
            cout<<"TAK"<<endl;
        }
        else
        {
            cout<<"NIE"<<endl;
        }
    }
    return 0;
}
 