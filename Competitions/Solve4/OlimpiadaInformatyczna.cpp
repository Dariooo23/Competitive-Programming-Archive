//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string wejscie;
    cin>>wejscie;

    vector<long long int> sumsuf(wejscie.size()+1);
    sumsuf[wejscie.size()]=0;
    for(int i=wejscie.size()-1;i>=0;i--){
        if(wejscie[i]=='I'){
            sumsuf[i]=1;
        }sumsuf[i]=sumsuf[i]+sumsuf[i+1];
    }

    long long int wynik=0;
    for(int i=0;i<wejscie.size();i++){
        if(wejscie[i]=='O'){
            wynik=wynik+sumsuf[i];
        }
    }

    cout<<wynik;
    return 0;
}