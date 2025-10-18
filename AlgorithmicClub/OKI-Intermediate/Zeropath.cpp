
//Karol Dziekan
//https://codeforces.com/contest/1695/submission/243661082
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cout<<"AC";

    return 0;
}

//Karol Dziekan
/*#include <bits/stdc++.h>

using namespace std;

vector<vector<long long int>> wejscie,dpmax,dpmin;

void solve(){
    long long int n,m;
    cin>>n>>m;

    wejscie.resize(n+1,vector<long long int>(m+1));
    dpmax.resize(n+1,vector<long long int>(m+1,0));
    dpmin.resize(n+1,vector<long long int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>wejscie[i][j];
            if(i==1){
                dpmax[i][j]=dpmax[i][j-1]+wejscie[i][j];
                dpmin[i][j]=dpmin[i][j-1]+wejscie[i][j];
            }
            if(j==1){
                dpmax[i][j]=dpmax[i-1][j]+wejscie[i][j];
                dpmin[i][j]=dpmin[i-1][j]+wejscie[i][j];
            }
        }
    }

    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            dpmax[i][j]=max(dpmax[i][j-1],dpmax[i-1][j])+wejscie[i][j];
            dpmin[i][j]=min(dpmin[i][j-1],dpmin[i-1][j])+wejscie[i][j];
        }
    }

    if(dpmax[n][m]<0 || dpmin[n][m]>0 || dpmax[n][m]%2){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }

    wejscie.clear();
    dpmax.clear();
    dpmin.clear();
    return;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}*/