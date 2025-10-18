#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

vector<long long int> par, rozmiar;

long long int fin(const int &a)
{
    if (par[a]!=a)
    {
        par[a]=fin(par[a]);
    }
    return par[a];
}
void uni(int &a,int &b)
{
    a=fin(a);
    b=fin(b);
    if (a==b)
    {
        return;
    }
    if (rozmiar[a]<rozmiar[b])
    {
        swap(a, b);
    }

    par[b]=a;
    rozmiar[a]=rozmiar[a]+rozmiar[b];
}

bool comparator(const pair<pair<long long int,long long int>,pair<long long int,long long int>> &a,const pair<pair<long long int,long long int>,pair<long long int,long long int>> &b)
{
    return a.first.first<b.first.first;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int n,m;
    long long wynik=0;
    cin>>n>>m;
    par.resize(n+9);
    rozmiar.resize(n+9);
    for (int i=1;i<=n;i++)
    {
        par[i]=i;
        rozmiar[i]=1;
    }

    priority_queue<pair<long long int,pair<int,int>>, vector<pair<long long int,pair<int,int>>>, greater<pair<long long int,pair<int,int>>>> kolejka;
    for(int i=1;i<=m;i++)
    {
        pair<long long int,pair<int,int>> b;
        cin>>b.second.first>>b.second.second>>b.first;
        kolejka.push(b);
    }
    while(n>1)
    {
        pair<long long int,pair<int,int>> c;
        c=kolejka.top();
        kolejka.pop();
        if(fin(c.second.first)!=fin(c.second.second))
        {
            wynik=wynik+2*rozmiar[par[c.second.first]]*rozmiar[par[c.second.second]]*c.first;
            uni(c.second.first,c.second.second);
            n--;
        }
    }
    cout<<wynik;


    return 0;
}