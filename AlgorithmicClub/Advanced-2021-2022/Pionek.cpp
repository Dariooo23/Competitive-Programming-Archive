//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct wektor
{
    long long int x,y;
};

long long int iloczyn_wektorowy(const wektor &a, const wektor &b)
{
    if (a.x*b.y - b.x*a.y>0)
    {
        return 1;
    }
    if (a.x*b.y - b.x*a.y<0)
    {
        return -1;
    }
    return 0;
}

bool cmp(const wektor &a, const wektor &b)
{
    if(a.x<0 && b.x>0)
    {
        return 1;
    }
    if(a.x>0 && b.x<0)
    {
        return 0;
    }
    if(iloczyn_wektorowy(a,b)==0)
    {
        return a.y<b.y;
    }
    else
    {
        return iloczyn_wektorowy(a,b)<0;
    }
}



long long int odleglosc(long long int x,long long int y)
{
    return (x*x)+(y*y);
}
vector<wektor> wektory;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,wynik=0;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        long long int x,y;
        cin>>x>>y;
        wektory.push_back({x,y});
    }

    sort(wektory.begin(),wektory.end(),cmp);


    long long int poczatek=0,koniec=0,sumay=0,sumax=0;
    wektor wspolrzedne={0,0};

    for(int i=0;i<wektory.size();i++)
    {
        wynik=max(wynik,odleglosc(wektory[i].x,wektory[i].y));
        sumax=sumax+wektory[i].x;
        sumay=sumay+wektory[i].y;
    }
    wynik=max(wynik,odleglosc(sumax,sumay));
    
    while(koniec<wektory.size()*2)
    { 
       if(odleglosc(wspolrzedne.x+wektory[poczatek%wektory.size()].x,wspolrzedne.y+wektory[poczatek%wektory.size()].y)
          >=odleglosc(wspolrzedne.x,wspolrzedne.y) && ((poczatek-koniec+1)<=wektory.size()))
          {
            wspolrzedne.x=wspolrzedne.x+wektory[poczatek%wektory.size()].x;
            wspolrzedne.y=wspolrzedne.y+wektory[poczatek%wektory.size()].y;
            poczatek=poczatek+1;
          }
          else
          {
            wspolrzedne.x=wspolrzedne.x-wektory[koniec%wektory.size()].x;
            wspolrzedne.y=wspolrzedne.y-wektory[koniec%wektory.size()].y;
            koniec=koniec+1;
          }
          wynik=max(wynik,odleglosc(wspolrzedne.x,wspolrzedne.y));
    }

    

    cout<<wynik;
    return 0;
}