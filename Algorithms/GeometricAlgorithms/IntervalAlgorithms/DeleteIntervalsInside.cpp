//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct CmpSet{
    bool operator()(const pair<long long int,long long int> &a,const pair<long long int,long long int> &b)const{
        if(a.first==b.first){
            return a.second>b.second;
        }else{
            return a.first<b.first;
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //Program wczytuje przedzialy i usuwa z niego wszystkie te ktore zawieraja sie w innym przedziale
    int n;
    vector<pair<int,int>> przedzialy;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        przedzialy.push_back({a,b});
    }

    set<pair<long long int,long long int>,CmpSet> konce_przedzialow;
    sort(przedzialy.begin(),przedzialy.end());
    for(int i=0;i<przedzialy.size();i++){
        pair<long long int,long long int> przedzial=przedzialy[i];
        auto it1=konce_przedzialow.lower_bound({przedzial.second,przedzial.first});
        while(it1!=konce_przedzialow.end()){
            if((it1->first)>=przedzial.second){
                konce_przedzialow.erase(it1);
            }else{
                break;
            }
            it1=konce_przedzialow.lower_bound({przedzial.second,przedzial.first});
        }
        konce_przedzialow.insert({przedzial.second,przedzial.first});
    }

    //Pozostale przedzialy ktore sie nie zawieraja w innych znajduja sie w set'cie "konce_przedzialow";
    return 0;
}