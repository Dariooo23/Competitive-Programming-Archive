//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> pref,suf,zapalki;

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,wynik=1e9+9;
    cin>>n;

    suf.resize(n+2);
    pref.resize(n+2);
    zapalki.resize(n+2);

    for(int i=1;i<=n;i++){
        cin>>zapalki[i];
    }

    pref[0]=0;
    for(int i=1;i<=n;i++){
        if(zapalki[i]==0)pref[i]=pref[i-1]+1;
        else pref[i]=pref[i-1];
    }

    suf[n+1]=0;
    for(int i=n;i>0;i--){
        if(zapalki[i]==1)suf[i]=suf[i+1]+1;
        else suf[i]=suf[i+1];
    }

    for(int i=0;i<=n;i++){
       wynik=min(wynik,pref[i]+suf[i+1]);
    }

    cout<<wynik;
    return 0;
}