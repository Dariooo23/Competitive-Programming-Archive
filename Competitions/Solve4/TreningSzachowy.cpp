//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

pair<int,vector<int>> suma_cyklu(int start,vector<int> usuniete,vector<vector<int>> graf){
    int licznik=0;
    queue<int> kolejka;

    usuniete[start]=1;
    kolejka.push(start);
    while(!kolejka.empty()){
        int punkt=kolejka.front();
        kolejka.pop();
        licznik++;

        for(int v:graf[punkt]){
            if(usuniete[v])continue;
            kolejka.push(v);
            usuniete[v]=1;
        }
    }
    return {licznik/2,usuniete};
}

int maksymalny_zbior_niezalezny(vector<vector<int>> graf, vector<int> usuniete, vector<int> stopnie){
    int punkt01=-1,punkt2=-1,punkt3=-1;
    for(int i=0;i<stopnie.size();i++){
        if(usuniete[i])continue;
        if(stopnie[i]==0 || stopnie[i]==1){
            punkt01=i;
        }
        if(stopnie[i]==2){
            punkt2=i;
        }
        if(stopnie[i]>=3){
            punkt3=i;
        }
    }

    if(punkt01!=-1){
        //Jezeli punkt ma stopien 0 lub 1 to zawsze mozemy go wziac i polepszyc wynik
        for(int v:graf[punkt01]){
            if(usuniete[v])continue;
            usuniete[v]=1;
            stopnie[v]--;

            for(int w:graf[v]){
                stopnie[w]--;
            }
        }

        usuniete[punkt01]=1; 
        return maksymalny_zbior_niezalezny(graf,usuniete,stopnie)+1;
    }
    if(punkt3!=-1){
        //Jezeli istnieja punkty ze stopniem 3 lub wiekszym to bierzemy je przed stopniami 2 aby miec pewnosc ze na koncu zostana same cykle
        //Opcja gdzie nie bierzemy danego punktu
        usuniete[punkt3]=1;
        for(int v:graf[punkt3]){
            stopnie[v]--;
        }
        int opcja1=maksymalny_zbior_niezalezny(graf,usuniete,stopnie);

        //Opcja gdzie bierzemy dany punkt i usuwamy jego wszystkich sasiadow
        for(int v:graf[punkt3]){
            if(usuniete[v])continue;
            usuniete[v]=1;
            stopnie[v]--;
            
            for(int w:graf[v]){
                stopnie[w]--;
            }
        }
        int opcja2=maksymalny_zbior_niezalezny(graf,usuniete,stopnie)+1;

        return max(opcja1,opcja2);
    }
    if(punkt2!=-1){
        //Jezeli jedyne punkty jakie pozostaly to te ze stopniem 2 to znaczy ze znajduja sie one na cyklach
        pair<int,vector<int>> wynik=suma_cyklu(punkt2,usuniete,graf);
        return wynik.first+maksymalny_zbior_niezalezny(graf,wynik.second,stopnie);
    }

    return 0;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<int> stopnie(n,0);
    vector<vector<int>> graf(n);
    vector<int> usuniete(n,0);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;

        a--;b--;
        stopnie[a]++;
        stopnie[b]++;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    cout<<maksymalny_zbior_niezalezny(graf,usuniete,stopnie);
    return 0;
}
