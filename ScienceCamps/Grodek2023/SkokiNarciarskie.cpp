//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> oceny;

int sprawdz_mediane(int mediana,int n,int r){
    vector<int> sumypref;
    sumypref.push_back(0);
    
    for(int i=1;i<=n;i++){
        if(oceny[i]>=mediana){
            sumypref.push_back(sumypref[i-1]+1);
        }else{
            sumypref.push_back(sumypref[i-1]-1);
        }
    }

    int mini=sumypref[0];
    int maks=-1e9;
    for(int i=r;i<=n;i++){
        maks=max(maks,sumypref[i]-mini);
        mini=min(mini,sumypref[i-r+1]);
    }

    return maks;
}
void solve(int n,int dl){
    long long int l=0,r=1e9,mid;
    oceny.resize(n+1);

    for(int i=1;i<=n;i++)cin>>oceny[i];

    while(l<r){
        mid=(l+r+1)/2;
        if(sprawdz_mediane(mid,n,dl)>0){
            l=mid;
        }else{
            r=mid-1;
        }
    }

    cout<<l<<endl;
    return;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int q;
    cin>>q;
    while(q--){
        int n,r;
        cin>>n>>r;
        solve(n,r);
    }
    return 0;
}
 