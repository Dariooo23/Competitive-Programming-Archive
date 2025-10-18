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

    long long int mnoznik=n,suma=0;
    for(int i=0;i<n;i++){
        long long int liczba;
        cin>>liczba;
        suma=suma+liczba*mnoznik;
        mnoznik--;
    }

    cout<<suma;
    return 0;
}