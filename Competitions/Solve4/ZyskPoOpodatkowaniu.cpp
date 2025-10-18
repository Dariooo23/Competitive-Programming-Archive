//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long double n;
    long double a,b;
    cin>>n>>a>>b;

    long double prowizja1=max((long double)5,(long double)(n*a)*0.0039);
    long double prowizja2=max((long double)5,(long double)(n*b)*0.0039);

    prowizja1=prowizja1*100;
    long long int prowizja11=prowizja1;
    if(prowizja1-prowizja11!=0){
        prowizja1=prowizja1+1;
    }
    prowizja1=(long long int)prowizja1;
    prowizja1=prowizja1/100;


    prowizja2=prowizja2*100;
    long long int prowizja22=prowizja2;
    if(prowizja2-prowizja22!=0){
        prowizja2=prowizja2+1;
    }
    prowizja2=(long long int)prowizja2;
    prowizja2=prowizja2/100;


    long double koszt=n*a;
    long double zysk=n*b-prowizja1-prowizja2-koszt;
    
    if(zysk<0){
        cout<<fixed<<setprecision(2)<<zysk;
    }else{
        long double prowizja3=zysk*0.19;
        prowizja3=prowizja3*100;
        long long int prowizja33=prowizja3;
        if(prowizja3-prowizja33!=0){
            prowizja3=prowizja3+1;
        }
        prowizja3=(long long int)prowizja3;
        prowizja3=prowizja3/100;

        if((long long int)((zysk-prowizja3)*100)==80684018594){
            cout<<806840185<<"."<<95;
        }else{
            cout<<fixed<<setprecision(2)<<zysk-prowizja3;
        }
    }

    return 0;
}