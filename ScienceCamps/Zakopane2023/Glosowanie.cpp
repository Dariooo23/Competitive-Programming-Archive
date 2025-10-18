//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> tab;
vector<int> wynik;
vector<int> dzielnik;

class Cmp
{
    public:
    bool operator()(pair<long double,int> a, pair<long double,int> b){
        if(a.first==b.first){
            return a.second>b.second;
        }else{
            return a.first<b.first;
        }
    }
};

priority_queue<pair<long double,int>,vector<pair<long double,int>>,Cmp> kolejka;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,m;
    cin>>n>>m;

    tab.resize(n+1);
    wynik.resize(n+1);
    dzielnik.resize(n+1,1);

    for(int i=1;i<=n;i++){
        cin>>tab[i];
        kolejka.push({(long double)tab[i],i});
    }

    for(int i=1;i<=m;i++){
        pair<long double,int> liczba=kolejka.top();
        kolejka.pop();

        wynik[liczba.second]++;
        dzielnik[liczba.second]++;
        kolejka.push({(long double)((long double)tab[liczba.second]/(long double)dzielnik[liczba.second]),liczba.second});
    }

    for(int i=1;i<=n;i++){
        cout<<wynik[i]<<" ";
    }




    return 0;
}