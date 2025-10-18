#include <iostream>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int pierwsza,ilosc_kart,zmiany;
    char ruch;
    cin>>ilosc_kart>>zmiany;
    queue<int>karty;
    pierwsza=1;
    for (int i=2;i<=ilosc_kart;i++)
    {
        karty.push(i);
    }
    for (int i=0;i<zmiany;i++)
    {
        cin>>ruch;
        if(ruch=='A')
        {
            karty.push(pierwsza);
            pierwsza=karty.front();
            karty.pop();
        }
        if(ruch=='B')
        {
            int x=karty.front();
            karty.push(x);
            karty.pop();
        }
    }
    cout<<pierwsza;
    return 0;
}