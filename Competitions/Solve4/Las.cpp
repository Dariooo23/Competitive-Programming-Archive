//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector<pair<int,pair<int,int>>> wejscie;
vector<vector<int>> uzyte;
vector<int> rozmiar;
vector<int> parent;

int find(int x){
    if(x!=parent[x]){
        parent[x]=find(parent[x]);
    }

    return parent[x];
}
void uni(int x,int y){
    x=find(x);
    y=find(y);

    if(x==y)return;
    if(rozmiar[x]<rozmiar[y])swap(x,y);

    rozmiar[x]=rozmiar[x]+rozmiar[y];
    rozmiar[y]=rozmiar[x];
    parent[y]=x;
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    parent.resize(n*n);
    rozmiar.resize(n*n);
    uzyte.resize(n,vector<int>(n,0));

    for(int i=0;i<n*n;i++){
        parent[i]=i;
        rozmiar[i]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            wejscie.push_back({a,{i,j}});
        }
    }

    sort(wejscie.begin(),wejscie.end());
    for(int i=0;i<n*n;i++){
        if(wejscie[i].second.first-1>=0){
            if(uzyte[wejscie[i].second.first-1][wejscie[i].second.second]==1){
                uni((n*(wejscie[i].second.first-1)+(wejscie[i].second.second)),((n*wejscie[i].second.first)+wejscie[i].second.second));
                if(rozmiar[find(n*wejscie[i].second.first+wejscie[i].second.second)]>=k){
                    cout<<wejscie[i].first<<endl;
                    return 0;
                }
            }
        }
        if(wejscie[i].second.first+1<n){
            if(uzyte[wejscie[i].second.first+1][wejscie[i].second.second]==1){
                uni((n*(wejscie[i].second.first+1)+(wejscie[i].second.second)),((n*wejscie[i].second.first)+wejscie[i].second.second));
                if(rozmiar[find(n*wejscie[i].second.first+wejscie[i].second.second)]>=k){
                    cout<<wejscie[i].first<<endl;
                    return 0;
                }
            }
        }
        if(wejscie[i].second.second+1<n){
            if(uzyte[wejscie[i].second.first][wejscie[i].second.second+1]==1){
                uni((n*(wejscie[i].second.first)+(wejscie[i].second.second+1)),((n*wejscie[i].second.first)+wejscie[i].second.second));
                if(rozmiar[find(n*wejscie[i].second.first+wejscie[i].second.second)]>=k){
                    cout<<wejscie[i].first<<endl;
                    return 0;
                }
            }
        }
        if(wejscie[i].second.second-1>=0){
            if(uzyte[wejscie[i].second.first][wejscie[i].second.second-1]==1){
                uni((n*(wejscie[i].second.first)+(wejscie[i].second.second-1)),((n*wejscie[i].second.first)+wejscie[i].second.second));
                if(rozmiar[find(n*wejscie[i].second.first+wejscie[i].second.second)]>=k){
                    cout<<wejscie[i].first<<endl;
                    return 0;
                }
            }
        }
        uzyte[wejscie[i].second.first][wejscie[i].second.second]=1;
    }
    return 0;
}