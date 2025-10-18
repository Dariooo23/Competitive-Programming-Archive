//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;
    string wejscie;
    cin>>wejscie;

    int licznik=1,wynik=1;
    for(int i=0;i<n;i++){
        if(wejscie[i]=='B'){
            licznik++;
        }else{
            wynik=max(wynik,licznik);
            licznik=1;
        }
    }
    wynik=max(wynik,licznik);

    if(n==1){
        cout<<0;
    }else{
        cout<<wynik;
    }
    return 0;
}