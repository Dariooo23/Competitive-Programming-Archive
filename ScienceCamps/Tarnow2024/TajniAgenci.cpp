//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

struct agent{
    int typ,nr,glebokosc;
};

bool cmp(const agent &a,const agent &b){
    if(a.glebokosc==b.glebokosc){
        return a.nr<b.nr;
    }else{
        return a.glebokosc<b.glebokosc;
    }
}

void wywala(int typ,int punkt, vector<agent> agenci1,vector<agent> agenci2,vector<agent> agenci3){
    /*cout<<typ<<" "<<punkt<<":"<<endl;
    cout<<"jedynki : ";
    for(int i=0;i<agenci1.size();i++){
        cout<<agenci1[i].nr<<" ";
    }cout<<endl;
    cout<<"dwojki : ";
    for(int i=0;i<agenci2.size();i++){
        cout<<agenci2[i].nr<<" ";
    }cout<<endl;
    cout<<"trojki : ";
    for(int i=0;i<agenci3.size();i++){
        cout<<agenci3[i].nr<<" ";
    }cout<<endl;
    cout<<endl;*/

    cout<<"NIE";

    exit(0);
}

vector<int> glebokosc;
vector<int> typ_agenta;
vector<vector<int>> graf;
vector<pair<int,int>> sparowania;

agent dfs(int s,int p,int glebokosc){
    vector<agent> agenci1;
    vector<agent> agenci2;
    vector<agent> agenci3;

    if(typ_agenta[s]==1)agenci1.push_back({1,s,glebokosc});
    if(typ_agenta[s]==2)agenci2.push_back({2,s,glebokosc});
    if(typ_agenta[s]==3)agenci3.push_back({3,s,glebokosc});

    for(const int &v:graf[s]){
        if(v==p)continue;
        agent agentp=dfs(v,s,glebokosc+1);
        if(agentp.typ==1)agenci1.push_back(agentp);
        if(agentp.typ==2)agenci2.push_back(agentp);
        if(agentp.typ==3)agenci3.push_back(agentp);
    }

    sort(agenci1.begin(),agenci1.end(),cmp);
    sort(agenci2.begin(),agenci2.end(),cmp);
    sort(agenci3.begin(),agenci3.end(),cmp);

    vector<agent> wynik;

    if(abs((LL)agenci2.size()-(LL)agenci3.size())>=2)wywala(3,s,agenci1,agenci2,agenci3);

    //Parowanie jedynek
    for(int i=0;i<agenci1.size();i++){
        if(i==agenci1.size()-1){
            if(wynik.size()!=0){
                wywala(1,s,agenci1,agenci2,agenci3);
            }
            wynik.push_back(agenci1[i]);
            continue;
        }

        if(agenci1[i].glebokosc==agenci1[i+1].glebokosc){
            sparowania.push_back({agenci1[i].nr,agenci1[i+1].nr});
            i++;
        }else{
            if(wynik.size()!=0){
                wywala(2,s,agenci1,agenci2,agenci3);
            }
            wynik.push_back(agenci1[i]);
        }
    }

    //Parowanie dwojek i trojek
    if(agenci2.size()==agenci3.size()){
        for(int i=0;i<agenci2.size();i++){
            if(agenci2[i].glebokosc>=agenci3[i].glebokosc){
                wywala(4,s,agenci1,agenci2,agenci3);
            }else{
                sparowania.push_back({agenci2[i].nr,agenci3[i].nr});
            }
        }
    }else{
        if(wynik.size()!=0){
            wywala(8,s,agenci1,agenci2,agenci3);
        }
    }

    if(agenci2.size()>agenci3.size()){
        int indeks1=agenci2.size()-1;
        int indeks2=agenci3.size()-1;
        while(indeks1>=0 && indeks2>=0){
            if(agenci2[indeks1].glebokosc<agenci3[indeks2].glebokosc){
                sparowania.push_back({agenci2[indeks1].nr,agenci3[indeks2].nr});
            }else{
                if(wynik.size()!=0){
                    wywala(5,s,agenci1,agenci2,agenci3);
                }
                wynik.push_back(agenci2[indeks1]);
                indeks2++;
            }
            indeks1--;
            indeks2--;
        }

        if(wynik.size()==0)wynik.push_back(agenci2[0]);
        //else wywala(10,s,agenci1,agenci2,agenci3);
    }

    
    if(agenci2.size()<agenci3.size()){
        int indeks1=0;
        int indeks2=0;
        while(indeks1<agenci2.size() && indeks2<agenci3.size()){
            if(agenci2[indeks1].glebokosc<agenci3[indeks2].glebokosc){
                sparowania.push_back({agenci2[indeks1].nr,agenci3[indeks2].nr});
            }else{
                if(wynik.size()!=0){
                    wywala(6,s,agenci1,agenci2,agenci3);
                }
                wynik.push_back(agenci3[indeks2]);
                indeks1--;
            }
            indeks1++;
            indeks2++;
        }
        if(wynik.size()==0)wynik.push_back(agenci3[agenci3.size()-1]);
        //else wywala(9,s,agenci1,agenci2,agenci3);
    }


    agenci1.clear();
    agenci2.clear();
    agenci3.clear();

    if(wynik.size()>1){
        wywala(7,s,agenci1,agenci2,agenci3);
    }else{
        if(wynik.size()==0){
            return {0,0,0};
        }else{
            return wynik[0];
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    graf.resize(n+1);
    glebokosc.resize(n+1);
    typ_agenta.resize(n+1);

    for(int i=2;i<=n;i++){
        cin>>typ_agenta[i];
    }

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    agent agent_zero=dfs(1,0,0);
    if(agent_zero.glebokosc!=0 || agent_zero.nr!=0 || agent_zero.typ!=0){
        cout<<"NIE";
        return 0;
    }else{
        cout<<"TAK"<<endl;
        for(int i=0;i<sparowania.size();i++){
            cout<<sparowania[i].first<<" "<<sparowania[i].second<<endl;
        }
    }
    return 0;
}