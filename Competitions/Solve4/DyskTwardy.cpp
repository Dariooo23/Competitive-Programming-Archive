//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> par;

struct Fau{
    Fau(int n){
        par.resize(n+1);
        for (int i=1; i<=n;i++){
            par[i]=i;
        }
    }
    int find(int a){
        if (par[a]!=a){
            par[a]=find(par[a]);
        }
        return par[a];
    }
    void uni(int a, int b) {
        a=find(a);
        b=find(b);
        if(a!=b){
            if(a>b)swap(a,b);
            par[a]=b;
        }
        
    }
};

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    Fau fau(n+1);

    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        int pozycja=fau.find(a+1);

        if(pozycja==n+1){
            cout<<"NIE"<<'\n';
        }else{
            cout<<pozycja<<'\n';
        }
        
        fau.uni(a,pozycja);
    }
    return 0;
}
 