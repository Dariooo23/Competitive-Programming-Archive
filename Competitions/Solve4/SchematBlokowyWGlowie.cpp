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

    int k=1,m=n-1;
    while(true){
        if((n+k)%m==0){
            cout<<m;
            break;
        }else{
            k=k+1;
            m=m-1;
        }
    }
    return 0;
}