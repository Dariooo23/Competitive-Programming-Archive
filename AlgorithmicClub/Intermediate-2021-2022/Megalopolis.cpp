#include <bits/stdc++.h>

using namespace std;

int licz=0;
const int M=1<<20;
vector<int> tab(2*M+1);
vector<int> dep(300000);
vector<vector<int>> g(300000);
vector<pair<int,int>> w(300000);

void update(int a,int b,int c)
{
    a=a+M;
    b=b+M;

    tab[a]=tab[a]+c;
    if(a!=b)
    {
        tab[b]=tab[b]+c;
    }

    while(a/2!=b/2)
    {
        if(a%2==0)
        {
            tab[a+1]=tab[a+1]+c;
        }
        if(b%2==1)
        {
            tab[b-1]=tab[b-1]+c;
        }
        a=a/2;
        b=b/2;
    }
}
int query(int a)
{
    a=a+M;
    int wyn=tab[a];

    while(a!=1)
    {
        a=a/2;
        wyn=wyn+tab[a];
    }
    return wyn;
}

void dfs(int s,int p)
{
    licz++;
    w[s].first=licz;

    for(const int &v : g[s])
    {
        if(v!=p)
        {
            dep[v]=dep[s]+1;
            dfs(v,s);
        }
    }
    w[s].second=licz;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0);

    cin>>m;
    while(m)
    {
        char d;
        int e,f;

        cin>>d;
        if(d=='W')
        {
            cin>>e;
            cout<<dep[e]-query(w[e].first)<<endl;

            m--;
        }
        else
        {
            cin>>e>>f;
            if(dep[e]>dep[f])
            {
                swap(e,f);
            }
            update(w[f].first,w[f].second,1);
        }
    }
    return 0;
}
