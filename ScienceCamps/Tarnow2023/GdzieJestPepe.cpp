//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct odcinek{
    bool ktora_os;
    int x1,y1,x2,y2;
    int dlugosc;
};
bool CmpVec(const pair<pair<int,int>,pair<int,int>> &a, const pair<pair<int,int>,pair<int,int>> &b){
    if(a.first.second==b.first.second){
        return a.first.first>b.first.first;
    }else{
        return a.first.second<b.first.second;
    }
}

vector<odcinek> odcinki;

int zamiatanie(int a){
    set<int> miotla;
    vector<pair<pair<int,int>,pair<int,int>>> odcinki2;

    for(int i=0;i<odcinki.size();i++){
        if(odcinki[i].ktora_os==1 && odcinki[i].dlugosc>=2*a){
            odcinki2.push_back({{1,odcinki[i].x1+a},{odcinki[i].y1,odcinki[i].y1}});
            odcinki2.push_back({{-1,odcinki[i].x2-a},{odcinki[i].y1,odcinki[i].y1}});
        }else{
            odcinki2.push_back({{0,odcinki[i].x1},{odcinki[i].y1+a,odcinki[i].y2-a}});
        }
    }

    sort(odcinki2.begin(),odcinki2.end(),CmpVec);
    for(int i=0;i<odcinki2.size();i++){
        if(odcinki2[i].first.first==1){
            miotla.insert(odcinki2[i].second.first);
        }
        if(odcinki2[i].first.first==-1){
            miotla.erase(odcinki2[i].second.first);
        }
        if(odcinki2[i].first.first==0){
            auto it=miotla.lower_bound(odcinki2[i].second.first);
            if(it!=miotla.end() && (*it)<=odcinki2[i].second.second){
                return 1;
            }
        }
    }

    odcinki2.clear();
    return 0;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        odcinki.push_back({1,a,c,b,c,b-a});
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        odcinki.push_back({0,c,a,c,b,b-a});
    }

    int l=1,r=1e9,mid;
    while(l<r){
        mid=(l+r)/2;
        
        if(zamiatanie(mid)){
            l=mid+1;
        }else{
            r=mid;
        }
    }

    if(zamiatanie(l)==1){
        cout<<l;
    }else{
        cout<<l-1;
    }
    return 0;
}
 