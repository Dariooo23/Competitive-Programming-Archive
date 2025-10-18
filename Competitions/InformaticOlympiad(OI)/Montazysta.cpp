//Karol Dziekan

#include <bits/stdc++.h>

using namespace std;

struct film
{
    long long int  nr;
    long long int  czas;
    long long int  koniec;
};

vector<film> tab;
vector<film> tab2;
vector<film> filmy;

bool comp(film a,film b)
{
    if(a.koniec==b.koniec)
    {
        if(a.czas==b.czas)
        {
             return a.nr<b.nr;
        }
        else
        {
             return a.czas<b.czas;
        }
    }
    else
    {

            return a.koniec<b.koniec;

    }
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int  ilosc,czas=0,iloscf=0;
    cin>>ilosc;
    priority_queue <pair<int,int>> kolejka;

    for(int i=0;i<ilosc;i++)
    {
       int a,b;
       cin>>a>>b;
       tab.push_back({i+1,a,b});
       tab2.push_back({i+1,a,b});

    }

    sort(tab.begin(),tab.end(),comp);


    for(int i=0;i<ilosc;i++)
    {
      if(tab[i].czas+czas<=tab[i].koniec)
      {
       iloscf++;
       czas=czas+tab[i].czas;
       kolejka.push(make_pair(tab[i].czas,tab[i].nr));
      }
      else
      {
          if(!kolejka.empty() && tab[i].czas<=kolejka.top().first&&tab[i].czas+czas-kolejka.top().first<=tab[i].koniec)
          {
              czas=czas-kolejka.top().first;
              czas=czas+tab[i].czas;
              kolejka.pop();
              kolejka.push(make_pair(tab[i].czas,tab[i].nr));
          }
      }
    }
    long long int j=0,czas1=1;


    while(!kolejka.empty())
    {
       int d,e,f;
       d=kolejka.top().second;
       e=kolejka.top().first;
       f=tab2[kolejka.top().second-1].koniec;
       filmy.push_back({d,e,f});
       kolejka.pop();
       j++;
    }
    sort(filmy.begin(),filmy.end(),comp);
    cout<<iloscf<<endl;
    for(int i=0;i<j;i++)
    {
        cout<<filmy[i].nr<<" "<<czas1<<endl;
        czas1=czas1+filmy[i].czas;
    }


    return 0;
}