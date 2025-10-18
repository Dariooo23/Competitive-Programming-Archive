#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graf;
vector<long double> morale;
vector<long double>rozmiar;
long double ilpunktow=1;
int punkty(int punkt,int parent)
{
    if(graf[punkt].empty())
    {
        rozmiar[punkt]=1;
        return rozmiar[punkt];
    }
    for(int v : graf[punkt])
    {
        if(v!=parent)
        {
            rozmiar[punkt]=rozmiar[punkt]+punkty(v,punkt);
        }
    }
    rozmiar[punkt]++;
    return rozmiar[punkt];
}

long double DFS(int punkt,int rodzic)
{
    for(int v : graf[punkt])
    {
        if(v!=rodzic)
        {
          morale[punkt]=max(DFS(v,punkt),morale[punkt]);
        }

    }
      if(graf[punkt].empty())
      {
          morale[punkt]=1;
      }
      return min(morale[punkt],(rozmiar[punkt])/(rozmiar[rodzic]-1));

}

int main()
{
    std::ios_base::sync_with_stdio(0);
    long double wynik=0;
    int pracownicy,buntownicy;
    cin>>pracownicy>>buntownicy;
    graf.resize(pracownicy+2);
    morale.resize(pracownicy+2);
    rozmiar.resize(pracownicy+2);
    for(int i=2;i<=pracownicy;i++)
    {
        int a;
        cin>>a;
        graf[a].push_back(i);
    }
    punkty(1,0);
    DFS(1,0);
   /* for(int i=1;i<=pracownicy;i++)
    {
        cout<<rozmiar[i]<<endl;
    }*/

    for(int i=1;i<=pracownicy;i++)
    {
        if(rozmiar[i]>buntownicy)
        {
            wynik=max(wynik,morale[i]);
        }
    }
    cout<<fixed<<setprecision(10)<<wynik;
    return 0;
}