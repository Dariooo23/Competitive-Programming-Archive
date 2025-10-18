//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

string slowo;
int n,m;

vector<int> dp;
vector<int> dlugosci;
vector<int> visited;
vector<int> prefikso_sufiks;
const long long int mod=1e9+7;

void kmp(string slowo){
    prefikso_sufiks.resize(slowo.size()+10);
    prefikso_sufiks[0]=0;

    for(int i=1;i<slowo.size();i++) {
        int prefiks=prefikso_sufiks[i-1];
        while(prefiks>0 && slowo[prefiks]!=slowo[i]){
           prefiks=prefikso_sufiks[prefiks-1];
        }
        if(slowo[prefiks]==slowo[i]){
            prefiks++;
        }
        prefikso_sufiks[i]=prefiks;
    }
}
void oblicz_dp(int dlugosc){
    dp[dlugosc]=0;
    for(int i=0;i<dlugosci.size();i++){
        if(dlugosc-dlugosci[i]>=0){
            if(dp[dlugosc-dlugosci[i]]==-1){
                oblicz_dp(dlugosc-dlugosci[i]);
            }
            dp[dlugosc]=(dp[dlugosc]+dp[dlugosc-dlugosci[i]])%mod;
        }
    }
}
void wzorcowka(){
    dp.resize(m+10,-1);
    visited.resize(m+10,0);

    kmp(slowo);
    dlugosci.push_back(slowo.size());
    visited[slowo.size()]=1;

    int wskaznik1=slowo.size()-1;
    while(prefikso_sufiks[wskaznik1]>0){
        dlugosci.push_back(slowo.size()-prefikso_sufiks[wskaznik1]);
        wskaznik1=prefikso_sufiks[wskaznik1]-1;
    }

    dp[slowo.size()]=1;
    oblicz_dp(m);
    if(n==m){
        cout<<1;
    }else{
        cout<<dp[m];
    } 
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n>>m;
    cin>>slowo;

    wzorcowka();
    


    return 0;
}
 