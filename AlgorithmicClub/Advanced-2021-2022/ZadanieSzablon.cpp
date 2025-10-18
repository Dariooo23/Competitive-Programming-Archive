//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int,int> PII;

vector<int> prefsuf;
vector<int> szablony;
vector<int> pokrycie;

int rozmiar;

void kmp(string tekst)
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

    string tekst;
    cin>>tekst;
    rozmiar=tekst.size();

    prefsuf.resize(rozmiar+1);
    szablony.resize(rozmiar+1);
    pokrycie.resize(rozmiar+1);

    tekst='#'+tekst;
    kmp(tekst);

    for(int i=0;i<=rozmiar;i++)
    {
        szablony[i]=i;
        pokrycie[i]=i;
    }

    for(int i=1;i<=rozmiar;i++)
    {
        int prefiks=prefsuf[i];
        int szablon=szablony[prefiks];
        if(prefiks>0 && pokrycie[szablon]>=i-szablon)
        {
            szablony[i]=szablon;
            pokrycie[szablon]=i;
        }
    }
    
    cout<<szablony[rozmiar];
    return 0;
}