//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

unsigned long long int n,m,o;
unsigned long long int wynik=0;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n>>m>>o;
    if(o%2==1){
        o++;
    }

    for(unsigned long long int i=1;i<=m;i++){
        unsigned long long int sciana;
        if((long long int)((long long int)(o-i*2)/2)<=0){
            sciana=1;
        }else{
            sciana=((o-i*2)/2);
        }
        if(sciana>n)continue;

        wynik=wynik+(unsigned long long int)((unsigned long long int)(((unsigned long long int)(n-sciana+1)*(unsigned long long int)(n-sciana+2))/2)*(unsigned long long int)(m-i+1));
    }

    cout<<wynik;
    return 0;
}