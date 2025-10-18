//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct kolejka{
    deque<pair<int,int>> queue;

    void push(int a,int dlugosc){
        while (!queue.empty() && queue.back().first >= dlugosc)
        queue.pop_back();
        queue.push_back(make_pair(dlugosc, a));
    }
    void pop(){
        queue.pop_front();
    }


    int indeks(){
        return queue.front().second;
    }
    int minimum(){
        if(!queue.empty()){
            return queue.front().first;
        }else{
            return 1e9;
        } 
    }
    int empty(){
        return queue.empty();
    }
};

vector<int> czas;
vector<vector<int>> dp;
vector<vector<int>> indeksy;

vector<kolejka> kolejkamin1;
vector<kolejka> kolejkamin2;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    czas.resize(n+10,0);
    kolejkamin1.resize(n+10);
    kolejkamin2.resize(n+10);
    dp.resize(n+10,vector<int> (n+10,0));
    indeksy.resize(n+10,vector<int> (n+10,0));

    for(int i=1;i<=n;i++){
        cin>>czas[i];
    }

    for(int dlugosc=0;dlugosc<=n-1;dlugosc++){
        for(int poczatek=1;poczatek<=n-dlugosc;poczatek++){
            int koniec=poczatek+dlugosc;
            
            for(int indeks=indeksy[poczatek][koniec-1];indeks<=indeksy[poczatek+1][koniec];indeks++){
                if(dp[poczatek][indeks-1]<=dp[indeks+1][koniec]){
                    indeksy[poczatek][koniec]=indeks;
                }
            }

            kolejkamin1[poczatek].push(koniec,czas[koniec]+dp[poczatek][koniec-1]);
            while(!kolejkamin1[poczatek].empty() && kolejkamin1[poczatek].indeks()<=indeksy[poczatek][koniec]){
                kolejkamin1[poczatek].pop();
            }

            kolejkamin2[koniec].push(poczatek,czas[poczatek]+dp[poczatek+1][koniec]);
            while(!kolejkamin2[koniec].empty() && kolejkamin2[koniec].indeks()>indeksy[poczatek][koniec]){
                kolejkamin2[koniec].pop();
            }

            if(!kolejkamin1[poczatek].empty()&& indeksy[poczatek][koniec]==0){
                indeksy[poczatek][koniec]=kolejkamin1[poczatek].indeks();
            }
            dp[poczatek][koniec]=min(kolejkamin1[poczatek].minimum(),kolejkamin2[koniec].minimum());
        }
    }

    cout<<dp[1][n];

    return 0;
}
 