#include <bits/stdc++.h>

using namespace std;

long double pole(long double a){
long double p=a*(a/4.0);
return p*(long double)sqrtl((long double)3);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
    long long int n;
    cin>>n;

    long long int l=1,r=2e9+9,mid;
    while (l<r)
    {
        mid=(l+r)/2;
        if(pole(mid)>=n){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }

    cout<<l;
    return 0;
}