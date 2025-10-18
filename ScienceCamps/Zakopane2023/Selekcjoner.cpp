//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> druzyny;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,m;
    cin>>n>>m;

    if(n==1){
        cout<<1<<" "<<1;
        return 0;
    }

    druzyny.resize(n,vector<int> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>druzyny[i][j];
        }
    }

    int l=0,r=1e9+69,mid,druzyna1=1,druzyna2=1;
    while(l<r){
        mid=(l+r+1)/2;

        int flaga=0;
        vector<int> maski(1<<m,-1);
        for(int i=0;i<n;i++){
            int maska=0;
            for(int j=0;j<m;j++){
                maska=maska*2;
                if(druzyny[i][j]>=mid)maska=maska+1;
            }
            maski[maska]=i+1;
        }

        for(int i=0;i<(1<<m);i++){
            for(int j=i+1;j<(1<<m);j++){
                if(maski[i]!=-1 && maski[j]!=-1){
                    if((i|j)==(1<<m)-1){
                        flaga=1;
                        druzyna1=maski[i];
                        druzyna2=maski[j];
                    }
                }
            }
        }
        if(flaga){
            l=mid;
        }else{
            r=mid-1;
        }
    }

    cout<<druzyna1<<" "<<druzyna2;

    
    return 0;
}