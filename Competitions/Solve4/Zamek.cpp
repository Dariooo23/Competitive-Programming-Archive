//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> dp;
vector<bool> mur;
void wypisz(int indeks){
    if(indeks!=0){
        wypisz(dp[indeks]);
        if(indeks-dp[indeks]==1){
            cout<<"V";
        }else{
            cout<<"H";
        }
    }
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    string wejscie;
    cin>>wejscie;

    mur.push_back(0);
    for(int i=0;i<wejscie.size();i++){
        if(wejscie[i]=='H'){
            mur.push_back(1);
            mur.push_back(1);
        }else{
            mur.push_back(0);
        }
    }


    dp.resize(n+1);
    dp[0]=1;

    if(mur[1]==0){
        dp[1]=-1;
    }else{
        dp[1]=0;
    }


    for(int i=2;i<=n;i++){
        if((dp[i-2]!=-1 && (mur[i]==0 || mur[i-1]==0))){
            dp[i]=i-2;
        }else{
            if((dp[i-1]!=-1 && mur[i]==1)){
                dp[i]=i-1;
            }else{
                dp[i]=-1;
            }
        }
    }


    if(dp[n]!=-1){
        cout<<"TAK"<<endl;
        wypisz(n);
    }else{
        cout<<"NIE";
    }

    return 0;
}