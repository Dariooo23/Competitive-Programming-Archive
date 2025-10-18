//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int,int> PII;

string tekst;
LL rozmiar,wynik=0;
vector<int> prefsuf;
vector<int> minprefsuf;

void kmp()
{
    prefsuf[0]=0;
    prefsuf[1]=0;
    int prefiks=0;

    for(int i=2;i<=rozmiar;i++)
    {
        while(prefiks>0 && tekst[prefiks+1]!=tekst[i])
        {
            prefiks=prefsuf[prefiks];
        }
        if(tekst[prefiks+1]==tekst[i])
        {
            prefiks++;
        }
        prefsuf[i]=prefiks;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>rozmiar>>tekst;
    tekst='#'+tekst;
    minprefsuf.resize(rozmiar+1);
    prefsuf.resize(rozmiar+1);

    kmp();

    for(int i=0;i<=rozmiar;i++)
    {
        minprefsuf[i]=0;
    }

    for(int i=1;i<=rozmiar;i++)
    {
        if(prefsuf[i]>0)
        {
            if(prefsuf[prefsuf[i]]==0)
            {
                minprefsuf[i]=prefsuf[i];
            }
            else
            {
                minprefsuf[i]=minprefsuf[prefsuf[i]];
            }
            wynik=wynik+i-minprefsuf[i];
        }
    }

    cout<<wynik;
    return 0;
}