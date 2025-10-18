//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

void palindrom(int n,int k){
    if(k==1){
        for(int i=0;i<n;i++){
            cout<<"9";
        }
    }else{
        for(int i=0;i<n;i++){
            if(i%2==0){
                cout<<"9";
            }else{
                cout<<"8";
            }
        }
    }
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    if(n%2==0){
        if(k>1){
            cout<<"NIE";
        }else{
            palindrom(n,k);
        }
    }else{
        if(k>2){
            cout<<"NIE";
        }else{
            palindrom(n,k);
        }
    }
    return 0;
}