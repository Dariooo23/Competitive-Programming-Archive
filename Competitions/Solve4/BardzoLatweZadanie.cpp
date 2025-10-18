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

    int indeks=1;
    string wynik="";
    for(int i=liczba.size()-1;i>=0;i--){
        if(indeks%2==0){
            wynik=wynik+liczba[i];
        }indeks++;
    }

    indeks=wynik.size()-1;
    while(indeks!=-1 && wynik[indeks]=='0'){
        indeks--;
    }
    for(int i=indeks;i>=0;i--){
        cout<<wynik[i];
    }
    if(indeks==-1 && wynik[0]=='0'){
        cout<<0;
    }
    return 0;
}