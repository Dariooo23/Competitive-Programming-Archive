//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int a,b,c,d;
    cin>>a>>b>>c>>d;

    if(a==b){
        cout<<a*c;
    }else{
        cout<<a*b;
    }
    return 0;
}