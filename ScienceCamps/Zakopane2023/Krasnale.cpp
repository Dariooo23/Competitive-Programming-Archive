//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> krasnale;
map<int,int> pozycje;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        krasnale.push_back(a);
    }

    sort(krasnale.begin(),krasnale.end());

    for(int i=0;i<n;i++){
        pozycje[krasnale[i]]=1;
    }

    for(int i=0;i<n;i++){
        if(pozycje.find(krasnale[i]+m)!=pozycje.end()){
            pozycje[krasnale[i]+m]=max(pozycje[krasnale[i]+m],pozycje[krasnale[i]]+1);
        }
    }

    int wynik=0,koniec;
    for(auto it=pozycje.begin();it!=pozycje.end();++it){
        if(it->second>wynik){
            wynik=it->second;
            koniec=it->first;
        }
    }

    wynik=0;
    vector<int> wyjscie;
    while(pozycje.find(koniec)!=pozycje.end()){
        wyjscie.push_back(koniec);
        koniec=koniec-m;
    }

    cout<<wyjscie.size()<<endl;
    for(int i=wyjscie.size()-1;i>=0;i--){
        cout<<wyjscie[i]<<" ";
    }


    return 0;
}