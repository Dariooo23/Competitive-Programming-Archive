//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct punkt {
    int x,y,nr;
};

vector<punkt> punkty;
vector<bool> dziala;

bool cmp1(const punkt &a, const punkt &b)
{
    if(a.x==b.x)
    {
        if(a.y==b.y)
        {
            return a.nr<b.nr;
        }
        else
        {
            return a.y>b.y;
        }
    }

    return a.x<b.x;
}

bool cmp2(const punkt &a, const punkt &b)
{
    if(a.x==b.x)
    {
        if(a.y==b.y)
        {
            return a.nr<b.nr;
        }
        else
        {
            return a.y<b.y;
        }
    }

    return a.x<b.x;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int ilosc,rozmiar,wynik=0;
    cin>>ilosc>>rozmiar;

    dziala.resize(ilosc+1,1);
    punkty.clear();

    for(int i=1;i<=ilosc;i++)
    {
        int x1,y1;
        cin>>x1>>y1;
        punkty.push_back({x1,y1,i});
    }
    
    sort(punkty.begin(),punkty.end(),cmp1);

    int najnizszy_y=punkty[0].y;
    dziala[punkty[0].nr]=0;
    for(int i=0;i<punkty.size();i++)
    {
        if(punkty[i].y<=najnizszy_y)
        {
            dziala[punkty[i].nr]=0;
            najnizszy_y=punkty[i].y;
        }
    }

    int najwyzszy_y=punkty[punkty.size()-1].y;
    dziala[punkty[punkty.size()-1].nr]=0;

    for(int i=punkty.size()-1;i>=0;i--)
    {
        if(punkty[i].y>=najwyzszy_y)
        {
            dziala[punkty[i].nr]=0;
            najwyzszy_y=punkty[i].y;
        }

    }

    sort(punkty.begin(),punkty.end(),cmp2);
    najwyzszy_y=punkty[0].y;
    dziala[punkty[0].nr]=0;
    for(int i=0;i<punkty.size();i++)
    {
        if(punkty[i].y>=najwyzszy_y)
        {
            dziala[punkty[i].nr]=0;
            najwyzszy_y=punkty[i].y;
        }
    }

    najnizszy_y=punkty[punkty.size()-1].y;
    dziala[punkty[punkty.size()-1].nr]=0;

    for(int i=punkty.size()-1;i>=0;i--)
    {
        if(punkty[i].y<=najnizszy_y)
        {
            dziala[punkty[i].nr]=0;
        }
        if(punkty[i].y<najnizszy_y)
        {
            najnizszy_y=punkty[i].y;
        }
    }

    

    
    for(int i=1;i<=ilosc;i++)
    {
        if(dziala[i])
        {
            wynik++;
        }
    }

    cout<<wynik;

    return 0;
}
 