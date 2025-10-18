//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,maks=0;
    cin>>n;

    vector<int> budynki(n+1);

    for(int i=1;i<=n;i++){
        cin>>budynki[i];
        maks=max(maks,budynki[i]);
    }

    for(int i=maks;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(budynki[j]>=i){
                cout<<"#";
            }else{
                cout<<".";
            }
        }cout<<endl;
    }
    return 0;
}