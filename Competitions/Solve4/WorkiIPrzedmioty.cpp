//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,m;
    cin>>n>>m;

    vector<vector<int>> wyjscie(m+1);
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        wyjscie[a].push_back(i);
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<wyjscie[i].size();j++){
            cout<<wyjscie[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}