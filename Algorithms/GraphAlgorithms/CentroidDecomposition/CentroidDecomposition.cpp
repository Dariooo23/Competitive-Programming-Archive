//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n;
//Tablica przechowująca graf (Dokładniej drzewo)
vector<vector<int>> g;

//Tablica przechowująca rozmiary poddrzew obliczone w stosunku do kolejnych centroidów
vector<int> rozmiar_poddrzew;

//Tablica przechowująca punkty które już zostały uznane za centroid dzieląc wstępne drzewo na coraz większą ich ilość
//Oraz ograniczając przy tym wyliczanie funkcji "oblicz_poddrzewa" do coraz mniejszych drzew.
vector<bool> uzyte;


//Funkcja obliczająca rozmiar wszystkich poddrzew w danym drzewie ukorzenionym w centroidzie
void oblicz_poddrzewa(int s,int p)
{
    rozmiar_poddrzew[s]=1;
    for(int v :g[s])
    {
        if(v!=p && uzyte[v]==0)
        {
            oblicz_poddrzewa(v,s);
            rozmiar_poddrzew[s]=rozmiar_poddrzew[s]+rozmiar_poddrzew[v];
        }
    }
}

//Funkcja przechodząca po całym drzewie w celu znalezienia nowego centroida który podzieli te drzewo na następne
//Mniejsze drzewa o rozmiarze maksymalnie n/2, gdzie n to ilosc punktow w aktualnym drzewie
int findCent(int w,int parent,int n)
{
    for(int v : g[w])
    {
        if(uzyte[v]==0 && v!=parent)
        {
             if(rozmiar_poddrzew[v]>n/2)
             {
                return findCent(v,w,n);
             }
        }
    }
    return w;
}

//Funkcja dzieląca całe drzewo na coraz mniejsze aż dojdzie do pojedynczych punktów
//(Takich podziałów będzie logarytmicznie wiele ze względu na podział drzewa na poddrzewa o rozmiarach co najwyżej n/2)
//Na początku wywołujemy oblicz_poddrzewa, aby później na podstawie rozmiarów poddrzew obliczyć centroid.
//Zaznaczamy wtedy go jako użyte, dzieląc tym samym drzewo na kilka mniejszych drzew w jego dzieciach
void decompose(int w)
{
    oblicz_poddrzewa(w,-1);

    int c=findCent(w,-1,rozmiar_poddrzew[w]);
    cout<<c<<" ";
    uzyte[c]=1;

    for(int v : g[c])
    {
        if(uzyte[v]==0)
        {
            decompose(v);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //Wczytujemy rozmiar drzewa
    cin>>n;

    g.resize(n+1);
    uzyte.resize(n+1,0);
    rozmiar_poddrzew.resize(n+1);

    //Wczytujemy graf
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    decompose(1);

    return 0;
}