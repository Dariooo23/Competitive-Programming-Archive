//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

void brut(int l,int r){
    int wynik=1;
    for(int i=2;i<=r;i++){
        int liczba1=l%i;
        int liczba2;

        if(liczba1==0){
            liczba2=l;
        }else{ 
            liczba2=l+(i-liczba1);
        }

        int liczba3=liczba2+i;
        if(liczba2>=l && liczba2<=r && liczba3>=l && liczba3<=r){
            wynik++;
        }
    }

    if(l==r){
        cout<<0<<endl;
    }else{
        cout<<wynik<<endl;
    }
    return;
}

void wzorcowka(long long int l,long long int r){

    long long int wynik=1;
    long long int lpocz=1e18;
    long long int minimum=1e18;
    for(int i=1;i<sqrtl(l);i++){
        long long int pocz=(l-1)/i+1,kon=r/(i+1);
        if(kon>=lpocz)kon=lpocz-1;

        lpocz=pocz;

        if(kon-pocz+1<0)continue;
        minimum=min(minimum,pocz);
        wynik=wynik+kon-pocz+1;
    }

    for(int i=2;i<=min((long long int)(sqrt(l-1)+1),(long long int)(minimum-1));i++){
        int liczba1=l%i;
        int liczba2;

        if(liczba1==0){
            liczba2=l;
        }else{ 
            liczba2=l+(i-liczba1);
        }

        int liczba3=liczba2+i;
        if(liczba2>=l && liczba2<=r && liczba3>=l && liczba3<=r){
            wynik++;
        }
    }

    if(l==r){
        cout<<0<<endl;
    }else{
        cout<<wynik<<endl;
    }
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int q;
    cin>>q;

    while(q--){
        long long int l,r;
        cin>>l>>r;
        if(l<=100000 && r<=100000){
            brut(l,r);
        }else{
            wzorcowka(l,r);
        }
        
    }
    return 0;
}