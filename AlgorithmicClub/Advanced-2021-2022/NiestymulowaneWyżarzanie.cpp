#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> graf;
long long int odleglosc[1000009]={0};
long long int wynik=0,wierzcholki,ilpunktow,odleglosc2=0;
const long long int MAX=1e9+7;

void punkty(int punkt,int parent)
{
    for(int v : graf[punkt])
    {
        if(v!=parent)
        {
            ilpunktow++;
            punkty(v,punkt);
        }

    }
}
void dfs2(int punkt,int parent,long long int odleglosc1)
{
    odleglosc2=(odleglosc2+odleglosc1)%MAX;
    for(int v : graf[punkt])
    {
        if(v!=parent)
        {
            dfs2(v,punkt,odleglosc1+1);
        }

    }
}

void dfs1(int punkt,int parent)
{
    long long int suma=0;
    ilpunktow=1;
    if(punkt!=1)
    {
    punkty(punkt,parent);
    suma=(odleglosc[parent]-ilpunktow+wierzcholki-ilpunktow)%MAX;
    odleglosc[punkt]=suma;
    wynik=(wynik+(suma*suma)%MAX)%MAX;
    //cout<<punkt<<" "<<suma<<endl;
    }
    else
    {
    dfs2(1,0,0);
    odleglosc[punkt]=odleglosc2%MAX;
    wynik=(wynik+(odleglosc2*odleglosc2)%MAX)%MAX;
    //cout<<punkt<<" "<<odleglosc2<<endl;
    }

    for(int v : graf[punkt])
    {
        if(v!=parent)
        {
            dfs1(v,punkt);
        }

    }
}



int main()
{
    cin>>wierzcholki;
    graf.resize(wierzcholki+2);
    for(int i=0;i<wierzcholki-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs1(1,0);
    wynik=wynik%MAX;
    cout<<((wynik*wynik)%MAX);
    return 0;
}
