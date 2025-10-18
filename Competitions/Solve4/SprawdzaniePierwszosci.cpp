//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    if(n==1 || n==0){
        cout<<0;
        return 0;
    }
    
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            cout<<0;
            return 0;
        }
    }

    cout<<1;
    return 0;
}