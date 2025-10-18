//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int liczba;
    cin>>liczba;

    long long int wynik=1e18+9;
    map<long long int,int> bylo;
    while(true){
        wynik=min(liczba,wynik);
        if(bylo.find(liczba)==bylo.end()){
            bylo[liczba]=1;
        }else{
            cout<<wynik<<" ";
            return 0;
        }

        long long int liczba2=liczba;
        liczba=0;
        while(liczba2!=0){
            liczba=liczba+((liczba2%10)*(liczba2%10));
            liczba2=liczba2/10;
        }
    }

    cout<<wynik;
    return 0;
}