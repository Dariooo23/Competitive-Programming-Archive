//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

bool cmp1(const pair<int,int> &a,const pair<int,int> &b){
    return a.first<b.first;
}
bool cmp2(const pair<int,int> &a,const pair<int,int> &b){
    return a.second<b.second;
}

void solve(){
    int a,b,c;
    cin>>a>>b>>c;

    vector<pair<int,int>> ananasy;
    ananasy.resize(c);

    for(int i=0;i<c;i++){
        cin>>ananasy[i].first>>ananasy[i].second;
    }

    int lewo,prawo,gora,dol;
    sort(ananasy.begin(),ananasy.end(),cmp1);
    lewo=ananasy[0].first-1;
    prawo=a-ananasy[ananasy.size()-1].first;

    sort(ananasy.begin(),ananasy.end(),cmp2);
    dol=ananasy[0].second-1;
    gora=b-ananasy[ananasy.size()-1].second;

    if((lewo^prawo^gora^dol)==0){
        cout<<"Bitek"<<endl;
    }else{
        cout<<"Bajtek"<<endl;
    }

    ananasy.clear();
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
 