#include <bits/stdc++.h>
#define ll long long

using namespace std;

const long long int modulo=123456789;

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

    long long int dlugosc,pary;
    cin>>dlugosc>>pary;

    macierz1.resize(27,vector<long long int> (27,1));
    macierz2.resize(27,vector<long long int> (27,0));
    macierz3.resize(27,vector<long long int> (27,0));

    for(int i=1;i<=pary;i++)
    {
        char litera1,litera2;
        cin>>litera1>>litera2;
        macierz1[litera1-'a'+1][litera2-'a'+1]=0;
    }
    for(int i=1;i<=26;i++)
    {
        macierz2[i][i]=1;
    }

    szybkie_potegowanie(dlugosc-1,26);

    long long int wynik=0;
    for(int i=1;i<=26;i++)
    {
        for(int j=1;j<=26;j++)
        {
            wynik=(wynik+macierz2[i][j])%modulo;
        }
    }
    cout<<wynik;

    return 0;
}