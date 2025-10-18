//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int D=200;
const int S=200;
const int M=200;

const LL maks=1e18;

LL dp[D+5][S+5][M+5];
int potega[D+5];

int s,m,q;

void query(LL k){
    string res;
    int sum=s;
    int mod=0;

    if(dp[D][s][0]<k){
        cout<<"NIE"<<endl;
        return;
    }

    for(int i=D;i>0;i--){
        for(int j=0;j<=9;j++){
            int newSum=sum-j;
            int newMod=((mod-j*potega[i-1])%m+m)%m; 
            if(dp[i-1][newSum][newMod]<k){
                k=k-dp[i-1][newSum][newMod];
            }else{
                res+=(char)'0'+j;
                mod=newMod;
                sum=newSum;
                break;
            }
        }
    }

    while(res[0] == '0'){
        res.erase(res.begin());
    }

    if(res.empty()){
        cout<<0<<endl;
    }else{
        cout<<res<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >>s>>m>>q;

    potega[0]=1;
    for(int i=1;i<=D;++i){
        potega[i]=potega[i-1]*10%m;
    }


    //Dp[D][S][M] - ile liczb o ilosci cyfr D,sumie S i danej reszcie przy dzieleniu przez M
    dp[0][0][0]=1;
    for(int i=0;i<=D;++i){
        for(int j=0;j<=s;++j){
            for(int r=0;r<m;++r){
                for(int d=0;d<=9;++d){
                    dp[i+1][j+d][(r+d*potega[i])%m]=min(dp[i+1][j+d][(r+d*potega[i])%m]+dp[i][j][r],maks);
                }
            }
        }
    }

    LL k;
    while(q!=0){
        cin>>k;
        query(k);
        q--;
    }

    return 0;
}