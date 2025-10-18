//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string slowo1,slowo2;
    cin>>slowo1;
    slowo2=slowo1;
    reverse(slowo2.begin(),slowo2.end());

    vector<vector<int>> dp(slowo1.size()+1,vector<int> (slowo2.size()+1,0));

    for(int i=0;i<slowo1.size();i++){
        for(int j=0;j<slowo2.size();j++){
            dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            if(slowo1[i]==slowo2[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }
        }
    }

    cout<<dp[slowo1.size()][slowo2.size()];
    return 0;
}