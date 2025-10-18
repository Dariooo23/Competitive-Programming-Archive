//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const long long int modulo=1e9+7;

vector<vector<long long int>> macierz1;
vector<vector<long long int>> macierz2;
vector<vector<long long int>> macierz3;

void szybkie_potegowanie(long long int potega, int rozmiar)
{
    while(potega)
    {
        if(potega%2!=0)
        {
            for(int i=1;i<=rozmiar;i++)
            {
                for(int j=1;j<=rozmiar;j++)
                {
                    macierz3[i][j] = 0;
                }
            }
            for(int i=1;i<=rozmiar;i++)
            {
                for(int j=1;j<=rozmiar;j++)
                {
                    for(int k=1;k<=rozmiar;k++)
                    {
                        macierz3[i][j]=(macierz3[i][j]+macierz2[i][k]*macierz1[k][j])%modulo;
                    }
                }
            }
            macierz2=macierz3;
        }

        for(int i=1;i<=rozmiar;i++)
        {
            for(int j=1;j<=rozmiar;j++)
            {
                macierz3[i][j] = 0;
            }
        }
        for(int i=1;i<=rozmiar;i++)
        {
            for(int j=1;j<=rozmiar;j++)
            {
                for(int k=1;k<=rozmiar;k++)
                {
                    macierz3[i][j]=(macierz3[i][j]+macierz1[i][k]*macierz1[k][j])%modulo;
                }
            }
        }
        macierz1=macierz3;

        potega=potega/2;
    }

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);


    //Podaj rozmiar macierz które chcesz potęgować oraz potęge do której chcesz je podnieść
    int rozmiar,potega;
    cin>>rozmiar>>potega;

    macierz1.resize(rozmiar+1,vector<long long int> (rozmiar+1,0));
    macierz2.resize(rozmiar+1,vector<long long int> (rozmiar+1,0));
    macierz3.resize(rozmiar+1,vector<long long int> (rozmiar+1,0));

    //Jeżeli chcesz potęgować tylko jedną macierz to wprowadź macierz neutralna czyli wypelniona zerami i z jedynkami po przekatnej
    for(int i=1;i<=rozmiar;i++)
    {
        for(int j=1;j<=rozmiar;j++)
        {
            cin>>macierz1[i][j];
        }
    }
    for(int i=1;i<=rozmiar;i++)
    {
        for(int j=1;j<=rozmiar;j++)
        {
            cin>>macierz2[i][j];
        }
    }

    szybkie_potegowanie(potega,rozmiar);

    //Wynik znajduje się w macierz2
    cout<<endl<<endl;
    for(int i=1;i<=rozmiar;i++)
    {
        for(int j=1;j<=rozmiar;j++)
        {
            cout<<macierz2[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}