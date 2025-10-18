//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int
const int M=1<<23;

vector<long long int> tree(M*2);
vector<pair<long long int,long long int>> przedzialy;

long long int query(int pocz,int kon){
    pocz=pocz+M;
    kon=kon+M;

    long long int wynik=tree[pocz];
    if(pocz!=kon){
        wynik=(wynik|tree[kon]);
    }

    while(pocz/2!=kon/2){
        if(pocz%2==0){
            wynik=(wynik|tree[pocz+1]);
        }
        if(kon%2==1){
            wynik=(wynik|tree[kon-1]);
        }
        pocz=pocz/2;
        kon=kon/2;
    }
    return wynik;
}
void update(int x,long long int y){
    x=x+M;
    tree[x]=(tree[x]|y);

    while(x!=1){
        x=x/2;
        tree[x]=(tree[2*x]|tree[2*x+1]);
    }
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,m,alternatywa=0;
    cin>>n>>m;
    przedzialy.resize(m+1);

    for(int i=m+1;i<=2*m;i++){
        long long int a;
        cin>>a;
        long long int maska=a+((1<<n)-1-a)*(1<<n);
        alternatywa=(alternatywa|maska);

        update(i,maska);
        update(i-m,maska);
        update(i+m,maska);
    }

    //Gasienica w lewo;
    int poczatek=2*m-1,koniec=2*m-1;
    while(poczatek>=m){
        if(query(koniec,poczatek)==alternatywa){
            przedzialy[poczatek-m+1].first=poczatek-koniec+1;
            poczatek--;
        }else{
            koniec--;
        }
    }

    //Gasienica w prawo;
    poczatek=m+1;
    koniec=m+1;
    while(poczatek<=2*m){
        if(query(poczatek,koniec)==alternatywa){
            przedzialy[poczatek-m].second=koniec-poczatek+1;
            poczatek++;
        }else{
            koniec++;
        }
    }

    long long int wynik=0;
    for(int i=1;i<=m;i++){
        if(przedzialy[i].first+przedzialy[i].second<=m){
            wynik=wynik+(m-przedzialy[i].first-przedzialy[i].second+1);
        }
    }

    cout<<wynik/2;
    return 0;
}