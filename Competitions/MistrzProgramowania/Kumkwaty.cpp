//Karol Dziekan
#include <bits/stdc++.h>

#define endl '\n'
#define LL long long

using namespace std;

vector<int> wejscie;
vector<int> prefiksy;
vector<int> sufiksy;
vector<int> roznice;

vector<vector<int>> zapamietywanie;

int oblicz_dp(int p,int k){
    if(zapamietywanie[p][k]!=0){
        return zapamietywanie[p][k];
    }
    if(p==k){
        return wejscie[p];
    }
    if(k<p){ 
        return 0;
    }
    if((k-p+1)%2==0){
        return max(prefiksy[k]-prefiksy[p-1],prefiksy[k-1]-prefiksy[max(p-2,0)]);
    }
    
    int wynik=0;
    for(int i=p+1;i<k;i+=2){
        int wynikp=wejscie[i];
        wynikp=wynikp+min(prefiksy[i-2]-prefiksy[p-1]+oblicz_dp(i+1,k),prefiksy[k-1]-prefiksy[i]+oblicz_dp(p,i-1));
        wynik=max(wynik,wynikp);
    }

    if(prefiksy[k]-prefiksy[max(p-2,0)]>wynik){
        wynik=prefiksy[k]-prefiksy[max(p-2,0)];
    }

    zapamietywanie[p][k]=wynik;
    return wynik;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,suma=0,flaga=1,flaga2=1;
    cin>>n;

    roznice.resize(n+1);
    wejscie.resize(n+1);
    prefiksy.resize(n+1,0);
    sufiksy.resize(n+2,0);

    for(int i=1;i<=n;i++){
        cin>>wejscie[i];
        suma+=wejscie[i];
        if(wejscie[i]!=1 && wejscie[i]!=2)flaga=0;
        if(wejscie[i]!=1)flaga2=0;
    }

    if(flaga){
        suma=0;
        for(int i=1;i<=n;i++){
            wejscie[i]--;
            suma+=wejscie[i];
        }

        for(int i=1;i<=n;i++){
            prefiksy[i]=wejscie[i];
            if(i-2>=1)prefiksy[i]=prefiksy[i]+prefiksy[i-2];
        }
        for(int i=n;i>=1;i--){
            sufiksy[i]=wejscie[i];
            if(i+2<=n)sufiksy[i]=sufiksy[i]+sufiksy[i+2];
        }

        if(flaga){
            if(n%2==0){
                long long int wynik=max(prefiksy[n],suma-prefiksy[n]);
                cout<<wynik+n/2<<" "<<(suma+n)-(wynik+n/2)<<endl;
                return 0;
            }else{
                long long int wynik=max(prefiksy[n],suma-prefiksy[n]);
                cout<<wynik+(n-1)/2+1<<" "<<(suma+n)-(wynik+(n-1)/2+1)<<endl;
                return 0;
            }
        }

    }

    for(int i=1;i<=n;i++){
        prefiksy[i]=wejscie[i];
        if(i-2>=1)prefiksy[i]=prefiksy[i]+prefiksy[i-2];
    }
    for(int i=n;i>=1;i--){
        sufiksy[i]=wejscie[i];
        if(i+2<=n)sufiksy[i]=sufiksy[i]+sufiksy[i+2];
    }
    for(int i=1;i<=n;i++){
        roznice[i]=(prefiksy[i]-sufiksy[n-i+1]);
    }

    if(flaga2){
        cout<<max(prefiksy[n],suma-prefiksy[n])<<" "<<min(suma-prefiksy[n],prefiksy[n])<<endl;
        return 0;
    }

    if(n<=0){
        zapamietywanie.resize(n+1,vector<int> (n+1,0));
        long long int wynik=oblicz_dp(1,n);
        cout<<wynik<<" "<<suma-wynik<<endl;
        return 0;
    }else{
        if(n%2==0){
            cout<<max(prefiksy[n],suma-prefiksy[n])<<" "<<min(suma-prefiksy[n],prefiksy[n])<<endl;
            return 0;
        }else{
            int wynik=max(prefiksy[n],suma-prefiksy[n]);
            for(int i=2;i<=n;i+=2){
                int wynikp1=0,wynikp2=0;

                int liczba1=0,liczba2=0,liczba3=0,liczba4=0;
                liczba1=prefiksy[i];
                if(i-1>=1)liczba2=prefiksy[i-1];
                liczba3=sufiksy[i];
                if(i+1<=n)liczba4=sufiksy[i+1];

                wynikp1=liczba1+liczba4;
                wynikp2=liczba2+liczba3;

                if(max(wynikp1,wynikp2)>wynik){
                    cout<<i<<" ";
                }
                wynik=max(wynik,max(wynikp1,wynikp2));
                
                
            }
            
            cout<<max(wynik,suma-wynik)<<" "<<min(wynik,suma-wynik)<<endl;
        }

    }

    return 0;
}