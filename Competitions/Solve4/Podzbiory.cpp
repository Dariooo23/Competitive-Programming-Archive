//Karol Dziekan
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;
    for(short int k=1;k<=n;++k){
        vector<vector<short int>> wyjscie;

        for(int i=1;i<=(1<<(n-k));++i){
            vector<short int> ciag;
            ciag.push_back(k);
            for(short int j=0;j<n-k;++j){
                if((i&(1<<(j)))){
                    ciag.push_back(j+k+1);
                }
            }

            wyjscie.push_back(ciag);
            ciag.clear();
        }


        sort(wyjscie.begin(),wyjscie.end());
        for(int i=0;i<wyjscie.size();++i){
            for(short int j=0;j<wyjscie[i].size();++j){
                cout<<wyjscie[i][j]<<" ";
            }cout<<'\n';
        }

        wyjscie.clear();
    }

    return 0;
}