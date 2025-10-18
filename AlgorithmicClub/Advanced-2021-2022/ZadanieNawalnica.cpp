#include <bits/stdc++.h>

using namespace std;
long long int n,m;
const long long int maks=2e5+9;
long long int wynik=0,roznica=2e9+9;
vector<pair<long long int,pair<long long int,long long int>>> krawedzie;
vector<long long int> par,ranki,wagi;

    int fin(int a)
    {
        if (par[a]==a)
        {
            return a;
        }
        else
        {
            return fin(par[a]);
        }
    }
    void uni(int a,int b,int waga)
    {
        a=fin(a);
        b=fin(b);
        if (a==b)
        {
            return;
        }
        if(ranki[a]>ranki[b])
        {
            par[b]=a;
            wagi[b]=waga;
        }
        else
        {
            par[a]=b;
            wagi[a]=waga;
        }
        if (ranki[a]==ranki[b])
        {
            ranki[b]++;
        }
        return;
    }
    long long int maksimum(long long int a,long long int b)
    {
    long long int pom=0;
    while(a!=b)
    {
        if(ranki[a]==ranki[b])
        {
            pom=max(pom,wagi[a]);
            pom=max(pom,wagi[b]);
            a=par[a];
            b=par[b];
        }
        else
        {
            if(ranki[a]>ranki[b])
            {
                pom=max(pom,wagi[b]);
                b=par[b];
            }
            else
            {
                pom=max(pom,wagi[a]);
                a=par[a];
            }
        }
    }
    return pom;
    }

bool comparator(const pair<int,pair<int,int>> &a,const pair<int,pair<int,int>> &b)
{
    return a.first<b.first;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin>>n>>m;
    par.resize(n+1);
    ranki.resize(n+1);
    wagi.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        par[i]=i;
        ranki[i]=0;
        wagi[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        pair<long long int,pair<long long int,long long int>> krawedz;
        cin>>krawedz.second.first>>krawedz.second.second>>krawedz.first;
        krawedzie.push_back(krawedz);
    }
    sort(krawedzie.begin(),krawedzie.end(),comparator);

    /*cout<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<krawedzie[i].first<<" ";
    }*/

    for(int i=0;i<m;i++)
    {
        int u=krawedzie[i].second.first;
        int v=krawedzie[i].second.second;
        int waga=krawedzie[i].first;
        if(fin(u)!=fin(v))
        {
            wynik=wynik+waga;
            uni(u,v,waga);
        }
        else
        {
            roznica=min(roznica,waga-maksimum(u,v));
            //cout<<roznica<<" ";
        }
    }
    cout<<wynik+roznica;
    return 0;
}