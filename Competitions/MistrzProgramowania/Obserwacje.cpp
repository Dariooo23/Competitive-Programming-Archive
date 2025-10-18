//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

vector<set<int>> obserwuje;
vector<set<int>> jest_obserwowany;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    obserwuje.resize(n+1);
    jest_obserwowany.resize(n+1);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        obserwuje[a].insert(b);
        jest_obserwowany[b].insert(a);
    }

    for(int i=1;i<=n;i++){
        for(auto it=obserwuje[i].begin();it!=obserwuje[i].end();++it){
            jest_obserwowany[i].erase(*it);
        }

        cout<<jest_obserwowany[i].size()<<" ";
    }

    return 0;
}