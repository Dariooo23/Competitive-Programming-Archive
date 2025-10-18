#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int,int>>> kontenery;
vector<int> wynik;
int przedzialy[4000][4000];
int n,k,pierwiastek;


void policz(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<kontenery[i].size();j++){
            pair<int,int> para=kontenery[i][j];
            przedzialy[para.first][i%para.first]=przedzialy[para.first][i%para.first]+para.second;
        }
        for(int j=1;j<=pierwiastek;j++){
            wynik[i]=wynik[i]+przedzialy[j][i%j];
        }
    }
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin>>n>>k;
    pierwiastek=ceil(sqrt(n));
    kontenery.resize(200009);
    wynik.resize(200009);

    for(int i=0;i<k;i++){
        int a,l,d;
        cin>>a>>l>>d;
        if(d<=pierwiastek){
            kontenery[a].push_back({d,1});
            kontenery[a+l*d].push_back({d,-1});
        }else{
            for(int j=0;j<l;j++){
                wynik[a+d*j]++;
            }
        }
    }

    policz();
    for(int i=1;i<=n;i++){
        cout<<wynik[i]<<" ";
    }
    
    return 0;
}