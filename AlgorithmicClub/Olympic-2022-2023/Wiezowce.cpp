//Karol Dziekan
#include "wie.h"
#include <bits/stdc++.h>

using namespace std;

vector<int> numery;
int losuj(int indeks){
    return rand()%indeks;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int n=wezN(),wynik=1;
    for(int i=1;i<=n;i++){
        numery.push_back(i);
    }

    random_shuffle(numery.begin(),numery.end(),losuj);

    long long int l=1,r=1e18,mid=0;
    for(int i=0;i<n;i++){
        if(wynik<1e18 && !zamowienie(numery[i],wynik+1))continue;

        r=1e18;
        while(l<r){
            mid=(l+r+1)/2;
            if(zamowienie(numery[i],mid)){
                l=mid;
            }else{
                r=mid-1;
            }
        }
        wynik=max(wynik,l);
    }

    odpowiedz(wynik);
    return 0;
}
 