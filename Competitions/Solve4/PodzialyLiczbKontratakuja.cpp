//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n,k;
void wygeneruj(vector<int> cyfry,int suma){
    if(cyfry.size()==k-1){
        if(n-suma>=cyfry[cyfry.size()-1]){
            for(int i=0;i<cyfry.size();i++){
            cout<<cyfry[i]<<" ";
        }
            cout<<n-suma<<'\n';
            return;
        }else{
            return;
        }
    }

    int poczatek=cyfry[cyfry.size()-1];
    int rozmiar=cyfry.size();
    for(int i=poczatek;i<=n;i++){
        cyfry.push_back(i);

        if(suma+i>n || (suma+i==n && rozmiar==k)){
            return;
        }

        wygeneruj(cyfry,suma+i);
        cyfry.pop_back();
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>k;
    
    if(k==1){
        if(n<=9){
            cout<<n;
            return 0;
        }else{
            return 0;
        }
    }else{
        for(int i=1;i<=n;i++){
            if(i<=n)wygeneruj({i},i);
        }
    }

    return 0;
}