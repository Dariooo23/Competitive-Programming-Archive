//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int x,k=1;
    cin>>x;
    while(x!=1){
        if(x%2==0){
            x=x/2;
        }else{
            x=3*x+1;
        }
        k++;
    }

    cout<<k;
    return 0;
}