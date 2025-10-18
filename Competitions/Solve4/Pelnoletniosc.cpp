//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int wynik=0,a;
    while(cin>>a){
        if(a>=18){
            wynik++;
        }
    }

    cout<<wynik;
    return 0;
}