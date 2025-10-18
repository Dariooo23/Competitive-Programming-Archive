//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> tablica;
vector<int> minimum;
vector<int> poprzednik;

int binsearch(int wartosc,int n){
    int l=0,r=n,mid;
    while(l<r){
        mid=(l+r)/2;
        if(minimum[mid]<=wartosc){
            l=mid+1;
        }else{
            r=mid;
        }
    }

    return l;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,wynik=0,koniec=0;
    cin>>n;

    tablica.resize(n+1);
    minimum.resize(n+1,1e9+7);
    
    for(int i=1;i<=n;i++){
        cin>>tablica[i];
    }

    minimum[0]=0;
    for(int i=1;i<=n;i++){
        int indeks=binsearch(tablica[i],n);
        
        if(minimum[indeks-1]<tablica[i] && minimum[indeks]>tablica[i]){
            minimum[indeks]=tablica[i];
            if(wynik<indeks){
                wynik=indeks;
                koniec=i;
            }
        }
    }

    cout<<wynik<<endl;
    return 0;
}
 