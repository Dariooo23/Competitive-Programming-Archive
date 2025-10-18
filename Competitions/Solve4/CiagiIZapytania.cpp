//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;

    vector<int> pozycje(1000009);
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(pozycje[a]==0){
            pozycje[a]=i;
        }
    }

    for(int i=0;i<q;i++){
        int a;
        cin>>a;
        if(pozycje[a]==0){
            cout<<"NIE"<<'\n';
        }else{
            cout<<pozycje[a]<<'\n';
        }
    }
    return 0;
}