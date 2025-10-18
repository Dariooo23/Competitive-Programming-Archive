//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> plansza;
vector<int> kolumny;
vector<int> wiersze;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    plansza.resize(n+1,vector<bool> (n+1));
    kolumny.resize(n+1,0);
    wiersze.resize(n+1,0);

    for(int i=1;i<=k;i++)
    {
        int a,b;
        cin>>a>>b;
        plansza[a][b]=1;
        if(plansza[a][b])
        {
                kolumny[b]++;
                wiersze[a]++;
        }
    }

    int wynik=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!plansza[i][j])
            {
                wynik=max(wynik,wiersze[i]+kolumny[j]);
            }
        }
    }
    cout<<wynik;
    
    return 0;
}
 