//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

vector<pair<LL,LL>> punkty;
map<pair<LL,pair<LL,LL>>,int> przekatne;

int main(){
    long long int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        long long int x,y;
        cin>>x>>y;
        punkty.push_back({x,y});
    }

    long long int wynik=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pair<LL,LL> punkt1=punkty[i],punkt2=punkty[j];
            LL dlugosc=(punkt1.first-punkt2.first)*(punkt1.first-punkt2.first)+(punkt1.second-punkt2.second)*(punkt1.second-punkt2.second);
            pair<LL,LL> srodek={punkt1.first+punkt2.first,punkt1.second+punkt2.second};

            if(przekatne.find({dlugosc,srodek})!=przekatne.end()){
                wynik+=przekatne[{dlugosc,srodek}];
            }
            przekatne[{dlugosc,srodek}]++;
        }
    }

    cout<<wynik;
    return 0;
}
 