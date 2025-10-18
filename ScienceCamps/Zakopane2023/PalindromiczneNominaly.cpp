//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int mod=1e9+7;
vector<int> dp;
vector<int> palindromy;

bool palindrom(int liczba){
    vector<int> cyfry;
    while(liczba>0){
        cyfry.push_back(liczba%10);
        liczba=liczba/10;
    }

    for(int i=0;i<cyfry.size();i++){
        if(cyfry[i]!=cyfry[cyfry.size()-1-i]){
            return 0;
        }
    }

    return 1;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int q;
    cin>>q;

    for(int i=1;i<=50000;i++){
        if(palindrom(i)){
            palindromy.push_back(i);
        }
    }

    dp.resize(50009);
    dp[0]=1;
    for(int i=0;i<palindromy.size();i++){
        for(int j=0;j<=50000;j++){
            if(j<palindromy[i])continue;
            dp[j]=(dp[j]+dp[j-palindromy[i]])%mod;
        }
    }

    while(q--){
        int r;
        cin>>r;
        cout<<dp[r]<<endl;
    }

    return 0;
}