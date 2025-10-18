//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

int wynik=0;
vector<bool> zestrzelone;
vector<pair<int,int>> stormtroopers;

int iloczyn(int x1, int y1, int x2, int y2, int x3, int y3){
    return (x1-x3)*(y1-y2)-(x1-x2)*(y1-y3);
}

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0);
    cin.tie(0);
    
    int n,x0,y0;
    cin>>n>>x0>>y0;

    zestrzelone.resize(n);
    stormtroopers.resize(n);
    for(int i=0;i<n;i++){
        cin>>stormtroopers[i].first>>stormtroopers[i].second;
    }

    for(int i=0;i<n;i++){
        if(zestrzelone[i]==1){
            continue;
        }

        for(int j=i+1;j<n;j++){
            if(iloczyn(x0,y0,stormtroopers[i].first,stormtroopers[i].second,
            stormtroopers[j].first,stormtroopers[j].second)==0){
                zestrzelone[j]=1;
            }
        }
        wynik++;
    }

    cout<<wynik;
    return 0;
}