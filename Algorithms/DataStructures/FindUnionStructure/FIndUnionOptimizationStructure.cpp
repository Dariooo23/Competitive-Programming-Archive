//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> tab;

struct FindUnion
{
    long long int n;
    vector<long long int> parent;
    vector<long long int> rank;

    FindUnion(long long int x)
    {
        n = x;
        parent.resize(n);
        rank.resize(n);
        for(long long int i=0;i<n;i++)
        {
            rank[i]=0;
            parent[i]=i;
        }
        return;
    }

    long long int find(long long int x)
    {
        if(parent[x]==x)
        {
            return x;
        }

        parent[x]=find(parent[x]);

        return parent[x];
    }

    void uni(long long int x,long long int y)
    {
        long long int a=find(x);
        long long int b=find(y);

        if(a==b)
        {
            return;
        }

        if(rank[a]>rank[b]) 
        {
            parent[b]=a;
        }
        else
        {
            parent[a]=b;
        }

        if(rank[a]==rank[b])
        {
            rank[b]++;
        }
        return;
    }

    long long int operator[](long long int x){
        return find(x);
    }
    long long int operator()(long long int x){
        return find(x);
    }
    void operator()(long long int a,long long int b){
        uni(a,b);
        return;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //WCZYTANIE DANYCH
    int n;
    cin>>n;
    tab.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>tab[i];
    }

    //INICJALIZACJA STRUKTURY FIND AND UNION
    FindUnion fau(n+1);

    //ŁĄCZENIE ZBIORÓW
    int laczenia;
    cin>>laczenia;
    while(laczenia--)
    {
        int a,b;
        cin>>a>>b;
        fau.uni(a,b);
    }

    //PYTANIE SIĘ O TO CZY PUNKTY SĄ W JEDNYM ZBIORZE
    int pytania;
    cin>>pytania;
    while(pytania--)
    {
        int a,b;
        cin>>a>>b;
        if(fau.find(a)!=fau.find(b))
        {
            cout<<"PUNKTY SA W OSOBNYCH ZBIORACH"<<'\n';
        }
        else
        {
            cout<<"PUNKTY SA W TYCH SAMYCH ZBIORACH"<<'\n';
        }
    }
    return 0;
}
 
