//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<long long int> tab(n);
    for(int i=0;i<n;i++){
        cin>>tab[i];
    }

    long long int licznik=0,lider=-1;
    for(int i=0;i<n;i++){
        if(lider==-1){
            lider=tab[i];
        }
        if(licznik>0){
            if(tab[i]==lider){
                licznik++;
            }else{
                licznik--;
            }
        }else{
            lider=tab[i];
            licznik++;
        }
    }

    if(lider==-1){
        cout<<"-1"<<'\n';
    }else{
        licznik=0;
        for(int i=0;i<n;i++){
            if(tab[i]==lider)licznik++;
        }
        if(licznik>n/2){
            cout<<lider<<'\n';
        }else{
            cout<<"-1"<<'\n';
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}