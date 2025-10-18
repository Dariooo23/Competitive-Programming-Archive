//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> visited;
vector<int> wejscie;
vector<int> zliczanie;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    visited.resize(n+1);
    wejscie.resize(n+1);
    zliczanie.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>wejscie[i];
        zliczanie[wejscie[i]]++;
        if(zliczanie[wejscie[i]]>1){
            cout<<"NIE";
            return 0;
        }
    }

    int wynik=0;
    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        int osoba=wejscie[i];
        visited[i]=1;
        wynik++;
        while(osoba!=i){
            visited[osoba]=1;
            osoba=wejscie[osoba];
        }
    }
    
    cout<<wynik;
    return 0;
}