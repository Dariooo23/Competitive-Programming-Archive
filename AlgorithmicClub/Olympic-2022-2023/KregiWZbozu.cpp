//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n;

struct okrag{
    long long int x,y,r;
};
struct granice{
    long long int x,indeks,jest;
};

set<pair<int,int>> pozycje;
set<pair<int,int>> policzone;

vector<okrag> okregi;
vector<granice> wejscie_seta;

bool czy_dotykaja(int a,int b){
    long long int dist1=(okregi[a].r+okregi[b].r)*(okregi[a].r+okregi[b].r);
    long long int dist2=(okregi[a].x-okregi[b].x)*(okregi[a].x-okregi[b].x)+(okregi[a].y-okregi[b].y)*(okregi[a].y-okregi[b].y);
    return dist1==dist2;
}

void dodaj(int okrag1){
    pozycje.insert({okregi[okrag1].y,okrag1});
    auto it=pozycje.find({okregi[okrag1].y,okrag1});

    int lewo=-1,prawo=-1;
    if(it!=pozycje.begin()){
        --it;
        lewo=it->second;
    }
    if(lewo!=-1){
        ++it;
    }
    it++;
    if(it!=pozycje.end()){
        prawo=it->second;
    }

    if(lewo!=-1 && czy_dotykaja(okrag1,lewo)){
        policzone.insert({min(okrag1,lewo),max(okrag1,lewo)});
    }
    if(prawo!=-1 && czy_dotykaja(okrag1,prawo)){
        policzone.insert({min(okrag1,prawo),max(okrag1,prawo)});
    }

    return;
}
void usun(int okrag1){
    auto it=pozycje.find({okregi[okrag1].y,okrag1});

    int lewo=-1,prawo=-1;
    if(it!=pozycje.begin()){
        --it;
        lewo=it->second;
    }
    if(lewo!=-1){
        ++it;
    }
    it++;
    if(it!=pozycje.end()){
        prawo=it->second;
    }

    if(lewo!=-1 && prawo!=-1 && czy_dotykaja(lewo,prawo)){
        policzone.insert({min(lewo,prawo),max(lewo,prawo)});
    }

    pozycje.erase({okregi[okrag1].y,okrag1});
    return;
}

void wrzuc_na_seta(){

    for(int i=0;i<wejscie_seta.size();i++){
        if(wejscie_seta[i].jest==1){
            dodaj(wejscie_seta[i].indeks);
        }else{
            usun(wejscie_seta[i].indeks);
        }
    }

    return;
}
void stworz_okregi(){
    for(int i=0;i<n;i++){
        wejscie_seta.push_back({okregi[i].x-okregi[i].r,i,1});   
        wejscie_seta.push_back({okregi[i].x+okregi[i].r,i,-1});    
    }

    return;
}

bool comp(const granice &a, const granice &b){
    if(a.x==b.x){
        return a.jest>b.jest;
    }else{
        return a.x<b.x;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n;
    for(int i=0;i<n;i++){
        int x,y,r;
        cin>>x>>y>>r;
        okregi.push_back({x,y,r});
    }

    stworz_okregi();
    sort(wejscie_seta.begin(),wejscie_seta.end(),comp);
    wrzuc_na_seta();

    cout<<policzone.size()<<endl;

    return 0;
}
 