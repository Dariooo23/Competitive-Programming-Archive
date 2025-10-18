//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int,int>,int>> przekatne;
stack<pair<int,int>> stos;

bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.first.first==b.first.first){
        return a.first.second>b.first.second;
    }else{
        return a.first.first<b.first.first;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,m;
    cin>>n>>m;

    //Wczytujesz przekatne {{poczatek,koniec},numer}
    for(int i=0;i<min(n,m);i++){
        int a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        przekatne.push_back({{a,b},i+1});
    }

    //Sortujesz najpierw po poczatkach rosnaca i koncach malejaco
    sort(przekatne.begin(),przekatne.end(),cmp);

    //Wrzucasz pierwsza przekatna na stos
    stos.push({przekatne[0].first.second,przekatne[0].second});

    //Idziesz po pozostalych przekatnych
    for(int i=1;i<min(n,m);i++){
        //Jezeli aktualnie rozpatrywana przekatna z tablicy "przekatne" ma koniec wiekszy niz koniec gory stosu to je usuwamy
        while(!stos.empty() && stos.top().first<=przekatne[i].first.first){
            stos.pop();
        }

        //Jezeli stos nie jest pusty i koniec na jego gorze jest mniejszy niz koniec aktualnie rozpatrywanej
        //Krawedzi to oznacza to ze sie one przecinaja, odczytujemy numery tych przekatnych i wypisujemy
        if(!stos.empty()){
            if(stos.top().first<przekatne[i].first.second){
                cout<<"TAK"<<endl;
                cout<<stos.top().second<<" "<<przekatne[i].second;
                return 0;
            }
        }
        stos.push({przekatne[i].first.second,przekatne[i].second});
    }

    //W przeciwnym wypadku nie znalezlismy zadnych krawedzi ktore sie przecinaja
    cout<<"NIE";
    return 0;
}