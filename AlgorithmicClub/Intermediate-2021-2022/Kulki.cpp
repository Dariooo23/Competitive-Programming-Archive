//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int solve(char kolor, string linia1, string linia2)
{
    vector<int> zabierz;
    vector<int> ustaw;

    ustaw.resize(linia1.size(),0);
    zabierz.resize(linia1.size(),0);

    long long int zamiany=0;

    for(int i=0;i<linia1.size();i++)
    {
        if(linia1[i]!=kolor)
        {
            ustaw[i]=1;
            zamiany++;
        }
        if(linia2[i]==kolor)
        {
            zabierz[i]=-1;
        }
    }

    int wstaw=0,wez=0;
    while(wstaw<linia1.size() && wez<linia1.size())
    {
        if(ustaw[wstaw]==1 && zabierz[wez]==-1)
        {
            int odleglosc=wez-wstaw;
            if(odleglosc<0)
            {
                odleglosc=odleglosc*-1;
            }

            zamiany=zamiany+odleglosc;
            wstaw++;
            wez++;
        }
        if(ustaw[wstaw]!=1)
        {
            wstaw++;
        }
        if(zabierz[wez]!=-1)
        {
            wez++;
        }
    }

    return zamiany;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int rozmiar;
    cin>>rozmiar;

    string linia1,linia2;
    cin>>linia1>>linia2;

    cout<<min(solve('B',linia1,linia2),solve('C',linia1,linia2));

    return 0;
}
 