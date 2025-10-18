//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct zawodnik{
    int x,y,z;
};

long long int porownaj(zawodnik &zawodnik1,zawodnik &zawodnik2,zawodnik &zawodnik3){
    int x=max(zawodnik1.x,max(zawodnik2.x,zawodnik3.x));
    int y=max(zawodnik1.y,max(zawodnik2.y,zawodnik3.y));
    int z=max(zawodnik1.z,max(zawodnik2.z,zawodnik3.z));

    int nr1=0,nr2=0,nr3=0;
    if(zawodnik1.x==x){
        if(nr1==0){
            nr1=1;
        }else{
            return -1;
        }
    }
    if(zawodnik2.x==x){
        if(nr1==0){
            nr1=2;
        }else{
            return -1;
        }
    }
    if(zawodnik3.x==x){
        if(nr1==0){
            nr1=3;
        }else{
            return -1;
        }
    }


    if(zawodnik1.y==y){
        if(nr2==0){
            nr2=1;
        }else{
            return -1;
        }
    }
    if(zawodnik2.y==y){
        if(nr2==0){
            nr2=2;
        }else{
            return -1;
        }
    }
    if(zawodnik3.y==y){
        if(nr2==0){
            nr2=3;
        }else{
            return -1;
        }
    }


    if(zawodnik1.z==z){
        if(nr3==0){
            nr3=1;
        }else{
            return -1;
        }
    }
    if(zawodnik2.z==z){
        if(nr3==0){
            nr3=2;
        }else{
            return -1;
        }
    }
    if(zawodnik3.z==z){
        if(nr3==0){
            nr3=3;
        }else{
            return -1;
        }
    }

    if(nr1!=nr2 && nr2!=nr3 && nr3!=nr1){
        long long int suma=0;
        if(nr1==1){
            suma=suma+zawodnik1.x;
        }
        if(nr1==2){
            suma=suma+zawodnik2.x;
        }
        if(nr1==3){
            suma=suma+zawodnik3.x;
        }


        if(nr2==1){
            suma=suma+zawodnik1.y;
        }
        if(nr2==2){
            suma=suma+zawodnik2.y;
        }
        if(nr2==3){
            suma=suma+zawodnik3.y;
        }


        if(nr3==1){
            suma=suma+zawodnik1.z;
        }
        if(nr3==2){
            suma=suma+zawodnik2.z;
        }
        if(nr3==3){
            suma=suma+zawodnik3.z;
        }

        return suma;
    }else{
        return -1;
    }
}
void brut(int n){
    set<pair<int,pair<int,int>>> zawodnicy_set;
    vector<zawodnik> zawodnicy_tablica;

    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        zawodnicy_set.insert({x,{y,z}});
    }
    for(auto it=zawodnicy_set.begin();it!=zawodnicy_set.end();++it){
        zawodnik zawodnik1;
        zawodnik1.x=it->first;
        zawodnik1.y=it->second.first;
        zawodnik1.z=it->second.second;
        
        zawodnicy_tablica.push_back(zawodnik1);
    }
    long long int wynik=-1;
    for(int i=0;i<zawodnicy_tablica.size();i++){
        for(int j=i+1;j<zawodnicy_tablica.size();j++){
            for(int k=j+1;k<zawodnicy_tablica.size();k++){
                zawodnik 
                zawodnik1=zawodnicy_tablica[i],
                zawodnik2=zawodnicy_tablica[j],
                zawodnik3=zawodnicy_tablica[k];

                wynik=max(wynik,porownaj(zawodnik1,zawodnik2,zawodnik3));
            }
        }
    }

    cout<<wynik;
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;
    
    brut(n);
    
    return 0;
}
 