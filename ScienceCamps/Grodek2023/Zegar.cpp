//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int godzina,minuta,sekunda;
    cin>>godzina>>minuta>>sekunda;

    if(sekunda==59){
        sekunda=0;
        minuta=minuta+1;
        if(minuta==60){
            minuta=0;
            godzina=godzina+1;
            if(godzina==24){
                godzina=0;
            }
        }
    }else{
        sekunda=sekunda+1;
    }

    if(godzina<10){
        cout<<"0"<<godzina<<":";
    }else{
        cout<<godzina<<":";
    }
    if(minuta<10){
        cout<<"0"<<minuta<<":";
    }else{
        cout<<minuta<<":";
    }
    if(sekunda<10){
        cout<<"0"<<sekunda;
    }else{
        cout<<sekunda;
    }

    return 0;
}
 