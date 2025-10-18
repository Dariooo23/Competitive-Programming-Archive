//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> par;
vector<int> ranki;
vector<int> tab;

struct Fau
{
    //INICJALIZACJA STRUKTURY FIND AND UNION
    Fau(int n)
    {
        par.resize(n+1);
        ranki.resize(n+1);
        for (int i=1;i<=n;i++)
        {
            par[i]=i;
            ranki[i]=1;
        }
    }

    //FUNKCJA SPRAWDZAJĄCA DO JAKIEGO ZBIORU NALEŻY PUNKT
    int find(int a)
    {
        if(par[a]!=a)
        {
            par[a]=find(par[a]);
        }
        return par[a];
    }

    //FUNKCJA ŁĄCZĄCA DWA ZBIORY
    void uni(int a, int b)
    {
        a=find(a);
        b=find(b);
        if(a!=b)
        {
            if(ranki[a]<ranki[b])
            {
                swap(a,b);
            }
            par[b]=a;
            ranki[a]=ranki[a]+ranki[b];
            ranki[b]=ranki[a];
        }
        
    }
};

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //WCZYTANIE DANYCH
    int n;
    cin>>n;
    tab.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>tab[i];
    }

    //INICJALIZACJA STRUKTURY FIND AND UNION
    Fau fau(n);

    //ŁĄCZENIE ZBIORÓW
    int laczenia;
    cin>>laczenia;
    while(laczenia--)
    {
        int a,b;
        cin>>a>>b;
        fau.uni(a,b);
    }

    //PYTANIE SIĘ O TO CZY PUNKTY SĄ W JEDNYM ZBIORZE
    int pytania;
    cin>>pytania;
    while(pytania--)
    {
        int a,b;
        cin>>a>>b;
        if(fau.find(a)!=fau.find(b))
        {
            cout<<"PUNKTY SA W OSOBNYCH ZBIORACH"<<'\n';
        }
        else
        {
            cout<<"PUNKTY SA W TYCH SAMYCH ZBIORACH"<<'\n';
        }
    }
    return 0;
}
 