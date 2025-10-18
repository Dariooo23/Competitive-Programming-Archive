//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g1;
vector<vector<int>> g2;

set<pair<long long int,long long int>> hashe5;

vector<long long int> hashe;
vector<long long int> hashe2;
vector<long long int> hashe3;
vector<long long int> hashe4;

vector<long long int> potegi;
vector<long long int> potegi2;

int n,m,wynik=0;
const long long int pierwsza=29;
const long long int pierwsza2=2137;
const long long int modulo=1e9+696969;

void potegowanie()
{
    potegi[0]=pierwsza;
    potegi2[0]=pierwsza2;

    for(int i=1;i<=n;i++)
    {
        potegi[i]=(potegi[i-1]*pierwsza)%modulo;
    }
    for(int i=1;i<=n;i++)
    {
        potegi2[i]=(potegi2[i-1]*pierwsza2)%modulo;
    }
}

pair<long long int,long long int> dfs2(int s,int p)
{
       for(const int v : g2[s])
       {
           if(v!=p)
           {
               pair<long long int,long long int> wartosc=dfs2(v,s);
               wartosc.first=wartosc.first%modulo;
               wartosc.second=wartosc.second%modulo;
               hashe2[s]=(hashe2[s]+wartosc.first)%modulo;
               hashe4[s]=(hashe4[s]+wartosc.second)%modulo;
           }
       }

    return {hashe2[s],hashe4[s]};
}

pair<long long int,long long int> dfs(int s,int p)
{
       for(const int v : g1[s])
       {
           if(v!=p)
           {
               pair<long long int,long long int> wartosc=dfs(v,s);
               wartosc.first=wartosc.first%modulo;
               wartosc.second=wartosc.second%modulo;
               hashe[s]=(hashe[s]+wartosc.first)%modulo;
               hashe3[s]=(hashe3[s]+wartosc.second)%modulo;
           }
       }

    hashe5.insert({hashe[s],hashe3[s]});
    return {hashe[s],hashe3[s]};
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>m;

    g1.resize(n+9);
    g2.resize(n+9);
    hashe.resize(n+9);
    hashe2.resize(n+9);
    hashe3.resize(n+9);
    hashe4.resize(n+9);
    potegi.resize(n+9);
    potegi2.resize(n+9);

    potegowanie();

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        g1[a].push_back(b);
        g1[b].push_back(a);
    }

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        g2[a].push_back(b);
        g2[b].push_back(a);
    }

    for(int i=1;i<=m;i++)
    {
        hashe[i]=potegi[i];
        hashe2[i]=potegi[i];
        hashe3[i]=potegi2[i];
        hashe4[i]=potegi2[i];
    }

    dfs(n,0);
    dfs2(n,0);

    for(int i=1;i<=n;i++)
    {
        if(hashe5.find({hashe2[i],hashe4[i]})!=hashe5.end())
        {
            hashe5.erase({hashe2[i],hashe4[i]});
            wynik++;
        }
    }

    cout<<wynik;
    return 0;
}
 