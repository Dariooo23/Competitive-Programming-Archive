
//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct wierzcholek{
    long long int psoms=0,prefix=0,sufix=0,suma=0;
};

long long int M=(1<<20);
vector<wierzcholek> tree(2*M);

wierzcholek polacz(wierzcholek punkt1,wierzcholek punkt2){
    wierzcholek punkt3;
    punkt3.psoms=max({punkt1.psoms,punkt2.psoms,punkt1.sufix+punkt2.prefix});
    punkt3.prefix=max({punkt1.prefix,punkt1.suma+punkt2.prefix});
    punkt3.sufix=max({punkt2.sufix,punkt2.suma+punkt1.sufix});
    punkt3.suma=punkt1.suma+punkt2.suma;

    return punkt3;
}

void update(int punkt,int poczatek,int koniec,int punkt2,long long int wartosc){
    if(poczatek==punkt2 && punkt2==koniec){
        tree[punkt].psoms=wartosc;
        tree[punkt].prefix=wartosc;
        tree[punkt].sufix=wartosc;
        tree[punkt].suma=wartosc;
        return;
    }

    int mid=(poczatek+koniec)/2;
    if(punkt2<=mid){
        update(punkt*2,poczatek,mid,punkt2,wartosc);
    }else{
        update(punkt*2+1,mid+1,koniec,punkt2,wartosc);
    }

    tree[punkt]=polacz(tree[punkt*2],tree[punkt*2+1]);
    return;
}
wierzcholek query(int punkt,int poczatek,int koniec,int lewo,int prawo){
    if(lewo<=poczatek && koniec<=prawo){
        return tree[punkt];
    }

    wierzcholek wynik1,wynik2;
    int mid=(poczatek+koniec)/2;
    if(lewo<=mid){
        wynik1=query(punkt*2,poczatek,mid,lewo,prawo);
    }
    if(prawo>mid){
        wynik2=query(punkt*2+1,mid+1,koniec,lewo,prawo);
    }

    return polacz(wynik1,wynik2);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,q;
    cin>>n;

    for(int i=1;i<=n;i++){
        long long int a;
        cin>>a;
        update(1,1,M,i,a);
    }

    cin>>q;
    for(int i=1;i<=q;i++){
        long long int a,b;
        char operacja;
        cin>>operacja;
        if(operacja=='Q'){
            cin>>a>>b;
            cout<<query(1,1,M,a,b).psoms<<endl;
        }else{
            cin>>a>>b;
            update(1,1,M,a,b);
        }
    }
    return 0;
}