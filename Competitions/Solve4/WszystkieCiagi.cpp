//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;



void rek(int dlugosc,vector<int> ciag,int k){
    if(dlugosc==ciag.size()){
        for(int i=0;i<ciag.size();i++){
            cout<<ciag[i]<<" ";
        }cout<<'\n';
    }else{
        for(int i=1;i<=k;i++){
            ciag.push_back(i);
            rek(dlugosc,ciag,k);
            ciag.pop_back();
        }
    }

    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    for(int i=1;i<=k;i++){
        rek(n,{i},k);
    }
    return 0;
}