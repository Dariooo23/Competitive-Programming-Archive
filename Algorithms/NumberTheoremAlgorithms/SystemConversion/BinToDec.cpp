//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int BinToDec(string a)
{
    long long int wynik=0;
    for(int i=0;i<a.size();i++)
    {
        wynik=wynik*2+(a[i]-'0');
    }
    return wynik;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    string a;
    cin>>a;

    cout<<BinToDec(a);

    return 0;
}
 