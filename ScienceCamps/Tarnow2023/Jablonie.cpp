//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> drzewa;

void brut(){
    for(int i=0;i<m;i++){
        string polecenie;
        cin>>polecenie;
        int wynik=0,c,d;
        if(polecenie=="zbieraj"){
            cin>>c>>d;
            for(int j=0;j<n;j++){
                if(drzewa[j]>=c && drzewa[j]<=d){
                    wynik++;
                }
            }
            cout<<wynik<<endl;
        }else{
            sort(drzewa.begin(),drzewa.end());
            cin>>c;
            for(int j=0;j<c;j++){
                drzewa[j]++;
            }
        }
    }
}
void czy_posortowane(){
    int indeks_bledu=-1;
    for(int i=1;i<n;i++){
        if(drzewa[i-1]>drzewa[i]){
            indeks_bledu=i;
        }
    }

    if(indeks_bledu!=-1){
        int wskaznik1=indeks_bledu-1,wskaznik2=indeks_bledu;
        while(wskaznik1-1>=0 && drzewa[wskaznik1-1]==drzewa[wskaznik1]){
            wskaznik1--;
        }
        while(wskaznik2+1<n && drzewa[wskaznik2+1]==drzewa[wskaznik2]){
            wskaznik2++;
        }
    
        int liczba1=drzewa[wskaznik1],liczba2=drzewa[wskaznik2];
        int dlugosc1=indeks_bledu-wskaznik1-1,dlugosc2=wskaznik2-indeks_bledu+1;

        for(int i=wskaznik1;i<wskaznik1+dlugosc2;i++){
            drzewa[i]=liczba2;
        }
        for(int i=wskaznik1+dlugosc2;i<indeks_bledu+dlugosc1;i++){
            drzewa[i]=liczba1;
        }
    }

    return;
}
void mniejszybrut(){

    sort(drzewa.begin(),drzewa.end());
    for(int i=0;i<m;i++){
        string polecenie;
        cin>>polecenie;
        int wynik=0,c,d;
        if(polecenie=="zbieraj"){
            cin>>c>>d;
            int lewo=0,prawo=n,srodek,poczatek,koniec;
            while(lewo<prawo){
                srodek=(lewo+prawo)/2;
                if(drzewa[srodek]<c){
                    lewo=srodek+1;
                }else{
                    prawo=srodek;
                }
            }
            poczatek=lewo;

            lewo=0,prawo=n;
            while(lewo<prawo){
                srodek=(lewo+prawo)/2;
                if(drzewa[srodek]<=d){
                    lewo=srodek+1;
                }else{
                    prawo=srodek;
                }
            }
            koniec=lewo;
            
            cout<<koniec-poczatek<<endl;
        }else{
            cin>>c;
            for(int j=0;j<c;j++){
                drzewa[j]++;
            }
            czy_posortowane();
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n>>m;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        drzewa.push_back(a);
    }

    if(n<=3000 && m<=3000){
        brut();
    }else{
        mniejszybrut();
    }
    return 0;
}
 