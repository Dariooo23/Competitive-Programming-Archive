//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int a;
    cin>>a;
    if(a%17==0){
        cout<<0;
    }else{
        cout<<17-a%17;
    }
    return 0;
}