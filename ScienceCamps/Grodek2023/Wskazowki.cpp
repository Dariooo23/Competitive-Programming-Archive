//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL wynik=0;
const LL mod=1e9+696969;
const LL podstawa1=1e9+7;
const LL podstawa2=1e9+9;

vector<vector<LL>> zegary;
vector<LL> potegi_podstawy1;
vector<LL> potegi_podstawy2;
vector<pair<LL,LL>> hash_zegarow;

map<pair<LL,LL>,LL> ilosc;
map<pair<LL,LL>,bool> czy_odwiedzony;
map<pair<LL,LL>,pair<LL,LL>> kolejny_hash;

void oblicz_potegi(LL n){
    potegi_podstawy1[0]=1;
    potegi_podstawy2[0]=1;
    for(int i=1;i<=n;i++){
        potegi_podstawy1[i]=(potegi_podstawy1[i-1]*podstawa1)%mod;
        potegi_podstawy2[i]=(potegi_podstawy2[i-1]*podstawa2)%mod;
    }return;
}
void stworz_cykl(LL nr,LL wskazowki,LL indeks,pair<LL,LL> hash1){
    pair<LL,LL> hash2=hash1,hash3={0,0};
    while(true){
        hash3.first=(hash2.first-((zegary[nr][indeks]*potegi_podstawy1[wskazowki-1])%mod)+mod)%mod;
        hash3.first=(hash3.first*podstawa1)%mod;
        hash3.first=(hash3.first+zegary[nr][indeks])%mod;

        hash3.second=(hash2.second-((zegary[nr][indeks]*potegi_podstawy2[wskazowki-1])%mod)+mod)%mod;
        hash3.second=(hash3.second*podstawa2)%mod;
        hash3.second=(hash3.second+zegary[nr][indeks])%mod;

        kolejny_hash[hash2]=hash3;
        hash2=hash3;
        if(indeks==0)break;
        indeks--;
    }

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    LL il_zegary,wskazowki,podzial;
    cin>>il_zegary>>wskazowki>>podzial;

      if(wskazowki==0){
        cout<<(il_zegary*(il_zegary-1))/2;
        return 0;
    }

    potegi_podstawy1.resize(1e6);
    potegi_podstawy2.resize(1e6);
    hash_zegarow.resize(1e6);
    zegary.resize(1e6);

    oblicz_potegi(1e5+1000);

    for(int i=1;i<=il_zegary;i++){
        LL pozycja1,pozycja2,pozycja3,hash1=0,hash2=0;

        
        cin>>pozycja1;
        pozycja3=pozycja1;
        for(int j=2;j<=wskazowki;j++){
            cin>>pozycja2;
            zegary[i].push_back(pozycja2-pozycja1);

            hash1=(hash1+((pozycja2-pozycja1)*potegi_podstawy1[j-2])%mod)%mod;
            hash2=(hash2+((pozycja2-pozycja1)*potegi_podstawy2[j-2])%mod)%mod;

            pozycja1=pozycja2;
        }

        zegary[i].push_back(podzial-pozycja1+pozycja3);
        hash1=(hash1+((podzial-pozycja1+pozycja3)*potegi_podstawy1[wskazowki-1])%mod)%mod;
        hash2=(hash2+((podzial-pozycja1+pozycja3)*potegi_podstawy2[wskazowki-1])%mod)%mod;
        hash_zegarow[i]={hash1,hash2};

        if(ilosc.find({hash1,hash2})!=ilosc.end()){
            ilosc[{hash1,hash2}]=ilosc[{hash1,hash2}]+1;
        }else{
            ilosc[{hash1,hash2}]=1;
        }

        /*for(int j=0;j<zegary[i].size();j++){
            cout<<zegary[i][j]<<" ";
        }cout<<endl;*/

        stworz_cykl(i,wskazowki,(LL)(zegary[i].size()-1),{hash1,hash2});
    }

    for(int i=1;i<=il_zegary;i++){
        LL wynikp=0;
        if(czy_odwiedzony.find(hash_zegarow[i])==czy_odwiedzony.end()){
            czy_odwiedzony[hash_zegarow[i]]=1;
            wynikp=wynikp+ilosc[hash_zegarow[i]];
            pair<LL,LL> hash1=kolejny_hash[hash_zegarow[i]];

            while(hash1!=hash_zegarow[i]){
                czy_odwiedzony[hash1]=1;
                wynikp=wynikp+ilosc[hash1];

                hash1=kolejny_hash[hash1];
            }

            wynik=wynik+((wynikp*(wynikp-1))/2);
        }
    }

    cout<<wynik;
    return 0;
}
 