//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

//Tablica z dowolnymi wartosciami
vector<int> a;
//Tablica z sumami z pozdbiorow zbioru a
vector<int> sum;
//Suma po podmaskach mask, rozniacych sie tylko na "i" pierwszych bitach
//Np dp[mask][i], gdzie mask=1101, i=2, mamy 1101, 1100, 1001, 1000
//Obliczanie nowych dp[][] na podstawie poprzednich:
//Gdy nastepny bit nie jest zapalony dp[mask][i+1]=dp[mask][i]
//Gdy nastepny bit jest zapalony dp[mask][i+1]=dp[mask][i]+dp[mask^(1<<i)][i]

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    a.resize((1<<n)-1);
    sum.resize((1<<n)-1);

    //Iterowanie sie po wszystkich podmaskach "s", maski "mask"
    for(int mask=0;mask<(1<<n);mask++){
        for(int s=mask;s!=0;s=mask&(s-1)){
            sum[mask]=sum[mask]+a[s];
        } 
    }


    //Zadanie
    //Znajdz minimalna liczbe kolorow potrzebnych do pokolorowania grafu, tak aby dwa takie same kolory nie byly obok siebie
    //Zlozonosc 3^n, gdzie n to ilosc wierzcholkow
    //dp[s] - minimalna liczba kolorow potrzebna do pokolorowania podzbioru reprezentowanego przez maske "s"
    //dp[s]=min(z t zawierajacego sie w zbiorze s, bez zadnych krawedzi)dp[s/t]+1

    //Zadanie a1,a2,a3,...,an, gdzie n~24
    //Liczby a1,a2,...,an to odleglosci o ile mozemy sie przemiescic jednorazowo, chcemy zawsze dojsc do konca, czyli korzystamy ze 
    //Wszystkich skokow, jednak w podlodze sa 2 dziury na dowolnych pozycjach.
    //Oblicz ile jest permutacji ktorymi mozemy dojsc do konca nie wpadajac w dziure.
    //dp[mask] - wybieramy tylko ai z maski, na ile sposobow nie zginelismy
    vector<int> dp((1<<n)-1);
    vector<int> dziura={0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0};
    for(int mask=0;mask<(1<<n)+1;mask++){
        if(dziura[mask]==1){
            dp[mask]=0;
            continue;
        }
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                dp[mask]=dp[mask]+dp[mask^(1<<i)];
            }
        }
    }
    

    return 0;
}