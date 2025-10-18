//Karol Dziekan
#include "r3clib.h"
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

long long int wynikx=0,wyniky=0;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int lewo=-1e9,prawo=1e9,licznik=0;
    while(lewo<=prawo){
        if(licznik==34)break;
        licznik++;
        long long int mid=(lewo+prawo)/2;
        long long int wynik=sluchaj(mid,0,mid,1);
        if(wynik==0){
            wynikx=mid;
            break;
        }
        if(wynik==-1){
            prawo=mid-1;
        }else{
            lewo=mid+1;
        }
    }
    if(sluchaj(lewo,0,lewo,1)==0){
        wynikx=lewo;
    }

    lewo=-1e9;prawo=1e9;licznik=0;
    while(lewo<=prawo){
        if(licznik==34)break;
        licznik++;
        long long int mid=(lewo+prawo)/2;
        long long int wynik=sluchaj(0,mid,1,mid);
        if(wynik==0){
            wyniky=mid;
            break;
        }
        if(wynik==1){
            prawo=mid-1;
        }else{
            lewo=mid+1;
        }
    }
    if(sluchaj(0,lewo,1,lewo)==0){
        wyniky=lewo;
    }

    odpowiedz(wynikx,wyniky);
}