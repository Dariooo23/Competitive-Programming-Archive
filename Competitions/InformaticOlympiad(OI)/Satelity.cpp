//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

long long int podstawa1=2137;
long long int podstawa2=2069;
long long int modulo=1e9+696969;
long long int trojki1=0,trojki2=0,piatki1=0,piatki2=0;

vector<int> zastepcze;
vector<int> firma_jeden;
vector<int> firma_druga;
vector<vector<int>> graf;
vector<vector<char>> kody;
vector<vector<int>> komp_graf;
vector<vector<int>> zastepcze2;
map<pair<long long int,long long int>, vector<int>> kompresja;
map<pair<long long int,long long int>, vector<int>> kompresja2;

void przypadek_3(const int &n,const int &punkt, const vector<int> &polaczenia,int wersja){
    long long int dlugosc=kody[zastepcze2[punkt][0]].size()+2;
    kody[zastepcze2[punkt][0]].push_back('C');
    kody[zastepcze2[punkt][0]].push_back('C');

    kody[zastepcze2[punkt][1]].push_back('C');
    if(wersja==0)kody[zastepcze2[punkt][1]].push_back('A');
    if(wersja==1)kody[zastepcze2[punkt][1]].push_back('B');

    if(wersja==0)kody[zastepcze2[punkt][2]].push_back('A');
    if(wersja==1)kody[zastepcze2[punkt][2]].push_back('B');
    kody[zastepcze2[punkt][2]].push_back('C');

    for(int i=0;i<polaczenia.size();i++){
        if(polaczenia[i]==0)continue;
        for(int j=0;j<zastepcze2[i].size();j++){
            kody[zastepcze2[i][j]].push_back('C');
            kody[zastepcze2[i][j]].push_back('C');
        }
    }

    for(int i=1;i<=n;i++){
        while(kody[i].size()<dlugosc){
            kody[i].push_back('A');
        }
    }
    for(int i=n+1;i<=2*n;i++){
        while(kody[i].size()<dlugosc){
            kody[i].push_back('B');
        }
    }
    return;
}
void przypadek_5(const int &n,const int &punkt, const vector<int> &polaczenia,int wersja){
    long long int dlugosc=kody[zastepcze2[punkt][0]].size()+3;
    kody[zastepcze2[punkt][0]].push_back('C');
    kody[zastepcze2[punkt][0]].push_back('C');
    kody[zastepcze2[punkt][0]].push_back('C');

    if(wersja==0)kody[zastepcze2[punkt][1]].push_back('A');
    if(wersja==1)kody[zastepcze2[punkt][1]].push_back('B');
    kody[zastepcze2[punkt][1]].push_back('C');
    kody[zastepcze2[punkt][1]].push_back('C');

    kody[zastepcze2[punkt][2]].push_back('C');
    if(wersja==0)kody[zastepcze2[punkt][2]].push_back('A');
    if(wersja==1)kody[zastepcze2[punkt][2]].push_back('B');
    kody[zastepcze2[punkt][2]].push_back('C');

    if(wersja==0)kody[zastepcze2[punkt][3]].push_back('A');
    if(wersja==1)kody[zastepcze2[punkt][3]].push_back('B');
    if(wersja==0)kody[zastepcze2[punkt][3]].push_back('A');
    if(wersja==1)kody[zastepcze2[punkt][3]].push_back('B');
    kody[zastepcze2[punkt][3]].push_back('C');

    kody[zastepcze2[punkt][4]].push_back('C');
    kody[zastepcze2[punkt][4]].push_back('C');
    if(wersja==0)kody[zastepcze2[punkt][4]].push_back('A');
    if(wersja==1)kody[zastepcze2[punkt][4]].push_back('B');

    for(int i=0;i<polaczenia.size();i++){
        if(polaczenia[i]==0)continue;
        for(int j=0;j<zastepcze2[i].size();j++){
            kody[zastepcze2[i][j]].push_back('C');
            kody[zastepcze2[i][j]].push_back('C');
            kody[zastepcze2[i][j]].push_back('C');
        }
    }

    for(int i=1;i<=n;i++){
        while(kody[i].size()<dlugosc){
            kody[i].push_back('A');
        }
    }
    for(int i=n+1;i<=2*n;i++){
        while(kody[i].size()<dlugosc){
            kody[i].push_back('B');
        }
    }
    return;
}

void stworz_kod(const int &n,const int &punkt,const vector<int> &polaczenia){
    for(int i=1;i<=n;i++){
        kody[i].push_back('A');
    }
    for(int i=n+1;i<=2*n;i++){
        kody[i].push_back('B');
    }
    for(int i=0;i<zastepcze2[punkt].size();i++){
        kody[zastepcze2[punkt][i]][kody[zastepcze2[punkt][i]].size()-1]='C';
    }

    for(int i=0;i<polaczenia.size();i++){
        if(polaczenia[i]==0)continue;
        for(int j=0;j<zastepcze2[i].size();j++){
            kody[zastepcze2[i][j]][kody[zastepcze2[i][j]].size()-1]='C';
        }
    }
}
void stworz_kody(int n,const vector<int> &firma,bool wersja){
    for(int i=0;i<firma.size();i++){
        if(zastepcze2[firma[i]].size()==3 && trojki1==1 && trojki2==1){
            przypadek_3(n,firma[i],komp_graf[firma[i]],wersja);
            continue;
        }
        if(zastepcze2[firma[i]].size()==5 && piatki1==1 && piatki2==1){
            przypadek_5(n,firma[i],komp_graf[firma[i]],wersja);
            continue;
        }
        stworz_kod(n,firma[i],komp_graf[firma[i]]);
    }
}


