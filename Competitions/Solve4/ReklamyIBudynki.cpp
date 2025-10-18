//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> blokady;
vector<pair<int,int>> budynki;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    blokady.resize(n+2);
    budynki.resize(n+2);

    budynki[0]={0,0};
    budynki[n+1]={0,n+1};

    for(int i=1;i<=n;i++){
        cin>>budynki[i].first;
        budynki[i].second=i;
    }

    priority_queue<pair<int,int>> kolejka;
    for(int i=0;i<=n+1;i++){
        while(!kolejka.empty() && kolejka.top().first>budynki[i].first){
            blokady[kolejka.top().second].second=budynki[i].second;
            kolejka.pop();
        }
        kolejka.push(budynki[i]);
    }
    while(!kolejka.empty()){
        kolejka.pop();
    }
    for(int i=n+1;i>=0;i--){
        while(!kolejka.empty() && kolejka.top().first>budynki[i].first){
            blokady[kolejka.top().second].first=budynki[i].second;
            kolejka.pop();
        }
        kolejka.push(budynki[i]);
    }
    while(!kolejka.empty()){
        kolejka.pop();
    }


    long long int wynik=0;
    for(int i=1;i<=n;i++){
        wynik=max(wynik,(long long int)budynki[i].first*(blokady[i].second-blokady[i].first-1));
    }

    cout<<wynik;
    return 0;
}