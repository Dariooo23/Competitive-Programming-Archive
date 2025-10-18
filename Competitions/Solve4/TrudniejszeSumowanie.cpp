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
    
    vector<long long int> pref(n+1);
    pref[0]=0;
    for(int i=1;i<=n;i++){
        long long int a;
        cin>>a;
        pref[i]=pref[i-1]+a;
    }

    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<pref[b]-pref[a-1]<<'\n';
    }
    return 0;
}