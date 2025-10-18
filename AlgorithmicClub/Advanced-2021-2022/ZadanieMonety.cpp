//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> miejsca;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    long long int wynik=1,modulo=1e9+7,liczba=0;
    cin>>n;
    miejsca.resize(n+9);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        miejsca[a]++;
    }

    for(int i=1;i<=n;i++)
    {
        while(miejsca[i])
        {
            wynik=wynik*(i-liczba++);
            wynik=wynik%modulo;
            miejsca[i]--;
        }
    }

    cout<<wynik;
    return 0;
}