#include<bits/stdc++.h>
using namespace std;

double dist[109][109];
vector<pair<pair<int,int>,int>> graf;
const int minimum=-1000009;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,ctr=37,dziala=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        pair<pair<int,int>,int> a;
        cin>>a.first.first>>a.first.second>>a.second;
        graf.push_back(a);
    }
    double poczatek=0,koniec=1e6,mid;
    while(ctr>0)
    {
        //cout<<ctr<<" ";
        //cout<<poczatek<<" "<<mid<<" "<<koniec<<endl;
        mid=(poczatek+koniec)/2;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=minimum;
            }
        }
        for(int i=0;i<graf.size();i++)
        {
          dist[graf[i].first.first][graf[i].first.second]=graf[i].second-mid;
        }
        //cout<<"lol"<<" ";
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    dist[i][j]=max(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        dziala=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j]+dist[j][i]>=0.0)
                {
                    dziala=1;
                }
            }
        }
        if(dziala==1)
        {
            poczatek=mid;
        }
        else
        {
            koniec=mid;
        }
        ctr--;
    }
    cout<<fixed<<setprecision(4)<<poczatek;

    return 0;
}