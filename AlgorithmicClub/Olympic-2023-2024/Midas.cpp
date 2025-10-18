//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

vector<pair<int,int>> graf;
vector<int> kolejnosc;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;
    graf.resize(n+1);
    kolejnosc.resize(n+1);

    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        graf[i]={a,b};
    }

    deque<pair<int,int>> kolejka;

    int punkt=1;
    int licznik=1;
    kolejnosc[punkt]=licznik;
    if(graf[punkt].second!=0){
        kolejka.push_back({graf[punkt].second,licznik+1});
        kolejnosc[graf[punkt].second]=licznik+1;
    }

    while(graf[punkt].first!=0){
        punkt=graf[punkt].first;
        kolejnosc[punkt]=licznik;

        if(graf[punkt].second!=0){
            kolejka.push_back({graf[punkt].second,licznik+1});
            kolejnosc[graf[punkt].second]=licznik+1;
        }
    }

    while(!kolejka.empty()){
        deque<pair<int,int>> kolejka2;

        licznik=licznik+2;
        while(!kolejka.empty()){
            pair<int,int> punkt=kolejka.front();
            kolejka.pop_front();
            if(graf[punkt.first].first!=0){
                kolejnosc[graf[punkt.first].first]=licznik;
                kolejka2.push_front({graf[punkt.first].first,licznik});
            }
            if(graf[punkt.first].second!=0){
                kolejnosc[graf[punkt.first].second]=licznik+1;
                kolejka2.push_back({graf[punkt.first].second,licznik+1});
            }
            if(!kolejka.empty() && kolejka.front().second!=punkt.second){
                break;
            }
        }

        while(!kolejka2.empty()){
            kolejka.push_back(kolejka2.front());
            kolejka2.pop_front();
        }
    }

    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        if(kolejnosc[a]>=kolejnosc[b]){
            cout<<"TAK"<<endl;
        }else{
            cout<<"NIE"<<endl;
        }
    }
    return 0;
}