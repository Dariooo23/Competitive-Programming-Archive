//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<long long int> tab;
long long int bin(long long int d,long long int n,long long int k){
    vector<long long int> dp(n+2);
    for(int i=1;i<=n+1;i++){
        dp[i]=dp[i-1]+tab[i-1];
    }
    for(int i=1;i<=3;i++){
        deque<pair<long long int, long long int>> kolejka={{0,0}};
        for(int j=1;j<=n+1;j++){
            pair<long long int,long long int> pozycja={dp[j],j};
            while(!kolejka.empty() && kolejka.back().first>=pozycja.first){
                kolejka.pop_back();
            }kolejka.push_back(pozycja);

            if(kolejka.front().second==j-d-1)kolejka.pop_front();
            dp[j]=min(dp[j-1],kolejka.front().first)+tab[j-1];
        }
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


    long long int l=0,r=n+1,mid;
    while(l+1<r){
        mid=(l+r)/2;
        if(bin(mid,n,k)>k){
            l=mid;
        }else{
            r=mid;
        }
    }

    cout<<r;
    return 0;
}