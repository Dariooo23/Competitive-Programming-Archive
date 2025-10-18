#include "bits/stdc++.h"
using namespace std;


int obszarzlimitem(vector<vector<int>> &dzialka,vector<vector<int>> &odwiedzone,int i,int wiek,pair<int, int> pozycja)
{
    array<pair<int,int>,4> kierunki;
    kierunki[0].first=1;  kierunki[0].second=0;
    kierunki[1].first=-1; kierunki[1].second=0;
    kierunki[2].first=0;  kierunki[2].second=1;
    kierunki[3].first=0;  kierunki[3].second=-1;

    int wiersz=pozycja.first;
    int kolumna=pozycja.second;
    odwiedzone[wiersz][kolumna]=i;
    int powierzchnia=1;

     for (int j=0;j<4;j++)
    {
        pair<int,int>punktp;
        punktp.first=wiersz+kierunki[j].first;
        punktp.second=kolumna+kierunki[j].second;
        int zasieg=0;
        if((0<=punktp.first&&punktp.first<dzialka.size())&&(0<=punktp.second&&punktp.second<dzialka.size()))
        {
            zasieg=1;
        }
        if (zasieg==0||(odwiedzone[punktp.first][punktp.second]==i)||(dzialka[punktp.first][punktp.second]>wiek))
        {
            continue;
        }
        powierzchnia=powierzchnia+obszarzlimitem(dzialka,odwiedzone,i,wiek,punktp);
    }
    return powierzchnia;
}



bool czyobszarrownyk(vector<vector<int>> &dzialka,vector<vector<int>> &odwiedzone,int i,int najmoz,int k)
{
    int nwier=odwiedzone.size();
    int nkol=odwiedzone.size();

    for (int wiersz=0;wiersz<nwier;wiersz++)
    {
        for (int kolumna=0;kolumna<nkol;kolumna++)
        {
            if ((odwiedzone[wiersz][kolumna]==i)||(dzialka[wiersz][kolumna]>najmoz))
            {
              continue;
            }

            pair<int,int> pozycja;
            pozycja.first=wiersz;
            pozycja.second=kolumna;
            int obszar=obszarzlimitem(dzialka,odwiedzone,i,najmoz,pozycja);

            if (obszar>=k)
            {
                return 1;
            }
        }
    }
    return 0;
}



int szukaniebin(vector<int> wynik,vector<vector<int>> &dzialka,vector<vector<int>> &odwiedzone,int k)
{
    int i=0;
    int start=0;
    int koniec=wynik.size();
    int dlugosc=wynik.size();

    while (dlugosc>0)
    {
        i++;
        int srodek=start+dlugosc/2;
        int pokrywa=czyobszarrownyk(dzialka,odwiedzone,i,wynik[srodek],k);
        if (pokrywa==1)
        {
            koniec=srodek;
        }
        else
        {
            start=srodek+1;
        }
        dlugosc=koniec-start;
    }
    return start;
}



void  solve()
 {
    int a,k;
    cin>>a>>k;
    vector< vector<int> >  dzialka(a, vector<int>(a));
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<a;j++)
        {
        cin>>dzialka[i][j];
        }
    }
    vector<vector<int>> odwiedzone(dzialka.size(),vector<int>(dzialka.size()));
    vector<int> drzewa;


     for (int k=0;k<dzialka.size();k++)
    {
        copy(dzialka[k].begin(), dzialka[k].end(), inserter(drzewa, drzewa.end()));
    }
    sort(drzewa.begin(), drzewa.end());
    drzewa.erase(unique(drzewa.begin(), drzewa.end()), drzewa.end());


    int i=0;
    int lewo=0;
    int prawo=drzewa.size();


    int wynik=szukaniebin(drzewa,dzialka,odwiedzone,k);
    cout<<drzewa[wynik];
}



int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}