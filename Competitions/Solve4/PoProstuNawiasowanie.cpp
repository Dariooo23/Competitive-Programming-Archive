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
    int suma=0;
    for(int i=0;i<a;i++){
        char znak;
        cin>>znak;
        if(znak=='('){
            suma++;
        }
        if(znak==')'){
            suma--;
            if(suma<0){
                cout<<"NIE";
                return 0;
            }
        }
    }
    if(suma==0){
        cout<<"TAK";
    }else{
        cout<<"NIE";
    }
    return 0;
}