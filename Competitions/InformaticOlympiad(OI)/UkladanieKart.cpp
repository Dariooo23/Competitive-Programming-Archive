#include <bits/stdc++.h>

using namespace std;
vector<long long int> pd;
vector<long long int> pw;
long long int modulo;
long long int silnia (long long int a)
{
    long long int wynik=1;
    for(int i=1;i<=a;i++)
    {
        wynik=(wynik*i)%modulo;
    }

    return wynik%modulo;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int ilosc,wynik=0,pd3=0,pd2=0,sum=0,pw2=0;
    cin>>ilosc>>modulo;
    pd.push_back(1);
    pw.push_back(0);
    for(int i=1;i<ilosc;i++)
    {
        sum=sum+i;
    }
    for(int i=1;i<ilosc-2;i++)
    {
        pd.push_back(((((ilosc-i)*pd[i-1])%modulo)+pd3+1)%modulo);
        pw.push_back((((((sum*pd[i-1])%modulo)+pd2)%modulo)+(((ilosc-i)*pw[i-1])%modulo)+pw2)%modulo);
        pw2=(pw2+pw[i-1])%modulo;
        pd2=(pd2+pd[i-1]*i)%modulo;
        pd3=(pd3+pd[i-1])%modulo;

        sum=(sum-i)%modulo;
    }
    for(int i=1;i<ilosc-1;i++)
    {
        wynik=(wynik+(pd[i-1]*i)%modulo+pw[i-1])%modulo;
    }
    long long int wynik2=(((((ilosc-1)*silnia(ilosc-1))%modulo)*((((ilosc-1)*ilosc)/2)%modulo)+(ilosc*wynik)%modulo)%modulo);
    if(wynik2<0)
    {
        cout<<wynik2+modulo;
    }
    else
    {
        cout<<wynik2;
    }

    return 0;
}