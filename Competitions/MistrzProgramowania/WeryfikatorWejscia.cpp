//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

vector<long long int> wejscie;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n;
    cin>>n;

    wejscie.resize(n);
    for(int i=0;i<n;i++){
        cin>>wejscie[i];
    }

    bool pod1=1,pod2=1,pod3=1,pod4=1,pod5=1,pod6=1,pod7=1;

    for(int i=0;i<n;i++){
        if(wejscie[i]!=1){
            pod1=0;
        }
        if(wejscie[i]!=1 && wejscie[i]!=2){
            pod2=0;
        }
    }

    if(n>100){
        pod3=0;
    }
    if(n>1000){
        pod4=0;
    }
    if(n%2==1){
        pod5=0;
    }
    if(n%2==0){
        pod6=0;
    }

    if(pod1){
        cout<<1;
        return 0;
    }
    if(pod2){
        cout<<2;
        return 0;
    }
    if(pod3){
        cout<<3;
        return 0;
    }
    if(pod4){
        cout<<4;
        return 0;
    }
    if(pod5){
        cout<<5;
        return 0;
    }if(pod6){
        cout<<6;
        return 0;
    }
    if(pod7){
        cout<<7;
        return 0;
    }
    return 0;
}