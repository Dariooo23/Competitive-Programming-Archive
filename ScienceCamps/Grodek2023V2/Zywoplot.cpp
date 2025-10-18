//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long int n,m;
    cin>>n>>m;

    vector<long long int> nasiona(n+1);
    for(int i=1;i<=n;i++){
        cin>>nasiona[i];
    }
    long long int l=0,r=1e17+100,mid;
    while(l<r){
        mid=(l+r+1)/2;
        long long int suma=0;
        vector<long long int> nawoz(n+1,0); 
        for(int i=1;i<=n;i++){ 
            long long int nawozenie=(mid-1)/nasiona[i]+1;
            nawoz[i]=max((long long int)0,nawoz[i]+nawozenie);
            if(nawoz[i]==0){
                if(i!=n)suma=suma+1;
            }else{
                suma=suma+(2*nawoz[i]-1);
                if(i+1<=n)nawoz[i+1]=nawoz[i+1]-(nawoz[i]-1);
            }
            if(suma>m)break;
        }
        if(m-suma>=0){
            l=mid;
        }else{
            r=mid-1;
        }
    }

    cout<<l<<'\n';
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}