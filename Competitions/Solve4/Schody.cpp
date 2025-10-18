//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> pref(n+2);
    pref[0]=0;
    pref[n+1]=1e9+9;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        pref[i]=max(pref[i-1],a);
    }

    int q;
    cin>>q;
    while(q--){
        int a;
        cin>>a;

        int l=0,r=n,mid;
        while(l<r){
            mid=(l+r+1)/2;
            if(pref[mid]<=a){
                l=mid;
            }else{
                r=mid-1;
            }
        }

        cout<<l<<'\n';
    }

    return 0;
}