//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    vector<int> boki(3);
    cin>>boki[0]>>boki[1]>>boki[2];
    sort(boki.begin(),boki.end());
    if(boki[0]+boki[1]>boki[2]){
        cout<<"TAK";
    }else{
        cout<<"NIE";
    }
    return 0;
}