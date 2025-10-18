//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int a;
    cin>>a;

    long double wynik=(sqrtl(3*a-33)-3)/3;
    if(wynik==(long long int)wynik){
        cout<<(long long int)wynik;
    }else{
        cout<<"NIE";
    }

    return 0;
}