//Rozwiazanie uzywa programowania dynamicznego
//dp[i] - maksymalna ilosc punktow ktora mozna zdobyc wybierajac 
//        z poczatkowego ciagu jakis podzbior liczb miedzy 0-i


//Potrzebne spostrzezenia:
//*Jezeli wzielismy liczbe o wartosci x,
// to wezmiemy wszystkie takie liczby z ciagu

//*Jezeli do naszego wyniku bierzemy liczby o wartosci x,
// to nie mozemy wziac liczb o wartosci x-1, wiec dp[x]=dp[x-2]+ilosc[x]*x

//*Jezeli do naszego wyniku nie bierzemy liczby o wartosci x,
// to przepisujemy wiec wynik z x-1, dp[x]=dp[x-1]
// (Nie jest to rownoznaczne z tym ze bierzemy liczby o wartosci x-1)

#include <bits/stdc++.h>

using namespace std;

#define LL long long int
#define endl '\n'

vector<int> ciag;
vector<long long int> dp;
vector<long long int> ilosc;

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    ciag.resize(n);
    dp.resize(100001);
    ilosc.resize(100001);

    for(int i=0;i<n;i++){
        cin>>ciag[i];
        ilosc[ciag[i]]++;
    }

    dp[0]=0;
    dp[1]=ilosc[1];
    for(int i=2;i<=100000;i++){
        dp[i]=max(dp[i-1],dp[i-2]+ilosc[i]*i);
    }

    cout<<dp[100000];
    return 0;
}