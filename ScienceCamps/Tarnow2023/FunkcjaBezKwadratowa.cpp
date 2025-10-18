//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long int> liczby;
vector<long long int> wartosci_funkcji;
const long long int mod=1e9+7;

void najwiekszy_kwadrat(long long int a,long long int indeks){
    long long int kwadrat=1;
    for(int i=1;i*i<=a;i++){
        if((a)%(i*i)==0){
            kwadrat=i*i;
        }
    }
    wartosci_funkcji[indeks]=((a)/(kwadrat))%mod;
}
long long int nwd(long long int a,long long int b){
    if(b!=0)return nwd(b,a%b);
    return a;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n;
    liczby.resize(n+1);
    wartosci_funkcji.resize(200009,0);

    long long int wynik=0,maks=0;
    for(int i=1;i<=n;i++){
        cin>>liczby[i];
        maks=max(maks,liczby[i]);
    }
    for(int i=1;i<=maks;i++){
        najwiekszy_kwadrat(i,i);
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            long long int dzielnik=nwd(liczby[i],liczby[j]);
            wynik=(wynik+(wartosci_funkcji[liczby[i]/dzielnik]*wartosci_funkcji[liczby[j]/dzielnik])%mod)%mod;
        }
    }

    cout<<wynik;

    return 0;
}
 