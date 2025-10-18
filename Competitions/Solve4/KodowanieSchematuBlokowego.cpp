//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int m=0;
    int k;
    
    while(true){
        cin>>k;
        if(k==0){
            cout<<m;
            return 0;
        }else{
            while(k%2==0){
                k=k/2;
                m++;
            }
        }
    }

    cout<<m;
    return 0;
}