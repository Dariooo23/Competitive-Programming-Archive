// Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
#define endl '\n'

LL modulo =1e9+7;

vector<LL> silnia;
vector<vector<LL>> dp;
vector<LL> dzielniki_k;
vector<vector<LL>> newton;

LL potega(LL a,LL b){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        LL wynik=potega(a,b/2);
        return (wynik*wynik)%modulo;
    }else{
        return (a*potega(a,b-1))%modulo;
    }
}
void oblicz_newton(int n){
    newton.resize(n+1);
    newton[0].push_back(1);

    for (int i =1;i <= n; i++){
        newton[i].push_back(1);
        for (int j=0;j<newton[i-1].size()-1;j++){
            newton[i].push_back((newton[i-1][j]+newton[i-1][j+1])%modulo);
        }
        newton[i].push_back(1);
    }
    return;
}
void oblicz_silnia(LL n){
    silnia.resize(n+1);
    silnia[0]=1;

    for (int i=1;i<=n;i++){
        silnia[i]=(silnia[i-1]*i)%modulo;
    }
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    oblicz_newton(1000);
    oblicz_silnia(100009);

    for(LL i=1;i<=k;i++){
        if (k%i==0){
            dzielniki_k.push_back(i);
        }
    }

    dp.resize(n+1,vector<LL>(dzielniki_k.size()+10,0));

    for(LL i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(LL i=0;i<dzielniki_k.size();i++){
        dp[0][i]=1;
    }

    for(LL j=1;j<dzielniki_k.size();j++){
        LL najwiekszy_dzielnik_indeks=0;
        LL akt_dzielnik=dzielniki_k[j];

        for(int i=j-1;i>=0;i--){
            if(akt_dzielnik%dzielniki_k[i]==0){
                najwiekszy_dzielnik_indeks=i;
                break;
            }
        }

        for(int i=0;i<=n;i++){
            dp[i][j]=dp[i][najwiekszy_dzielnik_indeks];
        }

        for(LL m=0;m<=j;m++){
            if(akt_dzielnik%dzielniki_k[m]==0 && dzielniki_k[najwiekszy_dzielnik_indeks]%dzielniki_k[m]!=0){
                
                LL nowy_dzielnik=dzielniki_k[m];
                for(LL i=n;i>=1;i--){
                    LL op_newton;
                    if(nowy_dzielnik>i){
                        op_newton=0;
                    }else{
                        op_newton=newton[i][nowy_dzielnik];
                    }

                    LL op_silnia;
                    if(nowy_dzielnik-1>=0){
                        op_silnia=silnia[nowy_dzielnik-1];
                    }else{
                        op_silnia=0;
                    }

                    LL op_dziel=1;
                    LL mnoznik=2;

                    for(LL indeks1=i-nowy_dzielnik;indeks1>=0;indeks1-=nowy_dzielnik){
                        dp[i][j]=(dp[i][j]+(((((dp[indeks1][j]*op_newton)%modulo)*op_silnia)%modulo)*potega(op_dziel,modulo-2))%modulo)%modulo;
                        
                        if(nowy_dzielnik>indeks1){
                            op_newton=(op_newton*0)%modulo;
                        }else{
                            op_newton=(op_newton*newton[indeks1][nowy_dzielnik])%modulo;
                        }

                        if(nowy_dzielnik-1<0){
                            op_silnia=(op_silnia*0)%modulo;
                        }else{
                            op_silnia=(op_silnia*silnia[nowy_dzielnik-1])%modulo;
                        }
                        op_dziel=(op_dziel*mnoznik)%modulo;
                        mnoznik++;
                    }
                }
            }
        }
    }

    for(int i=0;i<dzielniki_k.size();i++){
        for(int j=0;j<i;j++){
            if(dzielniki_k[i]%dzielniki_k[j]==0){
                dp[n][i]=(dp[n][i]-dp[n][j]+modulo)%modulo;
            }
        }
    }

    cout<<(dp[n][dzielniki_k.size()-1]*potega(silnia[n],modulo-2))%modulo;
    return 0;
}