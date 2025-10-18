//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<pair<long double,long double>> punkty;
vector<vector<long double>> pole;
vector<vector<vector<long double>>> dp;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,k;
    long double wynik=0;
    cin>>n>>k;

    pole.resize(n+1,vector<long double> (n+1,0));
    dp.resize(n+1,vector<vector<long double>> (n+1,vector<long double> (n+1,1e9)));

    for(int i=0;i<n;i++){
        long double x,y;
        cin>>x>>y;
        punkty.push_back({x,y});
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            pair<long double,long double> punkt1=punkty[i],punkt2=punkty[(i+j-1)%n],punkt3=punkty[(i+j)%n];  
            pole[i][(i+j)%n]=abs((punkt2.first-punkt1.first)*(punkt3.second-punkt1.second)-(punkt2.second-punkt1.second)*(punkt3.first-punkt1.first))/2+pole[i][(i+j-1)%n];
            dp[i][(i+j)%n][0]=pole[i][(i+j)%n];
        }
    }

    for(int ciecia=1;ciecia<=k;ciecia++){
        for(int pocz=0;pocz<=n;pocz++){
            for(int dl=0;dl<=n;dl++){
                for(int j=pocz;j<pocz+dl;j++){
                    dp[pocz][(pocz+dl)%n][ciecia]=min(dp[pocz][(pocz+dl)%n][ciecia],dp[pocz][j%n][ciecia-1]+pole[j%n][(pocz+dl)%n]);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        wynik=max(wynik,pole[i][(i+n-1)%n]-dp[(i+n-1)%n][i][k]);
    }

    cout<<fixed<<setprecision(1)<<wynik<<" ";
    return 0;
}
 