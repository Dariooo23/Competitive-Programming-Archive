//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<long long int, long long int>,pair<long long int, long long int>>> punkty;
vector<pair<long long int,long long int>> pary_koncowe;

bool cmp(const pair<pair<long long int, long long int>,pair<long long int, long long int>> &a, const pair<pair<long long int, long long int>,pair<long long int, long long int>> &b){
    if(a.first==b.first){
        return a.first.second>b.first.second;
    }else{
        return a.first.first<b.first.first;
    }
}
struct CmpSet{
    bool operator()(const pair<pair<long long int, long long int>,pair<long long int, long long int>> &a, const pair<pair<long long int, long long int>,pair<long long int, long long int>> &b)const{
        if(a.first.second==b.first.second){
            return a.first.first>b.first.first;
        }else{
            return a.first.second<b.first.second;
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int n,wynik=0;
    cin>>n;

    for(int i=0;i<n;i++){
        long long int x,y;
        cin>>x>>y;
        punkty.push_back({{x,y},{0,i+1}});
    }
    for(int i=0;i<n;i++){
        long long int x,y;
        cin>>x>>y;
        punkty.push_back({{x,y},{1,i+1}});
    }

    stable_sort(punkty.begin(),punkty.end(),cmp);
    set<pair<pair<long long int, long long int>,pair<long long int, long long int>>,CmpSet> miotla;
    for(int i=0;i<punkty.size();i++){
        if(punkty[i].second.first==0){
            miotla.insert(punkty[i]);
        }else{
            pair<pair<long long int, long long int>,pair<long long int, long long int>> punkt=*miotla.lower_bound(punkty[i]);
            wynik=wynik+abs(punkty[i].first.first-punkt.first.first)+abs(punkt.first.second-punkty[i].first.second);
            miotla.erase(punkt);
            pary_koncowe.push_back({punkt.second.second,punkty[i].second.second});
        }
    }

    cout<<wynik<<endl;
    for(int i=0;i<pary_koncowe.size();i++){
        cout<<pary_koncowe[i].first<<" "<<pary_koncowe[i].second<<endl;
    }



    return 0;
}
 