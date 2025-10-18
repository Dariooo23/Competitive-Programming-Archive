//Karol Dziekan
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void solve(){
    ordered_set pbds;
    char polecenie;
    while(cin>>polecenie){
        int liczba;
        if(polecenie=='K'){
            cin>>liczba;
            return;
        }
        if(polecenie=='A'){
            cin>>liczba;
            pbds.insert(liczba);
        }
        if(polecenie=='E'){
            cin>>liczba;
            if(pbds.find(liczba)==pbds.end()){
                cout<<"brak"<<endl;
            }else{
                pbds.erase(liczba);
            }
        }
        if(polecenie=='S'){
            cin>>liczba;
            if(pbds.find_by_order(liczba-1)==pbds.end()){
                cout<<"brak"<<endl;
            }else{
                cout<<*pbds.find_by_order(liczba-1)<<endl;
            }
        }
    }
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