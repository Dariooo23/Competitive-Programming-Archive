//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tab;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    tab.resize(n+1,vector<int> (n+1,0));

    for(int i=1;i<=n;i++){
        cin>>tab[1][i];
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            tab[i][j]=tab[i-1][j]^tab[i-1][j+1];
        }
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            tab[i][j]=max({tab[i-1][j],tab[i-1][j+1],tab[i][j]});
        }
    }

    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<tab[i][j]<<" ";
        }cout<<endl;
    }*/

    int q;
    cin>>q;

    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<tab[b-a+1][a]<<endl;
    }



    return 0;
}