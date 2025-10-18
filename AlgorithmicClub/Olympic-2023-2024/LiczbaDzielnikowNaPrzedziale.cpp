//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

long long int solve(long long int liczba){
    long long int wynik=0;

    for(long long int i=1;i<=(long long int)sqrt(liczba);i++){
        wynik=wynik+liczba/i;
    }

    wynik=wynik*2;
    wynik=wynik-((long long int)sqrt(liczba)*(long long int)sqrt(liczba));

    return wynik;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int a,b,wynik1=0,wynik2=0;
    cin>>a>>b;

    cout<<solve(b)-solve(a-1);
    return 0;
}