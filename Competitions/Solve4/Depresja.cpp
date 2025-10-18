//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

vector<pair<long long int,long long int>> blokady;
vector<pair<long long int,long long int>> wejscie;
vector<long long int> nastepny;
vector<long long int> pozycja;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n;
    cin>>n;

    wejscie.resize(n+2);
    blokady.resize(n+2);
    nastepny.resize(1000009,0);
    pozycja.resize(1000009,1e9);

    wejscie[0]={0,0};
    wejscie[n+1]={0,n+1};

    for(int i=1;i<=n;i++){
        cin>>wejscie[i].first;
        wejscie[i].second=i;
    }

    priority_queue<pair<long long int,long long int>> kolejka;
    for(int i=0;i<=n+1;i++){
        while(!kolejka.empty() && kolejka.top().first>wejscie[i].first){
            blokady[kolejka.top().second].second=wejscie[i].second;
            kolejka.pop();
        }
        kolejka.push(wejscie[i]);
    }
    while(!kolejka.empty()){
        kolejka.pop();
    }
    for(int i=n+1;i>=0;i--){
        while(!kolejka.empty() && kolejka.top().first>wejscie[i].first){
            blokady[kolejka.top().second].first=wejscie[i].second;
            kolejka.pop();
        }
        kolejka.push(wejscie[i]);
    }
    while(!kolejka.empty()){
        kolejka.pop();
    }


    for(int i=n;i>=1;i--){
        nastepny[i]=pozycja[wejscie[i].first];
        pozycja[wejscie[i].first]=i;
    }
    long long int wynik=0;
    for(int i=1;i<=n;i++){
        wynik=wynik+wejscie[i].first*((i-blokady[i].first)*(min(blokady[i].second,nastepny[i])-i));
    }

    cout<<fixed<<setprecision(6)<<(long double)(wynik)/(long double)((n*(n+1))/2);
    return 0;
}