//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int suma=0,liczbag=0;
void sprawdz(int liczba){
    int dodajnik=0;
    int kopia=liczba;

    while(kopia!=0){
        dodajnik=dodajnik+kopia%10;
        kopia=kopia/10;
    }
    if(dodajnik>suma){
        suma=dodajnik;
        liczbag=liczba;
    }

    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,k;
    cin>>k>>n;

    for(int i=n;i<n+k;i++){
        sprawdz(i);
    }

    cout<<liczbag;
    return 0;
}