//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int maks=1000000;
vector<int> wejscie;
int dp[2][3];


int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,wynik=maks;
    cin>>n;

    wejscie.resize(n);

    for(int i=0;i<n;i++){
        cin>>wejscie[i];
    }

    for(int i=0;i<n;i++){
        int *akt=dp[i%2]+1;
        int *poprz=dp[1-i%2]+1;
        for(int j=-1;j<=1;j++){
            if(i==0){
                if(j==wejscie[i]){
                    akt[j]=0;
                }else{
                    akt[j]=maks;
                }
            }else{
                akt[j]=maks;
                for(int k=-1;k<=j;k++){
                    if(wejscie[i]==j){
                        akt[j]=min(akt[j],poprz[k]);
                    }else{
                        if((j-wejscie[i])*k>0){
                            akt[j]=min(akt[j],poprz[k]+(j-wejscie[i])/k);
                        }
                    }
                }
            }
        }
    }

    for(int i=-1;i<=1;i++){
        wynik=min(wynik,dp[(n-1)%2][i+1]);
    }

    if(wynik==maks){
        cout<<"BRAK";
    }else{
        cout<<wynik;
    }

    return 0;
}
 