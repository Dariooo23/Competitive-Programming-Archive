//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector<int> pref(1000009);
vector<int> pierwsze(1000009);
void sito(){
    pierwsze[0]=1;
    pierwsze[1]=1;
    for(int i=2;i*i<=1000000;i++){
        if(pierwsze[i]==0){
            for(int j=i*i;j<=1000000;j=j+i){
                pierwsze[j]=1;
            }
        }
    }

    for(int i=1;i<=1000000;i++){
        if(pierwsze[i]==0){
            pref[i]=1;
        }
        pref[i]=pref[i]+pref[i-1];
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int q;
    cin>>q;
    sito();
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<pref[b]-pref[a-1]<<endl;
    }
    return 0;
}