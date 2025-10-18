//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n,m,k,x;
struct kolejka_min{
    deque<pair<long long int,long long int>> kolejkamin;
    void push(long long int wartosc,long long int indeks){
        while (!kolejkamin.empty() && kolejkamin.back().first>=wartosc)
            kolejkamin.pop_back();
        kolejkamin.push_back({wartosc,indeks});
    }

    void pop(){
        kolejkamin.pop_front();
    }

    pair<long long int,long long int> get(){
        if(kolejkamin.size()==0)return {1e9,1e9};
        return kolejkamin.front();
    }

    int rozmiar(){
        return kolejkamin.size();
    }
};

vector<vector<long long int>> minima;
vector<vector<long long int>> plansza;
vector<vector<vector<long long int>>> dp;
vector<vector<kolejka_min>> kolejki;

void wzorcowka_wariacie(){
    plansza.resize(n+1,vector<long long int> (m+1));
    kolejki.resize(k+1,vector<kolejka_min>(m+1));
    dp.resize(k+1,vector<vector<long long int>> (n+1,vector<long long int>(m+1,1e9+9)));

    for(long long int i=1;i<=n;i++){
        for(long long int j=1;j<=m;j++){
            cin>>plansza[i][j];
        }
    }

    for(long long int i=1;i<=n;i++){
        for(long long int j=1;j<=m;j++){
            if(i==1 && j==1){
                dp[0][i][j]=plansza[i][j];
            }else{
                dp[0][i][j]=min(dp[0][i-1][j],dp[0][i][j-1])+plansza[i][j];
            }
        }
    }

    for(long long int l=1;l<=k;l++){
        minima.resize(n+1,vector<long long int> (m+1,1e9+9));

        for(int i=1;i<=min(x+1,n);i++){
            for(int j=1;j<=m;j++){
                kolejki[l][j].push(dp[l-1][i][j],i);
            }
        }
        for(int i=1;i<=n;i++){
            kolejka_min kolejka;
            for(int j=1;j<=m;j++){
                while(kolejki[l][j].rozmiar()!=0 && kolejki[l][j].get().second<i-x){
                    kolejki[l][j].pop();
                }
                kolejki[l][j].push(dp[l-1][min(n,i+x)][j],min(n,i+x));
            }
            for(int j=1;j<=min(x+1,m);j++){
                kolejka.push(kolejki[l][j].get().first,j);
            }
            for(int j=1;j<=m;j++){
                while(kolejka.rozmiar()!=0 && kolejka.get().second<j-x){
                    kolejka.pop();
                }
                kolejka.push(kolejki[l][min(m,j+x)].get().first,min(m,j+x));
                minima[i][j]=kolejka.get().first;
            }
        }
        
        for(long long int i=1;i<=n;i++){
            for(long long int j=1;j<=m;j++){
                if(i==1 && j==1){
                    dp[l][i][j]=plansza[i][j];
                }else{
                    dp[l][i][j]=min(dp[l][i-1][j],dp[l][i][j-1])+plansza[i][j];
                }
                dp[l][i][j]=min(dp[l][i][j],minima[i][j]+plansza[i][j]);
            }
        }
        minima.clear();
    }

    cout<<dp[k][n][m];
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>m>>k>>x;
    wzorcowka_wariacie();
    
    
    
    return 0;
}
