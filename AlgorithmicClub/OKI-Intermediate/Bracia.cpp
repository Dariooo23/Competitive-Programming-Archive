//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

vector<int> wejscie,wejscie2;
vector<int> poczatek,koniec;

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    wejscie.resize(n);

    poczatek.resize(1000009,-1);
    koniec.resize(1000009,-1);

    for(int i=0;i<n;i++){
        cin>>wejscie[i];
    }

    for(int i=0;i<n;i++){
        if(poczatek[wejscie[i]]==-1)poczatek[wejscie[i]]=i;
    }
    for(int i=n-1;i>=0;i--){
        if(koniec[wejscie[i]]==-1){
            if(poczatek[wejscie[i]]!=i)koniec[wejscie[i]]=i;
        }
    }

    for(int i=0;i<n;i++){
        if(poczatek[wejscie[i]]!=-1 && koniec[wejscie[i]]==-1){
            wejscie2.push_back(wejscie[i]);
            wejscie2.push_back(wejscie[i]);
        }else{
            if(poczatek[wejscie[i]]==i || koniec[wejscie[i]]==i){
                wejscie2.push_back(wejscie[i]);
            }
        }
    }

    poczatek.clear();
    koniec.clear();

    poczatek.resize(1000009,-1);
    koniec.resize(1000009,-1);

    vector<int> dp(wejscie2.size(),0);

    for(int i=0;i<wejscie2.size();i++){
        if(poczatek[wejscie2[i]]==-1)poczatek[wejscie2[i]]=i;
    }
    for(int i=wejscie2.size()-1;i>=0;i--){
        if(koniec[wejscie2[i]]==-1){
            if(poczatek[wejscie2[i]]!=i)koniec[wejscie2[i]]=i;
        }
    }

    dp[0]=0;
    for(int i=1;i<wejscie2.size();i++){
        if(poczatek[wejscie2[i]]!=i)
        dp[i]=max(dp[i-1],dp[poczatek[wejscie2[i]]]+1);
        else
        dp[i]=dp[i-1];
    }

    cout<<dp[wejscie2.size()-1];
    return 0;
}