//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int a,potega=5,wynik=0;
    cin>>a;

    while(potega<=a){
        wynik=wynik+a/potega;
        potega=potega*5;
    }

    cout<<wynik;
    return 0;
}