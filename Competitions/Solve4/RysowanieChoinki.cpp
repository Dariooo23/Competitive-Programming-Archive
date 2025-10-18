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
    for(int k=0;k<=2;k++){
        for(int i=1;i<=n+k;i++){
            for(int j=1;j<=n+2-i;j++){
                cout<<" ";
            }
            for(int j=1;j<=1+(i-1)*2;j++){
                cout<<"*";
            }
            cout<<'\n';
        }
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            cout<<" ";
        }
        for(int j=1;j<=3;j++){
            cout<<"*";
        }cout<<'\n';
    }

    return 0;
}