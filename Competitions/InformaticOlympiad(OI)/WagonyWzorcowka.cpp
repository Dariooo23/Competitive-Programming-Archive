//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int n,d,a,b;
const unsigned long long int maks=1e19;
vector<unsigned long long int> dp_vector(1000009,maks);
unordered_map<long long int,unsigned long long int> dp_map;

unsigned long long int funkcja(unsigned long long int i,unsigned long long int j,unsigned long long int a,unsigned long long int b){
    return (i*a+j*b)%1001;
}

void oblicz_dp(long long int indeks){ 
    if(indeks>1e6){
        dp_map[indeks]=maks;
    }else{
        dp_vector[indeks]=maks;
    }

    long long int poczatek=max((indeks-d-1)/2+1,(long long int)1);
    long long int koniec=min((indeks+d)/2,n);

    for(long long int i=poczatek;i<=koniec;i++){
        if(indeks-i<0)continue;

        if(i>1e6){
            if(dp_map.find(i)==dp_map.end())oblicz_dp(i);
        }else{
            if(dp_vector[i]==maks)oblicz_dp(i);
        }
        if((indeks-i)>1e6){
            if(dp_map.find(indeks-i)==dp_map.end())oblicz_dp(indeks-i);
        }else{
            if(dp_vector[indeks-i]==maks)oblicz_dp(indeks-i);
        }

        unsigned long long int dodaj1,dodaj2,dodaj3=funkcja(i,indeks-i,a,b);
        if(i>1e6){
            dodaj1=dp_map[i];
        }else{
            dodaj1=dp_vector[i];
        }
        if((indeks-i)>1e6){
            dodaj2=dp_map[indeks-i];
        }else{
            dodaj2=dp_vector[indeks-i];
        }
        if(indeks>1e6){
            dp_map[indeks]=min(dodaj1+dodaj2+dodaj3,dp_map[indeks]);
        }else{
            dp_vector[indeks]=min(dodaj1+dodaj2+dodaj3,dp_vector[indeks]);
        }
    }return;
}

int main() 
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n>>d>>a>>b;

    dp_vector[0]=dp_vector[1]=0;
    for(int i=2;i<=d;i++){
        for(int j=max((int)(i-d-1)/2+1,(int)1);j<=min((i+d)/2,n);j++){
            if(i-j>=0)dp_vector[i]=min((dp_vector[j]+dp_vector[i-j]+funkcja(j,i-j,a,b)),dp_vector[i]);      
        }                                                                          
    }
    
    oblicz_dp(n);
    if(n<=1e6){
        cout<<dp_vector[n];
    }else{
        cout<<dp_map[n];
    }

    return 0;
}
 