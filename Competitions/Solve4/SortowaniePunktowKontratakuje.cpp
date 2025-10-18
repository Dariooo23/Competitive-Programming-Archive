//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second==b.second){
        return a.first<b.first;
    }else{
        return a.second<b.second;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    vector<pair<long long int,long long int>> punkty;

    for(int i=0;i<n;i++){
        long long int a,b;
        cin>>a>>b;
        punkty.push_back({a,b});
    }

    sort(punkty.begin(),punkty.end(),cmp);

    for(int i=0;i<n;i++){
        cout<<punkty[i].first<<" "<<punkty[i].second<<endl;
    }
    return 0;
}