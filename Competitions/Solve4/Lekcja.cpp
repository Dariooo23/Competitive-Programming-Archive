//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string godzina;
    cin>>godzina;

    int cgodzina,cminuta;
    cgodzina=(godzina[0]-'0')*10+godzina[1]-'0';
    cminuta=(godzina[3]-'0')*10+godzina[4]-'0';

    cminuta=cminuta+45;
    if(cminuta>=60){
        cminuta=cminuta-60;
        cgodzina=cgodzina+1;
    }
    if(cgodzina>=24){
        cgodzina=cgodzina-24;
    }
    if(cgodzina<10){
        cout<<"0"<<cgodzina;
    }else{
        cout<<cgodzina;
    }
    cout<<":";
    if(cminuta<10){
        cout<<"0"<<cminuta;
    }else{
        cout<<cminuta;
    }
    return 0;
}