//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int bok,pole,wynik=0;
vector<int> wysokosc;

void wiersz(){
    pair<int,int> pozycja={0,0};
    pair<int,int> pozycja2={0,0};
    stack<pair<int,int>> stos;

    for(int i=1;i<=bok+1;i++){
        bool flaga=0;
        if(!stos.empty()){
            pozycja=stos.top();
        }

        while(!stos.empty() && pozycja.second>wysokosc[i]){
            wynik=max(wynik,(i-pozycja.first)*pozycja.second);

            pozycja2=pozycja;
            stos.pop();
            flaga=1;

            if(!stos.empty()){
                pozycja=stos.top();
            }
        }

        if((stos.empty() && (wysokosc[i]>0)) || (pozycja.second<wysokosc[i])){
            if(flaga){
                stos.push({pozycja2.first,wysokosc[i]});
            }else{
                stos.push({i,wysokosc[i]});
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>bok;

    wysokosc.resize(bok+10,0);
    for(int i=1;i<=bok;i++){
        for(int j=1;j<=bok;j++){
            cin>>pole;
            if(pole){
                wysokosc[j]=0;
            }else{
                wysokosc[j]++;
            }
        }
        wiersz();
    }

    cout<<wynik;

    return 0;
}
 