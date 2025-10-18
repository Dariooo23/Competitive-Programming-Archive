//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int
struct wyklad{
    long long int poczatek,koniec,numer;
};

vector<wyklad> wziete1;
vector<wyklad> wziete2;
vector<wyklad> wyklady;

bool cmp(const wyklad &a,const wyklad &b){
    if(a.koniec==b.koniec){
        if(a.poczatek==b.poczatek){
            return a.numer<b.numer;
        }else{
            return a.poczatek>b.poczatek;
        }
    }else{
        return a.koniec<b.koniec;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,wynik1=0,wynik2=0;
    cin>>n;

    wyklady.resize(n);
    for(int i=0;i<n;i++){
        long long int a,b;
        cin>>a>>b;
        wyklady[i]={a,b,i};
    }

    sort(wyklady.begin(),wyklady.end(),cmp);
    //Przypadek pierwszy
    long long int koniec=0;
    for(long long int i=0;i<n;i++){
        if(wyklady[i].poczatek>=koniec){
            wziete1.push_back(wyklady[i]);
            koniec=wyklady[i].koniec;
            wynik1++;
        }
    }wynik1--;
    

    //Przypadek drugi
    long long int koniec_wyklad=0,koniec_wyklad_zast=0,koniec_zastepczy=0,flaga1=0,flaga2=0;
    wyklad wyklad_zastepczy;
    for(int i=0;i<n;i++){
        if(flaga1==0){
            if(wyklady[i].poczatek>=koniec_zastepczy){
                koniec_wyklad_zast=wyklady[i].koniec;
                wziete2.push_back(wyklady[i]);
                if(flaga2==1){
                    koniec_zastepczy=wyklady[i].koniec;
                    koniec_wyklad=koniec_wyklad_zast;
                    wziete2.push_back(wyklad_zastepczy);
                    wynik2++;
                    flaga1=0;
                    flaga2=0;
                }else{
                    flaga1=1;
                }
            }else{
                if(wyklady[i].poczatek>=koniec_wyklad){
                    wyklad_zastepczy=wyklady[i];
                    flaga2=1;
                }
            }
        }else{
            if(wyklady[i].poczatek>=koniec_wyklad){
                koniec_zastepczy=wyklady[i].koniec;
                koniec_wyklad=koniec_wyklad_zast;
                wziete2.push_back(wyklady[i]);
                wynik2++;
                flaga1=0;
            }
        }
    }

    if(wynik1>=wynik2){
        cout<<wynik1<<endl;
        for(long long int i=0;i<wziete1.size()-1;i++){
            cout<<wziete1[i].numer+1<<" "<<wziete1[wziete1.size()-1].numer+1<<endl;
        }
    }else{
        cout<<wynik2<<endl;
        for(long long int i=0;i<wziete2.size()-1;i=i+2){
            cout<<wziete2[i].numer+1<<" "<<wziete2[i+1].numer+1<<endl;
        }
    }
   
    return 0;
}