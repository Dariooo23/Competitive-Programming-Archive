//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    long long int stan1=1,stan2=1,stan3=1,suma;
    for(int i=1;i<=n;i++){
        suma=(stan1+stan2+stan3)%mod;
        stan2=(stan2+stan1)%mod;
        stan3=(stan3+stan1)%mod;
        stan1=suma%mod;
    }



    cout<<stan1%mod;
    return 0;
}