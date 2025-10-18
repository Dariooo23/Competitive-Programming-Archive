//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct maks_sciezki{
    int a,b,c;
    int ia,ib,ic;
};

struct maks_dp{
    int a,b;
    int ia,ib;
};

vector<vector<pair<int,int>>> graf;
vector<maks_sciezki> sciezki;
vector<int> maks_gora;
vector<int> dp_gora;
vector<maks_dp> dp;

int wynikg=0;

void dfs1(int s,int p){
    for(const auto &v:graf[s]){
        if(v.first==p)continue;
        dfs1(v.first,s);
        int wynik=sciezki[v.first].a+v.second;
    
        if(wynik>sciezki[s].a){
            sciezki[s].c=sciezki[s].b;
            sciezki[s].ic=sciezki[s].ib;

            sciezki[s].b=sciezki[s].a;
            sciezki[s].ib=sciezki[s].ia;

            sciezki[s].a=wynik;
            sciezki[s].ia=v.first;
        }else{
            if(wynik>sciezki[s].b){
                sciezki[s].c=sciezki[s].b;
                sciezki[s].ic=sciezki[s].ib;

                sciezki[s].b=wynik;
                sciezki[s].ib=v.first;
            }else{
                if(wynik>sciezki[s].c){
                    sciezki[s].c=wynik;
                    sciezki[s].ic=v.first;
                }
            }
        }
    }
}

void dfs2(int s,int p){
    for(const auto &v:graf[s]){
        if(v.first==p)continue;
        dfs2(v.first,s);

        int wynik=max(dp[v.first].a,sciezki[v.first].a+sciezki[v.first].b);
        if(wynik>dp[s].a){
            dp[s].b=dp[s].a;
            dp[s].ib=dp[s].ia;
            dp[s].a=wynik;
            dp[s].ia=v.first;
        }else{
            if(wynik>dp[s].b){
                dp[s].b=wynik;
                dp[s].ib=v.first;
            }
        }
    
    }return;
}

void dfs3(int s,int p){
    for(const auto &v:graf[s]){
        if(v.first==p)continue;
        maks_gora[v.first]=max(maks_gora[v.first],maks_gora[s]+v.second);
        if(sciezki[s].ia==v.first){
            maks_gora[v.first]=max(maks_gora[v.first],sciezki[s].b+v.second);
        }else{
            maks_gora[v.first]=max(maks_gora[v.first],sciezki[s].a+v.second);
        }

        dfs3(v.first,s);
    }
}

void dfs4(int s,int p){
    int wynik=maks_gora[s];
    if(wynik>sciezki[s].a){
            sciezki[s].c=sciezki[s].b;
            sciezki[s].ic=sciezki[s].ib;

            sciezki[s].b=sciezki[s].a;
            sciezki[s].ib=sciezki[s].ia;

            sciezki[s].a=wynik;
            sciezki[s].ia=p;
        }else{
            if(wynik>sciezki[s].b){
                sciezki[s].c=sciezki[s].b;
                sciezki[s].ic=sciezki[s].ib;

                sciezki[s].b=wynik;
                sciezki[s].ib=p;
            }else{
                if(wynik>sciezki[s].c){
                    sciezki[s].c=wynik;
                    sciezki[s].ic=p;
                }
            }
        }

    for(const auto &v:graf[s]){
        if(v.first==p)continue;
        dfs4(v.first,s);
    }
}

void dfs5(int s,int p){
    for(const auto&v:graf[s]){
        if(v.first==p)continue;

        dp_gora[v.first]=max(dp_gora[v.first],dp_gora[s]);
        if(dp[s].ia==v.first){
            dp_gora[v.first]=max(dp_gora[v.first],dp[s].b);
        }else{
            dp_gora[v.first]=max(dp_gora[v.first],dp[s].a);
        }
        
        if(sciezki[s].ia==v.first){
            dp_gora[v.first]=max(dp_gora[v.first],sciezki[s].b+sciezki[s].c);
        }else{
            if(sciezki[s].ib==v.first){
                dp_gora[v.first]=max(dp_gora[v.first],sciezki[s].a+sciezki[s].c);
            }else{
                dp_gora[v.first]=max(dp_gora[v.first],sciezki[s].a+sciezki[s].b);
            }
        }

        dfs5(v.first,s);
    }
}

void dfs6(int s,int p){
    if(s==1){
        wynikg=max(wynikg,dp[s].a+dp[s].b);
    }else{
        wynikg=max(wynikg,dp_gora[s]+dp[s].a);
        wynikg=max(wynikg,dp[s].a+dp[s].b);

        if(sciezki[s].ia==p){
            wynikg=max(wynikg,dp_gora[s]+sciezki[s].b+sciezki[s].c);
        }else{
            if(sciezki[s].ib==p){
                wynikg=max(wynikg,dp_gora[s]+sciezki[s].a+sciezki[s].c);
            }else{
                wynikg=max(wynikg,dp_gora[s]+sciezki[s].a+sciezki[s].b);
            }
        }
    }
    for(const auto&v:graf[s]){
        if(v.first==p)continue;
        dfs6(v.first,s);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    dp.resize(n+1);
    graf.resize(n+1);
    dp_gora.resize(n+1);
    sciezki.resize(n+1);
    maks_gora.resize(n+1);

    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graf[a].push_back({b,c});
        graf[b].push_back({a,c});
    }

    dfs1(1,0);
    dfs2(1,0);
    dfs3(1,0);
    dfs4(1,0);
    dfs5(1,0);
    dfs6(1,0);

    /*for(int i=1;i<=n;i++){
        cout<<i<<" "<<dp_gora[i]<<endl;
    }*/
    
    cout<<wynikg;


    return 0;
}
