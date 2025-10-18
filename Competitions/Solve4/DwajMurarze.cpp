#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int z;
    cin>>z;
    for(int i=0;i<z;i++){
        LL n;
        cin>>n;
        if(n==1){
            cout<<"Bajtomir"<<endl;
            continue;
        }
        n-=2;
        if(n%3==0){
            cout<<"Remis"<<endl;
        }else if((n/3)%2==0){
            cout<<"Bajtosz"<<endl;
        }else cout<<"Bajtomir"<<endl;
    }

    return 0;
}