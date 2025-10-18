//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n;
    cin>>n;

    long long int pozycja=2;
    while(pozycja<n){
        pozycja=pozycja*2+1;
    }

    if(pozycja==n || n==0){
        cout<<"NIE";
    }else{
        cout<<"TAK";
    }
    return 0;
}