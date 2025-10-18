#include <bits/stdc++.h>

using namespace std;

int wynik;
int rodzic[1000009];
int ranking[1000009]={0};
int fin(int x)
{
    if(rodzic[x]==x)
    {
        return x;
    }
    else
    {
    rodzic[x]=fin(rodzic [x]);
    return rodzic[x];
    }

}
void unio(int x, int y)
{
    if(fin(x)!=fin(y))
    {
        wynik--;
    int rodzicX=fin(x);
    int rodzicY=fin(y);
    if(ranking[rodzicX]>ranking[rodzicY])
    {
        rodzic[rodzicY]=rodzicX;
    }
    else
    {
        rodzic[rodzicX]=rodzicY;
    }
    if(ranking[rodzicX]==ranking[rodzicY])
    {
        ranking[rodzicX]++;
    }
    }
}

int main()
{
    int ilosc;
    cin>>ilosc;
    wynik=ilosc;
    for(int i=1;i<=ilosc;i++)
    {
        rodzic[i]=i;
    }
    pair<int,int> wyspy[ilosc+1];
    map<pair<int,int>,int> punkty;
    for(int i=1;i<=ilosc;i++)
    {
        cin>>wyspy[i].first>>wyspy[i].second;
        punkty[{wyspy[i].first,wyspy[i].second}]=i;
    }
    for(int i=1;i<=ilosc;i++)
    {

        for(int jx=wyspy[i].first-10;jx<=wyspy[i].first+10;jx++)
        {
            for(int jy=wyspy[i].second-10;jy<=wyspy[i].second+10;jy++)
        {
            if(punkty.find({jx,jy})!=punkty.end())
                {
                    if(((wyspy[i].first-jx)*(wyspy[i].first-jx)+(wyspy[i].second-jy)*(wyspy[i].second-jy))<=100)
                    {
                                unio(punkty[{jx,jy}],i);
                    }
                }
        }
        }
        {

        }
    }
    cout<<wynik;
    return 0;
}