//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> topsort;
vector<int> wartosci;
vector<bool> visited;
vector<int> visited2;
vector<vector<int>> graf;
vector<vector<int>> grafT;

void dfs1(int v){
    visited[v]=1;

    for(int u : graf[v]){
        if(visited[u])continue;
        dfs1(u);
    }

    topsort.push_back(v);
    return;
}

void dfs2(int v, int numer_skladowej){
    visited2[v]=numer_skladowej;

    for(int u : grafT[v]){
        if(visited2[u]!=0)continue;
        dfs2(u, numer_skladowej);
    }

    return;
}

bool rozwiaz_2SAT(){
    //Ustawiamy rozmiary tablic na dwukrotnosc ilosci punktow
    //Poniewaz dla kazdego punktu potrzebujemy jeszcze jego negacji
    //Jedynie tablica wartosci ma normalny rozmiar poniewaz przetrzymuje wyniki dla naszych argumentow poczatkowych
    topsort.clear();
    wartosci.resize(n+1,0);
    visited.resize((n+1)*2,0);
    visited2.resize((n+1)*2,0);

    //Tworzymy sortowanie topologiczne
    for(int i=0;i<(n+1)*2;i++){
        if(visited[i])continue;
        dfs1(i);
    }

    //Idac od tylu w sortowaniu topologicznym oznaczamy w jakich silnie spojnych skladowych znajduja sie dane punkty
    int numer_skladowej=1;
    for(int i=topsort.size()-1;i>=0;i--){
        if(visited2[topsort[i]])continue;
        dfs2(topsort[i],numer_skladowej);
        numer_skladowej++;
    }

    for(int i=0;i<(n+1)*2;i=i+2){
        //Jezeli ten warunek jest spelniony oznacza to ze argument a i ~a sa w jednej silnie spojnie skladowej
        //Przez co cale wyrazenie nie moze byc spelnione
        if(visited2[i]==visited2[i+1])return false;

        //Przypisujemy odpowiednie wartosci kolejnym argumentom aby spelnic wyrazenie
        //Przeskakujemy indeksy o 2 poniewaz indeksy nieparzyste to negacje naszych argumentow
        if(visited2[i]<visited2[i+1]){
            wartosci[i/2]=0;
        }else{
            wartosci[i/2]=1;
        }
    }


    return true;
}

void dodaj_krawedz(int zmienna1, bool wartosc1,int zmienna2, bool wartosc2){
    //Jezeli mamy warunek (a lub b) to odpowiednikiem jego w grafie bedzie ((~a -> b) i (~b -> a)),
    //Jezeli mamy warunek (~a lub b) to odpowiednikiem jego w grafie bedzie ((a -> b) i (~b -> ~a)), itp.

    //Zmienne to argumenty a i b, natomiast wartosci informuja nas czy w rownaniu wystepuja zanegowane czy tez nie, np.
    //Dla wartosc1=0 i wartosc2=1 mamy wyrazenie (a lub ~b), dla wartosc1=1 i wartosc2=1 mamy (~a lub ~b), itp.

    //Poczatkowo wszystkie argumenty zamieniamy na liczby parzyste i w zaleznosci czy maja byc zanegowane na poczatku na liczby nieparzyste,
    //Linijki zmienna1=2*zmienna1^wartosc1 i zmienna2=2*zmienna2^wartosc2
    zmienna1=2*zmienna1^wartosc1;
    zmienna2=2*zmienna2^wartosc2;

    //Nastepnie tworzymy ich negacje, zamieniajac parzyste na nieparzyste i odwrotnie
    int negacja_zmienna1=negacja_zmienna1^1;
    int negacja_zmienna2=negacja_zmienna2^1;
    //Tworzymy graf na podstawie opisu z poczatku funkcji oraz jego odwrotnosc potrzebna w stworzeniu silnie spojnych skladowych
    graf[negacja_zmienna1].push_back(zmienna2);
    graf[negacja_zmienna2].push_back(zmienna1);
    grafT[zmienna2].push_back(negacja_zmienna1);
    grafT[zmienna1].push_back(negacja_zmienna2);
    return;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //Wczytujemy graf
    cin>>n>>m;

    //Ustawiamy rozmiary tablic grafu do silnie spojnie skladowych na dwukrotnosc ilosci punktow
    //Poniewaz dla kazdego punktu potrzebujemy jeszcze jego negacji
    graf.resize((n+1)*2);
    grafT.resize((n+1)*2);
    for(int i=1;i<=m;i++){
        int zmienna1,zmienna2;
        int wartosc1,wartosc2;
        cin>>zmienna1>>wartosc1;
        cin>>zmienna2>>wartosc2;
        dodaj_krawedz(zmienna1,wartosc1,zmienna2,wartosc2);
    }

    rozwiaz_2SAT();
    for(int i=0;i<=n;i++){
        cout<<wartosci[i];
    }
    return 0;
}