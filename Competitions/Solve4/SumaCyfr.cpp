//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    string liczba;
    cin>>liczba;
    int wynik=0;
    for(int i=0;i<liczba.size();i++){
        wynik=wynik+liczba[i]-'0';
    }cout<<wynik;
    return 0;
}