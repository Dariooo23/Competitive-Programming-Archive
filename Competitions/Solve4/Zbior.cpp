// Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

map<unsigned long long int,bool> zbior;

void wygeneruj(unsigned long long int liczba){
    if(liczba>10000000)return;

    if(zbior.find(liczba)==zbior.end()){
        zbior[liczba]=1;
        wygeneruj(liczba*2+1);
        wygeneruj(liczba*3);
        wygeneruj(liczba*5);
    }
    return;
}

bool sprawdz(unsigned long long int liczba){
    if(liczba%2==0)return 0;
    if(zbior.find(liczba)!=zbior.end())return 1;

    if((liczba-1)%2==0){
        bool wynik=sprawdz((liczba-1)/2);
        if(wynik){
            zbior[liczba]=1;
        }
    }
    if(liczba%3==0){
        bool wynik=sprawdz(liczba/3);
        if(wynik){
            zbior[liczba]=1;
        }
    }
    if(liczba%5==0){
        bool wynik=sprawdz(liczba/5);
        if(wynik){
            zbior[liczba]=1;
        }
    }
    if(zbior.find(liczba)!=zbior.end()){
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    wygeneruj(1);

    for(int i=0;i<n;i++){
        unsigned long long int a;
        cin>>a;
        
        if(sprawdz(a)){
            cout<<"TAK"<<endl;
        }else{
            cout<<"NIE"<<endl;
        }
    }

    return 0;
}