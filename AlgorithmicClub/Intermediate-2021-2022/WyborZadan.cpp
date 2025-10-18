//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> zadania;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    zadania.resize(6,vector<int> (4));

    for(int i=1;i<=n;i++)
    {
        string zadanie;
        cin>>zadanie;

        int wiersz,kolumna;
        wiersz=zadanie[0]-'1'+1;
        kolumna=zadanie[1]-'A'+1;

        zadania[wiersz][kolumna]++;
    }

    bool dziala=1;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(zadania[i][j]<1)
            {
                dziala=0;
            }
        }
    }

    if(zadania[5][1]<2 || zadania[5][2]<2 || zadania[5][3]<2)
    {
        dziala=0;
    }

    if(dziala)
    {
        cout<<"TAK";
    }
    else
    {
        cout<<"NIE";
    }

    return 0;
}
 