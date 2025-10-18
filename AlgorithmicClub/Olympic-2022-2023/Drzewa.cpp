//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graf;
vector<int> najlepsze;
vector<int> gdzie;
vector<char> znak;

bool porownaj(int a,int b,int punkt){
    while(gdzie[a]!=0 && gdzie[b]!=0 && znak[gdzie[a]]==znak[gdzie[b]]){
        a=gdzie[a];
        b=gdzie[b];
    }

    if(gdzie[a] && gdzie[b]){
        return znak[gdzie[a]]>znak[gdzie[b]];
    }
    if(!gdzie[a] && !gdzie[b]){
        return a<b;
    }

    return gdzie[a]!=0;
}

void dfs(int s,int p){
    if(graf[s].size()==0){
        najlepsze[s]=s;
        gdzie[s]=0;
        return;
    }

    int wynik=0;
    for(int v:graf[s]){
        if(v==p)continue;
        dfs(v,s);

        if(wynik==0){
            wynik=v;
            continue;
        }
        if(znak[wynik]<znak[v]){
            wynik=v;
        }
        if(znak[wynik]==znak[v]){
            if(!porownaj(wynik,v,s)){
                wynik=v;
            }
        } 
    }

    gdzie[s]=wynik;
    najlepsze[s]=najlepsze[wynik];
    

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    graf.resize(600000);    
    znak.resize(600000,0);
    gdzie.resize(600000,0);
    najlepsze.resize(600000,0);

    for(int i=2;i<=n;i++){
        int a;
        char b;
        cin>>a>>b;

        znak[i]=b;
        graf[a].push_back({i});
    }

    dfs(1,0);

    for(int i=1;i<=n;i++){
        if(najlepsze[i]==i){
            cout<<"0"<<'\n';
        }else{
            cout<<najlepsze[i]<<'\n';
        }
    }

    return 0;
}
 