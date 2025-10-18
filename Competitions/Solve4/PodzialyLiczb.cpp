//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n;
void rek(int poczatek,int suma, vector<int> ciag){
    if(suma==n){
        for(int i=0;i<ciag.size();i++){
            cout<<ciag[i]<<" ";
        }cout<<'\n';
    }else{
        for(int i=poczatek;i<=n;i++){
            if(suma+i<=n){
                ciag.push_back(i);
                rek(i,suma+i,ciag);
                ciag.pop_back();
            }
        }
    }
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n;

    for(int i=1;i<=n;i++){
        rek(i,i,{i});
    }
    return 0;
}