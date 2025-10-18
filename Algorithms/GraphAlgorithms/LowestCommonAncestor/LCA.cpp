//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;
//DRZEWO
vector<vector<int>> g;
//TABLICA PRZODKÓW GDZIE PRZODKOWIE[X][K] OZNACZA PRZODKA ODDALONEGO OD X O 2^K KRAWĘDZI.
vector<vector<int>> przodkowie;
//TABLICA MÓWIĄCA NA KTÓREJ WARSTWIE DRZEWA JEST PUNKT
vector<int> glebokosc;

//DFS USTALAJACY OJCOW I GŁĘBOKOŚĆ PUNKTÓW
void ojcowie(int s,int p)
{
    przodkowie[s][0]=p;
    glebokosc[s]=glebokosc[p]+1;
    for(const int &v:g[s])
    {
        if(v!=p)
        {
            ojcowie(v,s);
        }
    }
}

//FUNKCJA USTALAJĄCA TABLICE PRZODKÓW DLA KAŻDEGO PUNKTU
void stworz_przodkow(int n)
{
    for(int k=1;k<=20;++k)
    {
        for(int x=1;x<=n;++x)
        {
            przodkowie[x][k]=przodkowie[przodkowie[x][k-1]][k-1];
        }
    }
}

//FUNKCJA ZWRACAJĄCA OSTATNIEGO WSPÓLNEGO PRZODKA
int lca(int a,int b)
{
    if(glebokosc[a]>glebokosc[b])
    {
        swap(a,b);
    }
    for(int k=20;k>=0;--k)
    {
        if(glebokosc[przodkowie[b][k]]>=glebokosc[a])
        {
            b=przodkowie[b][k];
        }
    }
    if(a==b)
    {
        return a;
    }
    for(int k=20;k>=0;--k)
    {
        if(przodkowie[a][k]!=przodkowie[b][k])
        {
            a=przodkowie[a][k];
            b=przodkowie[b][k];
        }
    }
    return przodkowie[a][0];
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    //WCZYTYWANIE DANYCH 
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    glebokosc.resize(n+1);
    przodkowie.resize(n+1,vector<int> (21));
    for(int i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    //USTALANIE OJCOW KAZDEGO PUNKTU;
    glebokosc[0]=0;
    ojcowie(1,1);

    //TWORZENIE TALBICY PRZODKÓW
    stworz_przodkow(n);
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<przodkowie[i][0]<<endl;
    }
    //SZUKANIE LCA DLA PUNKTOW A I B
    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<"OSTATNI WSPOLNY PRZODEK PUNKTÓW "<<a<<" I "<<b<<" TO: "<<lca(a,b)<<endl;
    }
    return 0;
}
 