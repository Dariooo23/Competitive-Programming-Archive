//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;

    vector<int> a;
    vector<int> b;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        a.push_back(c);
    }
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        b.push_back(c);
    }

    int wynik=0;
    for(int i=0;i<n;i++){
        wynik=(wynik)^(b[i]-a[i]-1);
    }
    if(wynik==0){
        cout<<"NIE"<<endl;
    }else{
        cout<<"TAK"<<endl;
        return;
    }

    a.clear();
    b.clear();
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