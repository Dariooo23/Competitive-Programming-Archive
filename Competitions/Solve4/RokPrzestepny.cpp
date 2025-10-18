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

    if(n%4==0){
        if(n%100==0){
            if(n%400==0){
                cout<<"TAK";
            }else{
                cout<<"NIE";
            }
        }else{
            cout<<"TAK";
        }
    }else{
        cout<<"NIE";
    }
    return 0;
}