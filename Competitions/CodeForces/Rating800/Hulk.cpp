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

    for(int i=2;i<=n;i++){
        if(i%2==0){
            cout<<"I hate that ";
        }else{
            cout<<"I love that ";
        }
    }

    if(n%2==0){
        cout<<"I love it";
    }else{
        cout<<"I hate it";
    }
    return 0;
}
 