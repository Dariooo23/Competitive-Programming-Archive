//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int N;
    cin>>N;

    long long result=1;
    for (int i=0;i<N;i++) {
        result=(result*2)%MOD;
    }

    cout<<result;
    return 0;
}