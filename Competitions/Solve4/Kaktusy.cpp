//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<long long int> tab;
long long int suma(long long int n,long long int k){
    vector<long long int> dp(n+2);
    deque<pair<long long int, long long int>> kolejka={{0,0}};

    for(int j=1;j<=n+1;j++){
        pair<long long int,long long int> pozycja={dp[j-1],j-1};
        while(!kolejka.empty() && kolejka.back().first>=pozycja.first){
            kolejka.pop_back();
        }
        
        kolejka.push_back(pozycja);
        if(kolejka.front().second==j-k-1)kolejka.pop_front();
        dp[j]=min(dp[j-1],kolejka.front().first)+tab[j-1];
    }
    
    return dp[n+1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    long long int n,k;
    cin>>n>>k;

    tab.resize(n);
    for(int i=0;i<n;i++)cin>>tab[i];
    tab.push_back(0);


    cout<<suma(n,k);
    return 0;
}