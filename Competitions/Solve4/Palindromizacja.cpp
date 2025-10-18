//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int,int> PII;

vector<int> prefsuf;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string slowo, odwrslowo,tekst="";
    int dlugosc;


    cin>>slowo;
    dlugosc=slowo.size();
    odwrslowo=slowo;
    reverse(odwrslowo.begin(),odwrslowo.end());
    tekst=odwrslowo+"#"+slowo;


    prefsuf.resize(tekst.size());
    prefsuf[0]=0;
    prefsuf[1]=0;
    for(int i=2;i<tekst.size();i++)
    {
        int prefiks=prefsuf[i-1];
        while (prefiks>0 && tekst[prefiks+1]!=tekst[i])
        {
            prefiks=prefsuf[prefiks];
        }
        if (tekst[prefiks+1]==tekst[i])
        {
            prefiks++;
        }
        prefsuf[i]=prefiks;
    }

    cout<<dlugosc-prefsuf[2*dlugosc]-1;


    return 0;
}