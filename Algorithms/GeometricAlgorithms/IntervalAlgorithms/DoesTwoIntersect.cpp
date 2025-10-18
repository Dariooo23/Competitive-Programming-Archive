//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int,int>,int>> przedzialy;
stack<pair<int,int>> stos;

bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.first.first==b.first.first){
        return a.first.second>b.first.second;
    }else{
        return a.first.first<b.first.first;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,m;
    cin>>n>>m;

    for(int i=0;i<min(n,m);i++){
        int a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        przedzialy.push_back({{a,b},i+1});
    }

    sort(przedzialy.begin(),przedzialy.end(),cmp);

    stos.push({przedzialy[0].first.second,przedzialy[0].second});

    for(int i=1;i<min(n,m);i++){
        while(!stos.empty() && stos.top().first<=przedzialy[i].first.first){
            stos.pop();
        }

        if(!stos.empty()){
            if(stos.top().first<przedzialy[i].first.second){
                cout<<"TAK"<<endl;
                cout<<stos.top().second<<" "<<przedzialy[i].second;
                return 0;
            }
        }
        stos.push({przedzialy[i].first.second,przedzialy[i].second});
    }

    cout<<"NIE";
    return 0;
}