long long int maks;
void roznicuj(int n,const vector<int> &indeksy,int poczatek,int koniec){
    maks=max(maks,(long long int)kody[indeksy[0]].size());
    if(poczatek==koniec)return;
    for(int i=poczatek;i<=(poczatek+koniec)/2;i++){
        if(indeksy[i-1]<=n){
            kody[indeksy[i-1]].push_back('A');
        }else{
            kody[indeksy[i-1]].push_back('B');
        }
    }
    for(int i=(poczatek+koniec)/2+1;i<=koniec;i++){
        kody[indeksy[i-1]].push_back('C');
    }

    roznicuj(n,indeksy,poczatek,(poczatek+koniec)/2);
    roznicuj(n,indeksy,(poczatek+koniec)/2+1,koniec);
    return;
}
void roznicowanie(int n,int poczatek,int koniec,char litera){
    kompresja2.clear();
    for(int i=poczatek;i<=koniec;i++){
        long long int hash1=0,hash2=0;
        for(int j=0;j<kody[i].size();j++){
            hash1=((hash1*podstawa1)%modulo)+(kody[i][j]-'A'+1)%modulo;
            hash2=((hash2*podstawa2)%modulo)+(kody[i][j]-'A'+1)%modulo;
        }
        kompresja2[{hash1,hash2}].push_back(i);
    }

    maks=0;
    for(auto it=kompresja2.begin();it!=kompresja2.end();++it){
        roznicuj(n,it->second,1,it->second.size());
    }

    for(int i=poczatek;i<=koniec;i++){
        while(kody[i].size()<maks){
            kody[i].push_back(litera);
        }
    }
}


void czy_klika(int n){
    bool flaga1=0,flaga2=0;
    for(int i=0;i<kody[1].size();i++){
        long long int licznik1=0,licznik2=0;
        for(int j=1;j<=n;j++){
            if(kody[j][i]=='A'){
                licznik1++;
            }
            if(kody[j][i]=='C'){
                licznik2++;
            }
        }
        if(licznik1==n || licznik2==n){
            flaga1=1;
        }
    }
    for(int i=0;i<kody[1].size();i++){
        long long int licznik1=0,licznik2=0;
        for(int j=n+1;j<=2*n;j++){
            if(kody[j][i]=='B'){
                licznik1++;
            }
            if(kody[j][i]=='C'){
                licznik2++;
            }
        }
        if(licznik1==n || licznik2==n){
            flaga2=1;
        }
    }

    if(flaga1==0 || flaga2==0){
        for(int i=1;i<=n;i++){
            kody[i].push_back('A');
        }
        for(int i=n+1;i<=2*n;i++){
            kody[i].push_back('B');
        }
    }
    return;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,p,m;
    cin>>n>>p>>m;

    kody.resize(n*2+1);
    graf.resize(n*2+1);
    zastepcze.resize(2*n+1);
    zastepcze2.resize(2*n+1);
    komp_graf.resize(2*n+1,vector<int> (2*n+1));

    for(int i=0;i<p;i++){
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }


    for(int i=1;i<=n*2;i++){
        long long int hash1=0,hash2=0;
        if(graf[i].size()==0)continue;
        sort(graf[i].begin(),graf[i].end());
        for(int j=0;j<graf[i].size();j++){
            hash1=(((hash1*podstawa1)%modulo)+graf[i][j])%modulo;
            hash2=(((hash2*podstawa2)%modulo)+graf[i][j])%modulo;
        }
        kompresja[{hash1,hash2}].push_back(i);
    }

    long long int licznik=1;
    for(auto it=kompresja.begin();it!=kompresja.end();++it){
        for(int i=0;i<it->second.size();i++){
            zastepcze[it->second[i]]=licznik;
            zastepcze2[licznik].push_back(it->second[i]);
        }
        if(it->second[0]<=n){
            if(it->second.size()==3){
                trojki1++;
            }
            if(it->second.size()==5){
                piatki1++;
            }
            firma_jeden.push_back(licznik);
        }else{
            if(it->second.size()==3){
                trojki2++;
            }
            if(it->second.size()==5){
                piatki2++;
            }
            firma_druga.push_back(licznik);
        }
        licznik++;
    }

    for(int i=1;i<=2*n;i++){
        for(int j=0;j<graf[i].size();j++){
            komp_graf[zastepcze[i]][zastepcze[graf[i][j]]]=1;
            komp_graf[zastepcze[graf[i][j]]][zastepcze[i]]=1;
        }
    }

    if(firma_jeden.size()<=firma_druga.size())stworz_kody(n,firma_jeden,0);
    else stworz_kody(n,firma_druga,1);

    roznicowanie(n,1,n,'A');
    for(int i=n+1;i<=2*n;i++){
        while(kody[i].size()<maks){
            kody[i].push_back('B');
        }
    }
    roznicowanie(n,n+1,2*n,'B');
    for(int i=1;i<=n;i++){
        while(kody[i].size()<maks){
            kody[i].push_back('A');
        }
    }

    if(kody[1].size()!=m)czy_klika(n);

    cout<<kody[1].size()<<endl;
    for(int i=1;i<=2*n;i++){
        for(int j=0;j<kody[i].size();j++){
            cout<<kody[i][j];
        }cout<<endl;
    }
    return 0;
}