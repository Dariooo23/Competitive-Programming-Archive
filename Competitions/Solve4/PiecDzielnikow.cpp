//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

map<long long int,long long int> mapa;
vector<int> pierwsze;

void sito(int n){
    pierwsze.resize(n+1);
    pierwsze[0]=0;
    pierwsze[1]=1;

    for(long long int i=2;i<=n;i++){
        if(pierwsze[i]==0){
            if(i*i*i*i<=1e18){
                mapa[i*i*i*i]=1;
            }
            for(long long int j=i*i;j<=n;j=j+i){
                pierwsze[j]=1;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    sito(33000);

    long long int q;
    cin>>q;
    while(q--){
        long long int a;
        cin>>a;

        if(mapa.find(a)==mapa.end()){
            cout<<"NIE"<<endl;
        }else{
            cout<<"TAK"<<endl;
        }
    }
    return 0;
}