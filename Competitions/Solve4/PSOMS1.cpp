//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    long long int wynik=0,suma=0;
    for(int i=0;i<n;i++){
        long long int a;
        
        cin>>a;
        suma=suma+a;
        if(suma<0){
            suma=0;
        }
        wynik=max(suma,wynik);
    }

    cout<<wynik;
    return 0;
}