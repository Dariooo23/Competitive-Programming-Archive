//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<pair<long long int,long long int>> panele;
set<pair<long long int,long long int>> panele_set;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,m,x,y,k;
    cin>>n>>m>>x>>y>>k;

    panele.resize(m+1);
    for(int i=1;i<=m;i++){
        cin>>panele[i].first>>panele[i].second;
    }
    for(int i=1;i<=m;i++){
        panele_set.insert({panele[i].second,panele[i].first});
    }


    for(int i=1;i<=n;i++){
        pair<long long int,long long int> punkt3;
        cin>>punkt3.first>>punkt3.second;

        if(punkt3.second<=k){
            cout<<":)"<<endl;
            continue;
        }

        auto it=panele_set.lower_bound({punkt3.first,-1});
        pair<long long int,long long int> panel;
        if(it==panele_set.end()){
            cout<<":)"<<endl;
            continue;
        }else{
            panel.first=it->second;
            panel.second=it->first;
        }

        if(panel.first>punkt3.first){
            cout<<":)"<<endl;
            continue;
        }

        long long int A=punkt3.second-k;
        long long int B1=punkt3.first-panel.first;
        long long int B2=punkt3.first-panel.second;
        long long int flaga1=A*punkt3.first-B1*punkt3.second;
        long long int flaga2=A*punkt3.first-B2*punkt3.second;

        if(flaga1>=0 || flaga2<=x*A){
            cout<<":)"<<endl;
        }else{
            cout<<":("<<endl;
        }
    }

    return 0;
}