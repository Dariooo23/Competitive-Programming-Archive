//Karol Dziekan
#include<bits/stdc++.h>

using namespace std;

const int maks=1e9;
int liczba_banknotow,kwota;

vector<vector<int> > wynik;
vector<int> min_banknotow1;
vector<int> min_banknotow2;
vector<int> nominaly;
vector<int> ilosc;

void wypisz(int banknoty,int suma)
{
    if(banknoty>1)
    {
        wypisz(banknoty-1,suma-wynik[suma][banknoty]*nominaly[banknoty]);
    }
    cout<<wynik[suma][banknoty]<<" ";
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>liczba_banknotow;

    nominaly.resize(liczba_banknotow+9);
    ilosc.resize(liczba_banknotow+9);

    for(int i=1;i<=liczba_banknotow;i++)
    {
        cin>>nominaly[i];
    }
    for(int i=1;i<=liczba_banknotow;i++)
    {
        cin>>ilosc[i];
    }
    cin>>kwota;
    
    wynik.resize(kwota+9,vector<int> (liczba_banknotow+9,0));
    min_banknotow1.resize(kwota+9,maks);
    min_banknotow2.resize(kwota+9);
    min_banknotow1[0]=0;

    for(int i=1;i<=liczba_banknotow;i++)
    {
        deque<int> kolejka;
        for(int mod=0;mod<nominaly[i];mod++)
        {
            kolejka.clear();
            int liczba=0;
            while(mod+liczba*nominaly[i]<=kwota)
            {
                min_banknotow2[liczba]=min_banknotow1[mod+liczba*nominaly[i]]-liczba;
                while(!kolejka.empty() && min_banknotow2[kolejka.back()]>=min_banknotow2[liczba])
                {
                    kolejka.pop_back();
                }
                kolejka.push_back(liczba);
                min_banknotow1[mod+liczba*nominaly[i]]=min_banknotow2[kolejka.front()]+liczba;
                wynik[mod+liczba*nominaly[i]][i]=liczba-kolejka.front();
                if(kolejka.front()==liczba-ilosc[i])
                {
                    kolejka.pop_front();
                }
                liczba++;
            }
        }
    }

    cout<<min_banknotow1[kwota]<<endl;
    wypisz(liczba_banknotow,kwota);

  return 0;
}