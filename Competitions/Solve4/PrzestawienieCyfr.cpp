//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    string liczba;
    cin>>liczba;
    if(liczba.size()==1){
        liczba='0'+liczba;
    }

    if(liczba[1]=='0'){
        cout<<liczba[0];
    }else{
        cout<<liczba[1]<<liczba[0];
    }
    return 0;
}