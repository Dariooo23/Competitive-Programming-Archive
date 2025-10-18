//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

void brut_k(int n,int k,int m,int q){
    set<pair<int,int>> dziury;

    for(int i=1;i<=m;i++){
        int a;
        cin>>a;
        dziury.insert({a,i});
    }

    while(q--){
        int a,b;
        cin>>a>>b;

        auto poczatek=dziury.lower_bound({a,0});
        auto koniec=dziury.upper_bound({b,1e9+9});

        if(poczatek==dziury.end() && koniec==dziury.end()){
            cout<<0<<endl;
        }else{
            if(koniec==dziury.end()){
                cout<<m-poczatek->second+1<<endl;
            }else{
                cout<<(koniec->second)-(poczatek->second)<<endl;
            }
        }
    }


}

void brut_q(int n,int k,int m,int q){
    set<int> dziury;

    for(int i=1;i<=m;i++){
        int a;
        cin>>a;
        dziury.insert(a);
    }

    int a,b,wynik=0;
    cin>>a>>b;
    auto it=dziury.lower_bound(a);
    while(it!=dziury.end() && *it<=b){
        wynik++;
        it=dziury.lower_bound(*it+k);
    }

    cout<<wynik<<endl;
}

void wzorcowka(int n,int k,int m,int q){
    set<pair<int,int>> dziury;
    vector<int> wejscie;
    vector<vector<int>> skoki;

    wejscie.resize(m+1);
    skoki.resize(21,vector<int> (m+1));

    for(int i=1;i<=m;i++){
        int a;
        cin>>a;
        dziury.insert({a,i});
        wejscie[i]=a;
    }

    for(int i=1;i<=m;i++){
        auto it=dziury.upper_bound({wejscie[i]+k-1,2e9+69});
        if(it!=dziury.end()){
            skoki[0][i]=it->second;
        }else{
            skoki[0][i]=m+1;
        }
    }

    for(int k=1;k<=20;k++){
        for(int x=1;x<=m;x++){
            if(skoki[k-1][x]==m+1){
                skoki[k][x]=m+1;
            }else{
                skoki[k][x]=skoki[k-1][skoki[k-1][x]];
            }
        }
    }

    while(q--){
        int a,b;
        cin>>a>>b;

        if(dziury.upper_bound({a,-1})==dziury.end()){
            cout<<"0"<<endl;
            continue;
        }
        int indeks=dziury.upper_bound({a,-1})->second;

        if(wejscie[indeks]>b){
            cout<<"0"<<endl;
            continue;
        }
        
        int wynik=1;
        for(int k=20;k>=0;k--){
            if(skoki[k][indeks]==m+1)continue;
            if(wejscie[skoki[k][indeks]]<=b){
                indeks=skoki[k][indeks];
                wynik=wynik+(1<<k);
            }
        }

        cout<<wynik<<endl;
    }




}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,k,m,q;
    cin>>n>>k>>m>>q;

    if(k==1){
        brut_k(n,k,m,q);
    }else{
        if(q==1){
            brut_q(n,k,m,q);
        }else{
            wzorcowka(n,k,m,q);
        }
    }

    return 0;
}