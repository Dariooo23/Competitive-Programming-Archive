//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n,m;
//DRZEWO DWOJKOWE
const long long int M=1<<20;
vector<long long int> tree2(M*2+1,-1e9);
vector<long long int> lazy2(M*2+1,0);
vector<long long int> indeks2(M*2+1,0);
void dodaj2(int punkt,long long int ile){
    lazy2[punkt]=lazy2[punkt]+ile;
    if(tree2[punkt]==-1e9){
        tree2[punkt]=ile;
    }else{
        tree2[punkt]=tree2[punkt]+ile;
    }
}
void przekaz2(int punkt,int ilosc){
    dodaj2(2*punkt,lazy2[punkt]);
    dodaj2(2*punkt+1,lazy2[punkt]);
    lazy2[punkt]=0;
}
void update2(int gdzie,int pocz,int kon,int x,int y,long long int ile){
    if(x<=pocz && y>=kon){
        dodaj2(gdzie,ile);
        return;
    }

    przekaz2(gdzie,kon-pocz+1);
    int mid=(pocz+kon)/2;
    if(x<=mid){
        update2(2*gdzie,pocz,mid,x,y,ile);
    }
    if(y>mid){
        update2(2*gdzie+1,mid+1,kon,x,y,ile);
    }

    tree2[gdzie]=max(tree2[2*gdzie],tree2[2*gdzie+1]);
    if(tree2[2*gdzie]>tree2[2*gdzie+1]){
        indeks2[gdzie]=indeks2[2*gdzie];
    }else{
        indeks2[gdzie]=indeks2[2*gdzie+1];
    }
    return;
}
pair<int,int> query2(int gdzie, int pocz, int kon, int x,int y){
   if(x<=pocz && y>=kon){
       return {tree2[gdzie],indeks2[gdzie]};
   }
   przekaz2(gdzie,kon-pocz+1);
   long long int mid=(pocz+kon)/2;
   pair<int,int> wynik1={-1e9,0},wynik2={-1e9,0};
   if(x<=mid){
    wynik1=query2(2*gdzie,pocz,mid,x,y);
   }
   if(y>mid){
    wynik2=query2(2*gdzie+1,mid+1,kon,x,y);
   }

   tree2[gdzie]=max(tree2[2*gdzie],tree2[2*gdzie+1]);
   if(tree2[2*gdzie]>tree2[2*gdzie+1]){
        indeks2[gdzie]=indeks2[2*gdzie];
    }else{
        indeks2[gdzie]=indeks2[2*gdzie+1];
    }


    if(wynik1.first>wynik2.first){
        return wynik1;
    }else{
        return wynik2;
    }
}
void stworz_drzewo2(int punkt,int poczatek,int koniec){
    if(poczatek==koniec){
        indeks2[punkt]=punkt-M+1;
        return;
    }
    int srodek=(poczatek+koniec)/2;
    stworz_drzewo2(punkt*2,poczatek,srodek);
    stworz_drzewo2(punkt*2+1,srodek+1,koniec);
    if(tree2[punkt*2]>tree2[punkt*2+1]){
        indeks2[punkt]=indeks2[punkt*2];
    }else{
        indeks2[punkt]=indeks2[punkt*2+1];
    }
    return;
}

//DRZEWO TROJKOWE

