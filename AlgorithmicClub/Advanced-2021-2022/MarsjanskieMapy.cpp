//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int,int> PII;

struct edge{
int x,y1,y2,znak;
};

int wynik=0;
int maks=30000;
int podstawa=1<<20;
vector<edge>  krawedzie; 
vector<int> drzewo(podstawa*2);
vector<int> suma(podstawa*2);

bool comp(const edge & a ,const edge & b)
{
    if(a.x==b.x)
    {
        return a.znak>b.znak;
    }
    else
    {
        return a.x<b.x;
    }
}

void popraw(int rodzic, int y1, int y2)
{
    if(drzewo[rodzic]>0)
    {
        suma[rodzic]=y2-y1+1;
    }
    else
    {
        suma[rodzic]=0;
        if(y1<y2)
        {
            suma[rodzic]=suma[rodzic*2]+suma[rodzic*2+1];
        }
    }
}

void zmien(int rodzic,int y1,int y2,int lewo,int prawo,int znak)
{
    if(y1<=lewo && y2>=prawo)
    {
        drzewo[rodzic]=drzewo[rodzic]+znak;
    }
    else
    {
        int mid=(lewo+prawo)/2;
        if(y1<=mid)
        {
            zmien(rodzic*2,y1,y2,lewo,mid,znak);
        }
        if(y2>mid)
        {
            zmien(rodzic*2+1,y1,y2,mid+1,prawo,znak);
        }
    }
    popraw(rodzic,lewo,prawo);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n,ostatni=0,x1,x2,y1,y2,znak;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        krawedzie.push_back({x1,y1,y2,1});
        krawedzie.push_back({x2,y1,y2,-1});
    }
    
    sort(krawedzie.begin(),krawedzie.end(),comp);

    for(int i=0;i<krawedzie.size();i++)
    {
        x1=krawedzie[i].x;
        y1=krawedzie[i].y1;
        y2=krawedzie[i].y2;
        znak=krawedzie[i].znak;
        wynik=wynik+suma[1]*(x1-ostatni);
        ostatni=x1;

        zmien(1,y1,y2-1,0,podstawa,znak);
    }

    cout<<wynik;
    return 0;
}