//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const long long int modulo=1e9+7;
vector<int> miejsca;
vector<bool> zajete;
vector<vector<int>> graf;
vector<vector<int>> opcje;
vector<pair<int,int>> komentatorzy;

void dfs(int s){
    zajete[s]=1;

    for(int v:graf[s]){
        if(zajete[v])continue;
        dfs(v);
    }

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,znane=0;
    cin>>n;

    graf.resize(n+1);
    opcje.resize(n+1);
    zajete.resize(n+1);
    miejsca.resize(n+1);
    komentatorzy.resize(n+1);

    queue<int> kolejka;
    
    for(int i=1;i<=n;i++){
        char znak;
        int pozycja1,pozycja2;
        cin>>znak;

        if(znak=='T'){
            cin>>pozycja1;
            znane++;

            if(!zajete[pozycja1]){
                zajete[pozycja1]=1;
                miejsca[i]=pozycja1;
                kolejka.push(pozycja1);
            }
        }else{
            cin>>pozycja1>>pozycja2;
            graf[pozycja1].push_back(pozycja2);
            graf[pozycja2].push_back(pozycja1);
            komentatorzy[i]={pozycja1,pozycja2};
            opcje[pozycja1].push_back(i);
            opcje[pozycja2].push_back(i);
        }
    }

    while(!kolejka.empty()){
        int miejsce=kolejka.front();
        kolejka.pop();

        for(const int v:opcje[miejsce]){
            if(miejsca[v])continue;
            if(komentatorzy[v].first!=miejsce){
                if(!zajete[komentatorzy[v].first]){
                    znane++;
                    zajete[komentatorzy[v].first]=1;
                    miejsca[v]=komentatorzy[v].first;
                    kolejka.push(komentatorzy[v].first);
                }
            }
            if(komentatorzy[v].second!=miejsce){
                if(!zajete[komentatorzy[v].second]){
                    znane++;
                    zajete[komentatorzy[v].second]=1;
                    miejsca[v]=komentatorzy[v].second;
                    kolejka.push(komentatorzy[v].second);
                }
            }
        }
    }

    if(znane==n){
        cout<<"TAK"<<endl;
        for(int i=1;i<=n;i++)cout<<miejsca[i]<<endl;  
    }else{
        cout<<"NIE"<<endl;
        long long int spojne=0;

        for(int i=1;i<=n;i++){
            if(zajete[i])continue;
            if(graf[i].size()){
                spojne++;
                dfs(i);
            }else{
                cout<<"0";
                exit(0);
            }
        }

        long long int wynik=1;
        while(spojne--){
            wynik=(wynik*2)%modulo;
        }

        cout<<wynik;
    }


    return 0;
}
 