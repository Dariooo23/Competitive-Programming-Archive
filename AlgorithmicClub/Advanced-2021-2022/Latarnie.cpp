//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct pozwys{
    int pozycja,wysokosc;
};

bool cmp(const pozwys &a,const pozwys &b)
{
    if(a.wysokosc==b.wysokosc)
    {
        return a.pozycja<b.pozycja;
    }
    else
    {
        return a.wysokosc>b.wysokosc;
    }
}

vector<pozwys> sortwysokosci;
vector<bool> oswietlone;
vector<int> wysokosci;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int ilosc,wynik=0;
    cin>>ilosc;

    oswietlone.resize(ilosc,0);

    for(int i=0;i<ilosc;i++)
    {
        int wysokosc;
        cin>>wysokosc;

        wysokosci.push_back(wysokosc);
        sortwysokosci.push_back({i,wysokosc});
    }

    sort(sortwysokosci.begin(),sortwysokosci.end(),cmp);

    for(int i=0;i<sortwysokosci.size();i++)
    {
        if(oswietlone[sortwysokosci[i].pozycja]==0)
        {
            wynik++;

            oswietlone[sortwysokosci[i].pozycja]=1;
            int poczatek=sortwysokosci[i].pozycja;
            int prawo=poczatek+1;
            int lewo=poczatek-1;
            int odleglosc=1;

            while(lewo>=0 && wysokosci[poczatek]-wysokosci[lewo]>=odleglosc && oswietlone[lewo]!=1)
            {
                oswietlone[lewo]=1;
                odleglosc++;
                lewo--;
            }

            odleglosc=1;
            while(prawo<ilosc && wysokosci[poczatek]-wysokosci[prawo]>=odleglosc && oswietlone[prawo]!=1)
            {
                oswietlone[prawo]=1;
                odleglosc++;
                prawo++;
            }
        }
    }

    cout<<wynik;
    return 0;
}