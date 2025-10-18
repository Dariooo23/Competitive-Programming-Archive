//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int mod=1e9+7;
vector<long long int> dp;
vector<long long int> prefiks_dp;

vector<pair<long long int,long long int>> trasy;
vector<pair<long long int,long long int>> trasybp;

vector<vector<pair<pair<int,int>,int>>> grupy;
vector<vector<pair<pair<int,int>,pair<long long int,long long int>>>> przedzialy_grup;

vector<long long int> skoki;
vector<long long int> konce;

struct CmpSet{
    bool operator()(const pair<long long int,long long int> &a,const pair<long long int,long long int> &b)const{
        if(a.first==b.first){
            return a.second>b.second;
        }else{
            return a.first<b.first;
        }
    }
};


long long int stworz_przedzialy_grup(long long int ilosc_kontrol){
    vector<pair<long long int,long long int>> przedzialy;
    for(int i=0;i<trasybp.size();i++){
        przedzialy.push_back({trasybp[i].first,i});
        przedzialy.push_back({trasybp[i].second,i});
    }


    sort(przedzialy.begin(),przedzialy.end());
    long long int wskaznik=1,nr_przedzialu=1;
    for(int i=1;i<przedzialy.size() && wskaznik!=ilosc_kontrol+1;i++){
        if(przedzialy[i].first-przedzialy[i-1].first!=0 && przedzialy[i-1].first>=grupy[wskaznik][0].first.first){
            przedzialy_grup[wskaznik].push_back({{wskaznik,nr_przedzialu},{przedzialy[i-1].first,przedzialy[i].first}});
            nr_przedzialu++;
        }
        if(przedzialy[i].first==grupy[wskaznik][0].first.second){
            wskaznik++;
        }
    } 
    return nr_przedzialu-1;
}
void oblicz_skoki(long long int ilosc_kontrol,long long int ilosc_przedzialow){
    for(int i=1;i<=ilosc_kontrol;i++){
        long long int wskaznik1=0,wskaznik2=0;
        while(wskaznik1!=grupy[i-1].size() && wskaznik2!=przedzialy_grup[i].size()){
            if(grupy[i-1][wskaznik1].first.second<przedzialy_grup[i][wskaznik2].second.second){
                wskaznik1++;
                if(wskaznik1==grupy[i-1].size())break;
            }
            if(grupy[i-1][wskaznik1].first.second>przedzialy_grup[i][wskaznik2].second.second){
                wskaznik2++;
                if(wskaznik2==przedzialy_grup[i].size())break;
            }
            if(grupy[i-1][wskaznik1].first.second==przedzialy_grup[i][wskaznik2].second.second){
                konce[grupy[i-1][wskaznik1].second]=przedzialy_grup[i][wskaznik2].first.second;
                wskaznik1++;
                wskaznik2++;
                if(wskaznik1==grupy[i-1].size())break;
                if(wskaznik2==przedzialy_grup[i].size())break;
            }
        }
    }
    for(int i=1;i<=ilosc_kontrol;i++){
        int wskaznik1=0,wskaznik2=0;
        while(wskaznik1!=grupy[i].size() && wskaznik2!=przedzialy_grup[i].size()){
            if(grupy[i][wskaznik1].first.first<przedzialy_grup[i][wskaznik2].second.second){
                wskaznik1++;
                if(wskaznik1==grupy[i].size())break;
            }
            if(grupy[i][wskaznik1].first.first>=przedzialy_grup[i][wskaznik2].second.second){
                skoki[przedzialy_grup[i][wskaznik2].first.second]=konce[grupy[i][wskaznik1].second];
                wskaznik2++;
                if(wskaznik2==przedzialy_grup[i].size())break;    
            }
        }
        while(wskaznik2!=przedzialy_grup[i].size()){
            if(i+1<=ilosc_kontrol){
                skoki[przedzialy_grup[i][wskaznik2].first.second]=przedzialy_grup[i+1][przedzialy_grup[i+1].size()-1].first.second;
            }else{
                skoki[przedzialy_grup[i][wskaznik2].first.second]=0;
            }
            wskaznik2++;
        }
    }
}
long long int oblicz_dp(long long int nr_kontroli,long long int ilosc_kontrol,long long int ilosc_przedzialow){
    if(nr_kontroli==0){
        oblicz_dp(nr_kontroli+1,ilosc_kontrol,ilosc_przedzialow);
        return prefiks_dp[przedzialy_grup[nr_kontroli+1][przedzialy_grup[nr_kontroli+1].size()-1].first.second];
    }


    if(nr_kontroli==ilosc_kontrol){
        long long int poczatek=grupy[nr_kontroli][grupy[nr_kontroli].size()-1].first.first,koniec=grupy[nr_kontroli][grupy[nr_kontroli].size()-1].first.second;
        for(int i=0;i<przedzialy_grup[nr_kontroli].size();i++){
            if(przedzialy_grup[nr_kontroli][i].second.first>=poczatek && przedzialy_grup[nr_kontroli][i].second.second<=koniec){
                dp[przedzialy_grup[nr_kontroli][i].first.second]=(przedzialy_grup[nr_kontroli][i].second.second-przedzialy_grup[nr_kontroli][i].second.first)%mod;
            }
        }

        prefiks_dp[przedzialy_grup[nr_kontroli][0].first.second]=dp[przedzialy_grup[nr_kontroli][0].first.second];
        for(int i=1;i<przedzialy_grup[nr_kontroli].size();i++){
            prefiks_dp[przedzialy_grup[nr_kontroli][i].first.second]=(prefiks_dp[przedzialy_grup[nr_kontroli][i-1].first.second]+dp[przedzialy_grup[nr_kontroli][i].first.second])%mod;
        }
    }


    if(nr_kontroli!=ilosc_kontrol && nr_kontroli!=0){
        oblicz_dp(nr_kontroli+1,ilosc_kontrol,ilosc_przedzialow);
        for(int i=0;i<przedzialy_grup[nr_kontroli].size();i++){
            if(skoki[przedzialy_grup[nr_kontroli][i].first.second]>=przedzialy_grup[nr_kontroli][0].first.second)
            dp[przedzialy_grup[nr_kontroli][i].first.second]=(prefiks_dp[skoki[przedzialy_grup[nr_kontroli][i].first.second]]*(przedzialy_grup[nr_kontroli][i].second.second-przedzialy_grup[nr_kontroli][i].second.first))%mod;
        }

        prefiks_dp[przedzialy_grup[nr_kontroli][0].first.second]=dp[przedzialy_grup[nr_kontroli][0].first.second];
        for(int i=1;i<przedzialy_grup[nr_kontroli].size();i++){
            prefiks_dp[przedzialy_grup[nr_kontroli][i].first.second]=(prefiks_dp[przedzialy_grup[nr_kontroli][i-1].first.second]+dp[przedzialy_grup[nr_kontroli][i].first.second])%mod;
        }
    }

    return 0;
}

