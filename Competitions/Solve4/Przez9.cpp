//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    string liczba;
    int suma=0;
    cin>>liczba;
    for(int i=0;i<liczba.size();i++){
        suma=suma+liczba[i]-'0';
    }

    if(suma%9==0){
        cout<<"TAK";
    }else{
        cout<<"NIE";
    }
    return 0;
}