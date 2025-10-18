//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

long long int indeks_polowa=-1;
long long int suma1=0,suma2=0,roznicag=0;
map<long long int,pair<long long int,pair<long long int,long long int>>> oddaje_zap;
map<long long int,pair<long long int,pair<long long int,long long int>>> potrzebuje_zap;
string rownanie,rownanie_lewo="",rownanie_prawo="";

void wypisz(int strona1,int indeks1,int zmiana1,int strona2,int indeks2,int zmiana2){
    for(int i=0;i<rownanie_lewo.size();i++){
        if(i==0 && rownanie_lewo[0]=='+'){
            continue;
        }
        if(i==indeks1 && strona1==1){
            cout<<zmiana1;
            continue;
        }
        if(i==indeks2 && strona2==1){
            cout<<zmiana2;
            continue;
        }
        cout<<rownanie_lewo[i];
    }

    cout<<"=";

    for(int i=0;i<rownanie_prawo.size();i++){
        if(i==0 && rownanie_prawo[i]=='+'){
            continue;
        }
        if(i+indeks_polowa==indeks1 && strona1==2){
            cout<<zmiana1;
            continue;
        }
        if(i+indeks_polowa==indeks1 && strona2==2){
            cout<<zmiana2;
            continue;
        }
        cout<<rownanie_prawo[i];
    }

    exit(0);
}
void zamien_na_liczbe(string znak,string liczba,int strona,int indeks){
    long long int suma=0,potega=1;
    for(int i=liczba.size()-1;i>=0;i--){
        long long int cyfra;
        cyfra=liczba[i]-'0';
        suma=suma+cyfra*potega;
        potega=potega*10;
    }
    if(strona==1){
        if(znak=="+")suma1=suma1+suma;
        if(znak=="-")suma1=suma1-suma;
    }
    if(strona==2){
        if(znak=="+")suma2=suma2+suma;
        if(znak=="-")suma2=suma2-suma;
    }
}
void dodaj(int zapalki,int suma,int strona,int indeks,int zmiana){
    //Zmiana tej samej liczby na inna
    if(zapalki==0){
        if(strona==1){
            if(roznicag+suma==0)wypisz(strona,indeks,zmiana,-1,-1,-1);
        }else{
            if(roznicag-suma==0)wypisz(strona,indeks,zmiana,-1,-1,-1);
        }
    }
    //Potrzeba zapalki do zmiany
    if(zapalki==1){
        if(strona==1){
            long long int dopelnienie=-(roznicag+suma);
            if(oddaje_zap.find(dopelnienie)!=oddaje_zap.end()){
                pair<long long int,pair<long long int,long long int>> zmiana2=oddaje_zap[dopelnienie];
                if(indeks!=zmiana2.first)
                wypisz(strona,indeks,zmiana,zmiana2.second.second,zmiana2.first,zmiana2.second.first);
                else potrzebuje_zap[suma]={indeks,{zmiana,strona}};
            }else{
                potrzebuje_zap[suma]={indeks,{zmiana,strona}};
            }
        }else{
            long long int dopelnienie=-(roznicag-suma);
            if(oddaje_zap.find(dopelnienie)!=oddaje_zap.end()){
                pair<long long int,pair<long long int,long long int>> zmiana2=oddaje_zap[dopelnienie];
                if(indeks!=zmiana2.first)
                wypisz(strona,indeks,zmiana,zmiana2.second.second,zmiana2.first,zmiana2.second.first);
                else potrzebuje_zap[-suma]={indeks,{zmiana,strona}};
            }else{
                potrzebuje_zap[-suma]={indeks,{zmiana,strona}};
            }
        }
    }
    //Wolna zapalka do oddania gdzies
    if(zapalki==-1){
        if(strona==1){
            long long int dopelnienie=-(roznicag+suma);
            if(potrzebuje_zap.find(dopelnienie)!=potrzebuje_zap.end()){
                pair<long long int,pair<long long int,long long int>> zmiana2=potrzebuje_zap[dopelnienie];
                if(indeks!=zmiana2.first)
                wypisz(strona,indeks,zmiana,zmiana2.second.second,zmiana2.first,zmiana2.second.first);
                else oddaje_zap[suma]={indeks,{zmiana,strona}};
            }else{
                oddaje_zap[suma]={indeks,{zmiana,strona}};
            }
        }else{
            long long int dopelnienie=-(roznicag-suma);
            if(potrzebuje_zap.find(dopelnienie)!=potrzebuje_zap.end()){
                pair<long long int,pair<long long int,long long int>> zmiana2=potrzebuje_zap[dopelnienie];
                if(indeks!=zmiana2.first)
                wypisz(strona,indeks,zmiana,zmiana2.second.second,zmiana2.first,zmiana2.second.first);
                else oddaje_zap[-suma]={indeks,{zmiana,strona}};
            }else{
                oddaje_zap[-suma]={indeks,{zmiana,strona}};
            }
        }
    }
}
void zero(string znak,int cyfra,int potega,int strona,int indeks){
    long long int roznica;
    //Z 0 na 6
    roznica=6*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(0,roznica,strona,indeks,6);
    //Z 0 na 9 
    roznica=9*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(0,roznica,strona,indeks,9);
    //Z 0 na 8  
    roznica=8*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(1,roznica,strona,indeks,8);
    return;
}
void jedynka(string znak,int cyfra,int potega,int strona,int indeks){
    long long int roznica;
    //Z 1 na 7;
    roznica=6*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(1,roznica,strona,indeks,7);
    return;
}
void dwojka(string znak,int cyfra,int potega,int strona,int indeks){
    long long int roznica;
    //Z 2 na 3
    roznica=1*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(0,roznica,strona,indeks,3);
    return;
}
void trojka(string znak,int cyfra,int potega,int strona,int indeks){
    long long int roznica;
    //Z 3 na 2
    roznica=-1*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(0,roznica,strona,indeks,2);
    //Z 3 na 5 
    roznica=2*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(0,roznica,strona,indeks,5);
    //Z 3 na 9 
    roznica=6*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(1,roznica,strona,indeks,9);
    return;
}
void czworka(string znak,int cyfra,int potega,int strona,int indeks){
    //Beka z czworki
    return;
}
void piatka(string znak,int cyfra,int potega,int strona,int indeks){
    long long int roznica;
    //Z 5 na 3
    roznica=-2*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(0,roznica,strona,indeks,3);
    //Z 5 na 6
    roznica=1*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(1,roznica,strona,indeks,6);
    //Z 5 na 9
    roznica=4*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(1,roznica,strona,indeks,9);
    return;
}
void szostka(string znak,int cyfra,int potega,int strona,int indeks){
    long long int roznica;
    //Z 6 na 0
    roznica=-6*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(0,roznica,strona,indeks,0);
    //Z 6 na 5
    roznica=-1*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(-1,roznica,strona,indeks,5);
    //Z 6 na 8
    roznica=2*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(1,roznica,strona,indeks,8);
    //Z 6 na 9 
    roznica=3*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(0,roznica,strona,indeks,9); 
    return;
}
void siodemka(string znak,int cyfra,int potega,int strona,int indeks){
    long long int roznica;
    //Z 7 na 1
    roznica=-6*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(-1,roznica,strona,indeks,1);
    return;
}
void osemka(string znak,int cyfra,int potega,int strona,int indeks){
    long long int roznica;
    //Z 8 na 0
    roznica=-8*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(-1,roznica,strona,indeks,0);
    //Z 8 na 6
    roznica=-2*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(-1,roznica,strona,indeks,6);
    //Z 8 na 9 
    roznica=1*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(-1,roznica,strona,indeks,9);
    return;
}
void dziewiatka(string znak,int cyfra,int potega,int strona,int indeks){
    long long int roznica;
    //Z 9 na 0 
    roznica=-9*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(0,roznica,strona,indeks,0);
    //Z 9 na 3
    roznica=-6*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(-1,roznica,strona,indeks,3);
    //Z 9 na 5
    roznica=-4*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(-1,roznica,strona,indeks,5);
    //Z 9 na 6
    roznica=-3*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(0,roznica,strona,indeks,6);
    //Z 9 na 8 
    roznica=-1*potega;
    if(znak=="-")roznica=roznica*-1;
    dodaj(1,roznica,strona,indeks,8);
    return;
}
void popraw_rownanie(string znak,string liczba,int strona,int indeks){
    long long int potega=1;
    for(int i=liczba.size()-1;i>=0;i--){
        long long int cyfra;
        cyfra=liczba[i]-'0';
        if(cyfra==0){
            zero(znak,cyfra,potega,strona,i+indeks);
        }
        if(cyfra==1){
            jedynka(znak,cyfra,potega,strona,i+indeks);
        }
        if(cyfra==2){
            dwojka(znak,cyfra,potega,strona,i+indeks);
        }
        if(cyfra==3){
            trojka(znak,cyfra,potega,strona,i+indeks);
        }
        if(cyfra==4){
            czworka(znak,cyfra,potega,strona,i+indeks);
        }
        if(cyfra==5){
            piatka(znak,cyfra,potega,strona,i+indeks);
        }
        if(cyfra==6){
            szostka(znak,cyfra,potega,strona,i+indeks);
        }
        if(cyfra==7){
            siodemka(znak,cyfra,potega,strona,i+indeks);
        }
        if(cyfra==8){
            osemka(znak,cyfra,potega,strona,i+indeks);
        }
        if(cyfra==9){
            dziewiatka(znak,cyfra,potega,strona,i+indeks);
        }
        potega=potega*10;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>rownanie;

    for(int i=0;i<rownanie.size();i++){
        if(rownanie[i]=='='){
            indeks_polowa=i;
        }
    }

    rownanie_lewo=rownanie.substr(0,indeks_polowa);
    rownanie_prawo=rownanie.substr(indeks_polowa+1,rownanie.size()-(indeks_polowa+1));
    if(rownanie_lewo[0]!='-')rownanie_lewo="+"+rownanie_lewo;
    if(rownanie_prawo[0]!='-')rownanie_prawo="+"+rownanie_prawo;

    indeks_polowa+=2;

    //USTALANIE SUM PO OBU STRONACH ROWNANIA
    string znak="",liczba="";
    int indeks=0;
    for(int i=0;i<rownanie_lewo.size();i++){
        if(rownanie_lewo[i]=='-' || rownanie_lewo[i]=='+'){
            if(liczba.size()!=0){
                zamien_na_liczbe(znak,liczba,1,indeks);
                liczba.clear();
                znak.clear();
            }
            indeks=i+1;
            znak=rownanie_lewo[i];
        }else{
            liczba.push_back(rownanie_lewo[i]);
        }
    }
    if(liczba.size()!=0){
        zamien_na_liczbe(znak,liczba,1,indeks);
        liczba.clear();
    }


    indeks=0;
    for(int i=0;i<rownanie_prawo.size();i++){
        if(rownanie_prawo[i]=='-' || rownanie_prawo[i]=='+'){
            if(liczba.size()!=0){
                zamien_na_liczbe(znak,liczba,2,indeks);
                liczba.clear();
                znak.clear();
            }
            indeks=indeks_polowa+i+1;
            znak=rownanie_prawo[i];
        }else{
            liczba.push_back(rownanie_prawo[i]);
        }
    }
    if(liczba.size()!=0){
        zamien_na_liczbe(znak,liczba,2,indeks);
        liczba.clear();
    }

    roznicag=suma1-suma2;
    //cout<<suma1<<" "<<suma2<<" "<<roznicag<<endl;


    //POPRAWIANIE ROWNANIA
    for(int i=0;i<rownanie_lewo.size();i++){
        if(rownanie_lewo[i]=='-' || rownanie_lewo[i]=='+'){
            if(liczba.size()!=0){
                popraw_rownanie(znak,liczba,1,indeks);
                liczba.clear();
                znak.clear();
            }
            indeks=i+1;
            znak=rownanie_lewo[i];
        }else{
            liczba.push_back(rownanie_lewo[i]);
        }
    }
    if(liczba.size()!=0){
        popraw_rownanie(znak,liczba,1,indeks);
        liczba.clear();
    }


    indeks=0;
    for(int i=0;i<rownanie_prawo.size();i++){
        if(rownanie_prawo[i]=='-' || rownanie_prawo[i]=='+'){
            if(liczba.size()!=0){
                popraw_rownanie(znak,liczba,2,indeks);
                liczba.clear();
                znak.clear();
            }
            indeks=indeks_polowa+i+1;
            znak=rownanie_prawo[i];
        }else{
            liczba.push_back(rownanie_prawo[i]);
        }
    }
    if(liczba.size()!=0){
        popraw_rownanie(znak,liczba,2,indeks);
        liczba.clear();
    }

    cout<<"no";
    return 0;
}