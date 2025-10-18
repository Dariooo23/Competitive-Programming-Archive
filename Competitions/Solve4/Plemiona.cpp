//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a;
    cin>>a;
    
    vector<string> slowa;
    for(int i=0;i<a;i++){
        string slowo;
        cin>>slowo;
        slowa.push_back(slowo);
    }
    for(int i=a-1;i>=0;i--){
        cout<<slowa[i]<<" ";
    }cout<<endl;
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}