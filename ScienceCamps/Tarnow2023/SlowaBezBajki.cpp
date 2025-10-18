//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const long long int mod=1e9+696969;
const long long int potega1=3;
const long long int potega2=7;

map<pair<long long int,long long int>,int> nowe_slowa;
vector<vector<long long int>> hashe1_pref;
vector<vector<long long int>> hashe2_pref;
vector<vector<long long int>> hashe1_suf;
vector<vector<long long int>> hashe2_suf;
vector<long long int> potegi1;
vector<long long int> potegi2;
vector<string> slowa;

void zrob_potegi(int dlugosc){
    potegi1[0]=1;
    potegi2[0]=1;
    for(int i=1;i<=dlugosc;i++){
        potegi1[i]=potegi1[i-1]*potega1;
        potegi2[i]=potegi2[i-1]*potega2;
    }

    return;
}
void hashowanie(int indeks,string slowo){
    hashe1_pref[indeks].resize(slowo.size()+1);
    hashe2_pref[indeks].resize(slowo.size()+1);
    hashe1_suf[indeks].resize(slowo.size()+1);
    hashe2_suf[indeks].resize(slowo.size()+1);

    hashe1_pref[indeks][1]=((slowo[0]-'a'+1)*potega1)%mod;
    hashe2_pref[indeks][1]=((slowo[0]-'a'+1)*potega2)%mod;

    for(int i=2;i<=slowo.size();i++){
        hashe1_pref[indeks][i]=(hashe1_pref[indeks][i-1]+(((slowo[i-1]-'a'+1)*potegi1[i])%mod))%mod;
        hashe2_pref[indeks][i]=(hashe2_pref[indeks][i-1]+(((slowo[i-1]-'a'+1)*potegi2[i])%mod))%mod;
    }

    hashe1_suf[indeks][slowo.size()]=((slowo[slowo.size()-1]-'a'+1)*potegi1[slowo.size()])%mod;
    hashe2_suf[indeks][slowo.size()]=((slowo[slowo.size()-1]-'a'+1)*potegi2[slowo.size()])%mod;

    for(int i=slowo.size()-1;i>=1;i--){
        hashe1_suf[indeks][i]=(hashe1_suf[indeks][i+1]+(((slowo[i-1]-'a'+1)*potegi1[i])%mod))%mod;
        hashe2_suf[indeks][i]=(hashe2_suf[indeks][i+1]+(((slowo[i-1]-'a'+1)*potegi2[i])%mod))%mod;
    }

    return;
}
int main()
{
    //std::ios_base::sync_with_stdio(0);
    //cout.tie(0);
    //cin.tie(0); 

    long long int n,wynik=0;
    cin>>n;

    hashe1_pref.resize(n+1);
    hashe2_pref.resize(n+1);
    hashe1_suf.resize(n+1);
    hashe2_suf.resize(n+1);
    potegi1.resize(500009);
    potegi2.resize(500009);
    zrob_potegi(500001);

    for(int i=0;i<n;i++){
        string slowo;
        cin>>slowo;

        hashowanie(i,slowo);
        slowa.push_back(slowo);
    }

    /*for(int i=0;i<n;i++){
        for(int j=1;j<=slowa[i].size();j++){
            cout<<hashe1_pref[i][j]<<" ";
        }cout<<endl;
        for(int j=1;j<=slowa[i].size();j++){
            cout<<hashe2_pref[i][j]<<" ";
        }cout<<endl;
        for(int j=1;j<=slowa[i].size();j++){
            cout<<hashe1_suf[i][j]<<" ";
        }cout<<endl;
        for(int j=1;j<=slowa[i].size();j++){
            cout<<hashe2_suf[i][j]<<" ";
        }cout<<endl;
    }*/

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=1;k<=slowa[i].size();k++){
                for(int l=1;l<=slowa[j].size();l++){
                    long long int hash1_pref=(hashe1_pref[i][k])%mod;
                    long long int hash2_pref=(hashe2_pref[i][k])%mod;

                    /*long long int hash12_pref=(hashe1_pref[j][l]*potegi1[k])%mod;
                    long long int hash22_pref=(hashe2_pref[j][l]*potegi2[k])%mod;

                    long long int hash1=(hash1_pref+hash12_pref)%mod;
                    long long int hash2=(hash2_pref+hash22_pref)%mod;*/

                    long long int hash1_suf=(hashe1_suf[j][l]*potegi1[k])%mod;
                    long long int hash2_suf=(hashe2_suf[j][l]*potegi2[k])%mod;

                    long long int hash1=(hash1_pref+hash1_suf)%mod;
                    long long int hash2=(hash2_pref+hash2_suf)%mod;

                    if(nowe_slowa.find({hash1,hash2})==nowe_slowa.end()){
                        nowe_slowa[{hash1,hash2}]=1;
                        wynik++;
                    }
                }
            }
        }
    }

    cout<<wynik;







    return 0;
}
 