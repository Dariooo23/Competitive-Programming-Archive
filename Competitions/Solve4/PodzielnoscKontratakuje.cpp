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

    if(n%5==0 && n%7==2){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}