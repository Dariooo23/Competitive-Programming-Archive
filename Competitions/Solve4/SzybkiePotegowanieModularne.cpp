//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int potegowanie(long long int a,long long int b,long long int c){
    if(b==0)return 1;
    if(b%2==0){
        long long int potega=(potegowanie(a,b/2,c))%c;
        return (potega*potega)%c;
    }else{
        return (a*potegowanie(a,b-1,c))%c;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int a,b,c;
    cin>>a>>b>>c;

    cout<<potegowanie(a,b,c)%c;
    return 0;
}