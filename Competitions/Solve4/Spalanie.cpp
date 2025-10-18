//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long double liczba;
    cin>>liczba;
    string napis;
    cin>>napis;

    if(napis[napis.size()-1]=='m'){
        cout<<fixed<<setprecision(2)<<(100/1.609344)/(liczba/3.78541178)<<" mpg";
    }else{
        cout<<fixed<<setprecision(2)<<100/(1.609344/3.78541178*liczba)<<" l/100km";
    }
    return 0;
}