//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

//FindUnion
vector<long long int > par;
vector<long long int > ranki;

struct FindUnion{
    long long int n;
    long long int licz;
    vector<long long int> parent;
    vector<long long int> rank;

    FindUnion(long long int x){
        n = x;
        licz=n;
        parent.resize(n);
        rank.resize(n);
        for(long long int i=0;i<n;i++){
            rank[i]=0;
            parent[i]=i;
        }
        return;
    }

    long long int find(long long int x){
        if(parent[x]==x)return x;

        parent[x]=find(parent[x]);
        return parent[x];
    }

    void onion(long long int x,long long int y){
        long long int a=find(x);
        long long int b=find(y);

        if(a==b)return;

        licz--;

        if(rank[a]>rank[b]) parent[b]=a;
        else parent[a]=b;
        if(rank[a]==rank[b])rank[a]++;
        return;
    }

    long long int operator[](long long int x){
        return find(x);
    }
    long long int operator()(long long int x){
        return find(x);
    }
    void operator()(long long int a,long long int b){
        onion(a,b);
        return;
    }
};

struct krawedz{
    long long int  a,b,waga,zapytanie;
};

//Tablice do zapytan
vector<krawedz> krawedzie;
vector<krawedz> krawedzie2;
vector<krawedz> zapytania;
vector<bool> wyniki;

//Tablice do dfs
vector<vector<long long int >> g;
vector<bool> visited;
vector<long long int > odpalz;

bool cmp(krawedz a,krawedz b)
{
    if(a.waga==b.waga)
    {
        return a.zapytanie<b.zapytanie;
    }
    else
    {
        return a.waga<b.waga;
    }
}

bool dfs(long long int  s,long long int  p)
{
    long long int  res=1;
    for(long long int  v : g[s])
    {
        if(v==p)
        {
            continue;
        }
        if(visited[v])
        {
            res=0;
            continue;
        }
        visited[v]=1;
        if(!dfs(v,s))
        {
            res=0;
        }
    }
    return (bool)res;
}

FindUnion f(200001);

int  main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    long long int  n,m;
    cin>>n>>m;

    krawedzie.resize(m,{0,0,0,0});
    krawedzie2.resize(m,{0,0,0,0});

    for(long long int  i=0;i<m;i++)
    {
        long long int  o,r,c;
        cin>>o>>r>>c;
        krawedz przejscie;

        przejscie.a=o;
        przejscie.b=r;
        przejscie.waga=c;
        przejscie.zapytanie=0;

        krawedzie[i]=przejscie;
    }

    long long int  q;
    cin>>q;
    wyniki.resize(q+1,1);

    for(long long int  i=1;i<=q;i++)
    {
        long long int  e;
        cin>>e;
        for(long long int j=0;j<e;j++)
        {
            long long int f;
            cin>>f;
            f--;
            krawedz przejscie;
            przejscie.a=krawedzie[f].a;
            przejscie.b=krawedzie[f].b;
            przejscie.waga=krawedzie[f].waga;
            przejscie.zapytanie=i;

            zapytania.push_back(przejscie);
        }
    }

    krawedzie2=krawedzie;

    sort(zapytania.begin(),zapytania.end(),cmp);
    sort(krawedzie2.begin(),krawedzie2.end(),cmp);

    /*for(long long int  i=0;i<krawedzie.size();i++)
    {
        cout<<krawedzie[i].a<<" "<<krawedzie[i].b<<" "<<krawedzie[i].waga<<" "<<krawedzie[i].nr<<endl;
    }*/

    long long int  ostatniapozycja=0;

    g.resize(n+9);
    visited.resize(n+9);

    for(long long int  i=0;i<zapytania.size();i++)
    {
        if(i>0 && (zapytania[i-1].zapytanie!=zapytania[i].zapytanie || zapytania[i-1].waga!=zapytania[i].waga))
        {
            for(long long int  v : odpalz)
            {
                if(visited[v])
                {
                    continue;
                }
                    visited[v]=1;
                    if(!dfs(v,0))
                    {
                        wyniki[zapytania[i-1].zapytanie]=0;
                    }
            }

            for(long long int  v : odpalz)
            {
                visited[v]=0;
                g[v].clear();
            }

            odpalz.clear();
        }
       
        if(i>0 && zapytania[i-1].waga!=zapytania[i].waga)
        {
                for(long long int  j=ostatniapozycja;j<krawedzie2.size();j++)
                {
                    if(j>0 &&krawedzie2[j].waga>zapytania[i-1].waga)
                    {
                        ostatniapozycja=j;
                        break;
                    }
                    else
                    {
                        if(f.find(krawedzie2[j].a)!=f.find(krawedzie2[j].b))
                        {
                            f.onion(krawedzie2[j].a,krawedzie2[j].b);
                        }
                    }
                }
        }
            
            long long int a=f(zapytania[i].a);
            long long int b=f(zapytania[i].b);
            //cout<<"PRZERABIAM ZAPYTANIE NR "<<zapytania[i].zapytanie<<" Z KRAWEDZI "<<zapytania[i].a<<" DO KRAWEDZI "<<zapytania[i].b<<" O WADZE "<<zapytania[i].waga<<endl;
            if(a==b)
            {
                //cout<<"NIE DZIALA DLA ZAPYTANIA "<<zapytania[i].zapytanie<<" PONIEWAZ FIND ZGADZA SIE DLA PUNKTOW "<<zapytania[i].a<<" ORAZ "<<zapytania[i].b<<endl;
                wyniki[zapytania[i].zapytanie]=0;
                continue;
            }
            odpalz.push_back(a);
            odpalz.push_back(b);
            g[a].push_back(b);
            g[b].push_back(a);
        

    }

    for(long long int  v : odpalz)
            {
                if(visited[v])
                {
                    continue;
                }
                
                    visited[v]=1;
                    if(!dfs(v,0))
                    {
                        wyniki[zapytania[zapytania.size()-1].zapytanie]=0;
                    }
                
            }

    for(long long int  i=1;i<=q;i++)
    {
        if(wyniki[i]==0)
        {
            cout<<"NIE"<<endl;
        }
        else
        {
            cout<<"TAK"<<endl;
        }
    }
    cout<<endl;
    return 0;
}