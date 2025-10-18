//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
       
    int n,m;
    cin>>n>>m;

    vector<int> dzieci(31);
    vector<vector<int>> buty(31);

    for(int i=1;i<=n;i++){
        int s;
        cin>>s;
        dzieci[s-20]++;
    }

    for(int i=1;i<=m;i++){
        int r,c;
        cin>>r>>c;
        buty[r-20].push_back(c);
    }

    int wynik=0;
    for(int i=20;i<=50;i++){
        sort(buty[i-20].begin(),buty[i-20].end());
        
        if(buty[i-20].size()<dzieci[i-20]){
            cout<<"NIE"<<endl;
            return 0;
        }
        for(int j=0;j<dzieci[i-20];j++){
            wynik+=buty[i-20][j];
        }
    }

    cout<<wynik<<endl;
    return 0;
}