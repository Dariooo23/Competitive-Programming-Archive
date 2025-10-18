//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);


    long long int m,d,n,m2;
    cin>>m>>d>>n;
    m2=m-d;

    vector<long long int> taksowki(n);

    for(int i=0;i<n;i++){
        cin>>taksowki[i];
    }

    sort(taksowki.begin(),taksowki.end());

    long long int potrzebna=taksowki[taksowki.size()-1];
    long long int indeks=-1;

    if(potrzebna>=m+d){
        cout<<1;
        return 0;
    }

    for(int i=0;i<n;i++){
        if(taksowki[i]>=m2){
            potrzebna=taksowki[i];
            indeks=i;
            break;
        }
    }

    if(indeks==-1){
        cout<<0;
        return 0;
    }

    long long int indeks_bajtka=0;
    long long int wynik=1;

    for(int i=n-1;i>=0;i--){
        if(i==indeks)continue;
        long long int zmiana=taksowki[i];
        if(zmiana<=d-indeks_bajtka){
            cout<<0;
            return 0;
        }else{
            zmiana=zmiana-(d-indeks_bajtka);
            indeks_bajtka=indeks_bajtka+zmiana;
            wynik++;

            if(indeks_bajtka>=(m+d-potrzebna-1)/2+1){
                break;
            }
        }
    }
    
    if(indeks_bajtka>=(m+d-potrzebna-1)/2+1){
        if(indeks_bajtka>=m){
            cout<<wynik-1;
        }else{
            cout<<wynik;
        }
    }else{
        cout<<0;
    }
     
    return 0;
}