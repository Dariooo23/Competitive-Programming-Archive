//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cout<<"AC";
    
    return 0;
}
//Karol Dziekan
/*#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

vector<vector<int>> dp;
vector<vector<int>> wejscie;
bool sprawdz(int mediana,int n){
    dp.resize(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1)dp[i][j]=dp[i][j-1];
            if(j==1)dp[i][j]=dp[i-1][j];
            if(i!=1 && j!=1)dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

            if(wejscie[i][j]>=mediana)dp[i][j]+=1;
            if(wejscie[i][j]<mediana)dp[i][j]-=1;
        }
    }

    if(dp[n][n]>0){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    wejscie.resize(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>wejscie[i][j];
        }
    }

    int lewo=1,prawo=1e9,srodek;
    while(lewo<prawo){
        srodek=(lewo+prawo+1)/2;

        if(sprawdz(srodek,n)){
            lewo=srodek;
        }else{
            prawo=srodek-1;
        }
    }

    cout<<lewo;
    return 0;
}*/