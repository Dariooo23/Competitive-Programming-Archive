//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int maks=1e9;

vector<int> dp;
vector<int> drzewa;
deque<int> kolejkamaks;

void push(int a){
    while(!kolejkamaks.empty() && ((dp[a]<dp[kolejkamaks.back()]) || (dp[a]==dp[kolejkamaks.back()] && drzewa[a]>drzewa[kolejkamaks.back()])))
        kolejkamaks.pop_back();

    kolejkamaks.push_back(a);
    return;
}
void pop(int a){
    while(!kolejkamaks.empty() && kolejkamaks.front()<a)
        kolejkamaks.pop_front();
}
int get(int a){
    if(kolejkamaks.empty())return maks;
    if(drzewa[kolejkamaks.front()]>drzewa[a]){
        return dp[kolejkamaks.front()];
    }else{
        return dp[kolejkamaks.front()]+1;
    }
}

void solve(int k,int n){
    dp.resize(n+1,0);
    dp[1]=0;

    push(1);
    for(int i=2;i<=n;i++){
        pop(max(1,i-k));
        dp[i]=get(i);
        push(i);
    }

    kolejkamaks.clear();
    cout<<dp[n]<<endl;
    dp.clear();
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    drzewa.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>drzewa[i];
    }

    int q;
    cin>>q;
    while(q--){
        int k;
        cin>>k;
        solve(k,n);
    }
    return 0;
}
 