//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n;
    cin>>n;

    long long int wynik=0;
    vector<int> tablica(n+1);
    for(int i=1;i<=n;i++){
        long long int a;
        cin>>a;
        long long int dlugosc1=i-1,dlugosc2=n-i;
        if(dlugosc2>dlugosc1)swap(dlugosc1,dlugosc2);
        long long int przedzialy=(n*(n+1))/2-(dlugosc1*(dlugosc1+1))/2-(dlugosc2*(dlugosc2+1))/2;
        wynik=wynik+a*przedzialy;
    }

    cout<<wynik;
    return 0;
}