void solve(){
    long long int stacje,ilosc_tras;
    cin>>stacje>>ilosc_tras;


    for(int i=0;i<ilosc_tras;i++){
        int poczatek,koniec;
        cin>>poczatek>>koniec;
        trasy.push_back({poczatek,koniec});
    }


    set<pair<long long int,long long int>,CmpSet> konce_tras;
    sort(trasy.begin(),trasy.end());
    for(int i=0;i<trasy.size();i++){
        pair<long long int,long long int> przedzial=trasy[i];
        auto it1=konce_tras.lower_bound({przedzial.second,przedzial.first});
        while(it1!=konce_tras.end()){
            if((it1->first)>=przedzial.second){
                konce_tras.erase(it1);
            }else{
                break;
            }
            it1=konce_tras.lower_bound({przedzial.second,przedzial.first});
        }
        konce_tras.insert({przedzial.second,przedzial.first});
    }
    for(auto it=konce_tras.begin();it!=konce_tras.end();++it){
        trasybp.push_back({it->second,it->first});
    }konce_tras.clear();


    dp.resize(ilosc_tras*2+10,0);
    grupy.resize(ilosc_tras*2+10);
    skoki.resize(ilosc_tras*2+10);
    konce.resize(ilosc_tras*2+10);
    prefiks_dp.resize(ilosc_tras*2+10,0);
    przedzialy_grup.resize(ilosc_tras*2+10);


    long long int kontrola=0,ilosc_kontrol=0;
    for(int i=0;i<trasybp.size();i++){
        if(trasybp[i].first>=kontrola){
            kontrola=trasybp[i].second;
            ilosc_kontrol++;
        }
        grupy[ilosc_kontrol].push_back({trasybp[i],i});
    }

    long long int ilosc_przedzialow=stworz_przedzialy_grup(ilosc_kontrol);
    oblicz_skoki(ilosc_kontrol,ilosc_przedzialow);
    cout<<ilosc_kontrol<<" "<<oblicz_dp(0,ilosc_kontrol,ilosc_przedzialow)<<endl;


    dp.clear();
    skoki.clear();
    grupy.clear();
    konce.clear();
    trasy.clear();
    trasybp.clear();
    prefiks_dp.clear();
    przedzialy_grup.clear();
}


int main()
{
    //Ten kod można idealnie opisać dwoma słowami "Dobre gówno".
    //Nigdy więcej takiego badziewia.
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}