vector<long long int> tree3(M*2+1,-1e9);
vector<long long int> lazy3(M*2+1,0);
vector<long long int> indeks3(M*2+1,0);
void dodaj3(int punkt,long long int ile){
    lazy3[punkt]=lazy3[punkt]+ile;
    if(tree3[punkt]==-1e9){
        tree3[punkt]=ile;
    }else{
        tree3[punkt]=tree3[punkt]+ile;
    }
}
void przekaz3(int punkt,int ilosc){
    dodaj3(2*punkt,lazy3[punkt]);
    dodaj3(2*punkt+1,lazy3[punkt]);
    lazy3[punkt]=0;
}
void update3(int gdzie,int pocz,int kon,int x,int y,long long int ile){
    if(x<=pocz && y>=kon){
        dodaj3(gdzie,ile);
        return;
    }

    przekaz3(gdzie,kon-pocz+1);
    int mid=(pocz+kon)/2;
    if(x<=mid){
        update3(2*gdzie,pocz,mid,x,y,ile);
    }
    if(y>mid){
        update3(2*gdzie+1,mid+1,kon,x,y,ile);
    }

    tree3[gdzie]=max(tree3[2*gdzie],tree3[2*gdzie+1]);
    if(tree3[2*gdzie]>tree3[2*gdzie+1]){
        indeks3[gdzie]=indeks3[2*gdzie];
    }else{
        indeks3[gdzie]=indeks3[2*gdzie+1];
    }
    return;
}
pair<int,int> query3(int gdzie, int pocz, int kon, int x,int y){
   if(x<=pocz && y>=kon){
       return {tree3[gdzie],indeks3[gdzie]};
   }
   przekaz3(gdzie,kon-pocz+1);
   long long int mid=(pocz+kon)/2;
   pair<int,int> wynik1={-1e9,0},wynik2={-1e9,0};
   if(x<=mid){
    wynik1=query3(2*gdzie,pocz,mid,x,y);
   }
   if(y>mid){
    wynik2=query3(2*gdzie+1,mid+1,kon,x,y);
   }

   tree3[gdzie]=max(tree3[2*gdzie],tree3[2*gdzie+1]);
   if(tree3[2*gdzie]>tree3[2*gdzie+1]){
        indeks3[gdzie]=indeks3[2*gdzie];
    }else{
        indeks3[gdzie]=indeks3[2*gdzie+1];
    }
    if(wynik1.first>wynik2.first){
        return wynik1;
    }else{
        return wynik2;
    }
}
void stworz_drzewo3(int punkt,int poczatek,int koniec){
    if(poczatek==koniec){
        if(punkt-M+1>n)return;
        indeks3[punkt]=punkt-M+1;
        return;
    }
    int srodek=(poczatek+koniec)/2;
    stworz_drzewo3(punkt*2,poczatek,srodek);
    stworz_drzewo3(punkt*2+1,srodek+1,koniec);
    indeks3[punkt]=max(indeks3[punkt*2],indeks3[punkt*2+1]);
    if(tree3[punkt*2]>tree3[punkt*2+1]){
        indeks3[punkt]=indeks3[punkt*2];
    }else{
        indeks3[punkt]=indeks3[punkt*2+1];
    }
    return;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin>>n>>m;

    vector<int> godziny(n+1);

    for(int i=1;i<=n;i++){
        cin>>godziny[i];
    }
    for(int i=1;i<n;i++){
        update2(1,1,M,i,i,godziny[i]+godziny[i+1]);
    }
    for(int i=1;i<n-1;i++){
        update3(1,1,M,i,i,godziny[i]+godziny[i+1]+godziny[i+2]);
    }
    stworz_drzewo2(1,1,M);
    stworz_drzewo3(1,1,M);

    for(int i=1;i<=m;i++){
        int a;
        cin>>a;
        if(a==1){
            int b,c,d;
            cin>>b>>c>>d;
            if(b==c){
                update2(1,1,M,max(1,b-1),c,d);
                update3(1,1,M,max(1,b-2),c,d);
            }
            if(b+1==c){
                update2(1,1,M,max(1,b-1),c,d);
                update2(1,1,M,b,max(1,c-1),d);

                update3(1,1,M,max(1,b-2),c,d);
                update3(1,1,M,max(1,b-1),max(1,c-1),d);
            }
            if(c>b+1){
                update2(1,1,M,max(1,b-1),c,d);
                update2(1,1,M,b,max(1,c-1),d);

                update3(1,1,M,max(1,b-2),c,d);
                update3(1,1,M,max(1,b-1),max(1,c-1),d);
                update3(1,1,M,b,max(1,c-2),d);
            }
        }else{
            int b,c;
            cin>>b>>c;
            if(c-b==1){
                pair<int,int> wynik=query2(1,1,M,b,c-1);
                cout<<wynik.second<<" "<<wynik.second+1<<endl;
            }else{
                pair<int,int> wynik1=query2(1,1,M,b,c-1);
                pair<int,int> wynik2=query3(1,1,M,b,c-2);
                wynik1.first=wynik1.first*3;
                wynik2.first=wynik2.first*2;
                if(wynik1.first>wynik2.first){
                    cout<<wynik1.second<<" "<<wynik1.second+1<<endl;
                }else{
                    cout<<wynik2.second<<" "<<wynik2.second+2<<endl;
                }
            }
        }
    }

    return 0;
}