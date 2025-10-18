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

    vector<pair<int,int>> przedzialy(n);
    for(int i=0;i<n;i++){
        cin>>przedzialy[i].first>>przedzialy[i].second;
    }

    sort(przedzialy.begin(),przedzialy.end());
    int koniec=przedzialy[0].second,usuniete=0;
    for(int i=1;i<n;i++){
        if(przedzialy[i].first<koniec){
            usuniete++;
            koniec=min(koniec,przedzialy[i].second);
        }else{
            koniec=przedzialy[i].second;
        }
    }

    cout<<n-usuniete;
    return 0;
}