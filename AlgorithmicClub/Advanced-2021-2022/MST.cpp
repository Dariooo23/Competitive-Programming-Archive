#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

    vector<int> par, ranki;

    int fin(const int &a)
    {
        if (par[a] != a) par[a] = fin(par[a]);
        return par[a];
    }
    void uni(int &a,int &b)
    {
        a = fin(a);
        b = fin(b);
        if (a == b) return;
        if (ranki[a] < ranki[b]) swap(a, b);
        par[b] = a;
        if (ranki[a] == ranki[b]) ranki[a]++;
    }

bool comparator(const pair<pair<int,int>,pair<int,int>> &a,const pair<pair<int,int>,pair<int,int>> &b)
{
    return a.first.first<b.first.first;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    int n,m;
    pair<int,int> a;
    cin>>n>>m;
    par.resize(n+1);
    ranki.resize(n+1);
    for (int i=1;i<=n;i++)
    {
        par[i]=i;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> kolejka;
    pair<int,int> tab[m+1];
    for(int i=1;i<=m;i++)
    {
        pair<int,int> b;
        cin>>b.first>>b.second;
        tab[i]=b;
        cin>>b.first;
        b.second=i;
        kolejka.push(b);
    }
    while(n>1)
    {
        pair<int,int> c;
        c=kolejka.top();
        kolejka.pop();
        if(fin(tab[c.second].first)!=fin(tab[c.second].second))
        {
            uni(tab[c.second].first,tab[c.second].second);
            cout<<c.second<<" ";
            n--;
        }
    }

    return 0;
}