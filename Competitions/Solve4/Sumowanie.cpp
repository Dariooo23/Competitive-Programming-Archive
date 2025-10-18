//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int a,wynik=0;
    cin>>a;
    for(int i=0;i<a;i++){
        long long int b;
        cin>>b;
        wynik=wynik+b;
    }
    cout<<wynik;

    return 0;
}