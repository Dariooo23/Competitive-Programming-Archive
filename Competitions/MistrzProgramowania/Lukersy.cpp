//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n;
    cin>>n;

    long long int lewo=1,prawo=1e9,srodek;
    while(lewo<prawo){
        srodek=(lewo+prawo)/2;
        if((srodek*(srodek+1))/2<n){
            lewo=srodek+1;
        }else{
            prawo=srodek;
        }
    }

    cout<<lewo;
    return 0;
}