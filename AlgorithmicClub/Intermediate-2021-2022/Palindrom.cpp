//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const long long int mod=1e9+696969;
const long long int podstawa1=2137;
long long int hash1=0,hash2=0;
long long int podstawa2=1;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int k;
    cin>>k;

    char litera;
    while(cin>>litera)
    {
        hash1=(podstawa2*litera+hash1)%mod;
        hash2=(podstawa1*hash2+litera)%mod;
        podstawa2=(podstawa2*podstawa1)%mod;
    }

    if(hash1==hash2)
    {
        cout<<"TAK"<<endl;
    }
    else
    {
        cout<<"NIE"<<endl;
    }

    return 0;
}
 