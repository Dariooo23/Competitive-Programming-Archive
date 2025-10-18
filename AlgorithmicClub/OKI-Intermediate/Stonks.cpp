//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cout<<"AC";
    
    return 0;
}

//Karol Dziekan
/*#include <bits/stdc++.h>

using namespace std;

struct wierzcholek{
    long long int psoms,prefix,sufix,suma;
};

int M=(1<<15);
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

    long long int n,q,koszt;
    cin>>n>>q>>koszt;

    for(int i=1;i<=n;i++){
        long long int a;
        cin>>a;
        a-=koszt;
        update(1,1,M,i,a);
    }

    cout<<query(1,1,M,1,M).psoms<<" ";

    for(int i=1;i<=q;i++){
        long long int a,b;
        cin>>a>>b;
        b-=koszt;
        update(1,1,M,a,b);
       cout<<query(1,1,M,1,M).psoms<<" ";
    }
    return 0;
}*/