//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    for(int i=1;i<=10;i++){
        int ilosc=0;
        for(int j=1;j<=10;j++){
            char znak;
            cin>>znak;
            if(znak=='#'){
                ilosc++;
            }
        }
        if(ilosc!=0){
            cout<<ilosc;
            return 0;
        }
    }
    
    return 0;
}