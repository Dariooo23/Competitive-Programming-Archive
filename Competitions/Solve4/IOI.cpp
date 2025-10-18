//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int a,b,c;
    cin>>a>>b>>c;

    if(a>=2 && b>=2 && c>=1){
        cout<<"TAK";
    }else{
        cout<<"NIE";
    }
    return 0;
}