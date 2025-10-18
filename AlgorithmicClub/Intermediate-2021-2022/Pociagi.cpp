//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int poziomy_drzewa=7;
const int rozmiar_drzewa=128;


vector<int> alfabet;
vector<map<long long int,int>> pary;
map<long long int,int>::iterator it;

struct etykieta
{
    vector<int> drzewo_etykiet;

    etykieta()
    {
        drzewo_etykiet.resize(2*rozmiar_drzewa+1);
        for(int i=0;i<=rozmiar_drzewa*2;i++)
        {
            drzewo_etykiet[i]=0;
        }
    }

    void zmiana(int wagon, char znak)
    {
        int warstwa=poziomy_drzewa;
        wagon=wagon+rozmiar_drzewa;
        drzewo_etykiet[wagon]=znak;

        while(wagon>>1)
        {
            wagon=wagon>>1;
            warstwa--;

            it=pary[warstwa].find((((long long int)drzewo_etykiet[wagon<<1])<<32) + (long long int)drzewo_etykiet[(wagon<<1)+1]);
            if(it==pary[warstwa].end())
            {
                alfabet[warstwa]++;
                drzewo_etykiet[wagon]=alfabet[warstwa];
                pary[warstwa][(((long long int)drzewo_etykiet[wagon<<1])<<32)+(long long int)drzewo_etykiet[(wagon<<1)+1]]=alfabet[warstwa];
            }
            else
            {
                drzewo_etykiet[wagon]=it->second;
            }
        }
    }

    char litera(int wagon)
    {
        return (char) drzewo_etykiet[wagon+rozmiar_drzewa];
    }
};
struct operacja
{
    int nastepny,waga,indeks_pociagu;
};
struct struktura_drzewa
{
    int suma,indeks_pociagu;
    bool poczatek;
};

vector<int> etykiety_grup;
vector<etykieta> pociagi;
vector<operacja> grupy;
int numer_grupy=0;

void dodaj_do_listy(int etykieta,int waga, int indeks_pociagu)
{
    if(etykiety_grup[etykieta]==-1)
    {
        etykiety_grup[etykieta]=numer_grupy;
        grupy[etykiety_grup[etykieta]].nastepny=-1;
    }
    else
    {
        grupy[numer_grupy].nastepny=etykiety_grup[etykieta];
        etykiety_grup[etykieta]=numer_grupy;
    }

    grupy[numer_grupy].waga=waga;
    grupy[numer_grupy].indeks_pociagu=indeks_pociagu;
    numer_grupy++;
}


vector<struktura_drzewa> drzewo;

int policz_dlugosc_listy(int l)
{
    int dlugosc=0;
    while(l!=-1)
    {
        l=grupy[l].nastepny;
        dlugosc++;
    }

    return dlugosc;
}
int policz_poczatek_listy(int dlugosc)
{
    int warstwa=0;
    while(dlugosc>0)
    {
        dlugosc=dlugosc>>1;
        warstwa++;
    }

    return warstwa;
}
void policz_wynik(int l)
{
    int dlugosc=policz_dlugosc_listy(etykiety_grup[l]);
    int start=1<<policz_poczatek_listy(dlugosc);
    int pozycja=dlugosc+start-1;

    for(int i=etykiety_grup[l];i!=-1;i=grupy[i].nastepny,pozycja--)
    {
        drzewo[pozycja].indeks_pociagu=grupy[i].indeks_pociagu;
        drzewo[pozycja].suma=grupy[i].waga;
        drzewo[pozycja].poczatek=(grupy[i].waga==1);
    }

    for(int i=start+1;i<=start+dlugosc-1;i++)
    {
        drzewo[i].suma=drzewo[i].suma+drzewo[i-1].suma;
    }

    while(pozycja)
    {
        drzewo[pozycja].suma=max(drzewo[2*pozycja].suma,drzewo[2*pozycja+1].suma);
        pozycja--;
    }

    for(int i=start;i<=start+dlugosc-1;i++)
    {
        if(drzewo[i].poczatek)
        {
            pociagi[drzewo[i].indeks_pociagu].drzewo_etykiet[1]=i;
        }
        else
        {
            int lewy=pociagi[drzewo[i].indeks_pociagu].drzewo_etykiet[1];
            int prawy=i;
            int wynik=0;

            while(lewy<prawy)
            {
                if((lewy&1)==1)
                {
                    wynik=max(wynik,drzewo[lewy].suma);
                    lewy++;
                }
                if((prawy&1)==0)
                {
                    wynik=max(wynik,drzewo[prawy].suma);
                    prawy--;
                }

                lewy=lewy>>1;
                prawy=prawy>>1;
            }

            if(lewy==prawy)
            {
                wynik=max(wynik,drzewo[lewy].suma);
            }

            pociagi[drzewo[i].indeks_pociagu].drzewo_etykiet[0]=max(pociagi[drzewo[i].indeks_pociagu].drzewo_etykiet[0],wynik);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int ilosc,dlugosc,zmiany;
    cin>>ilosc>>dlugosc>>zmiany;


    etykiety_grup.resize(2*ilosc*dlugosc+4*zmiany,-1);
    drzewo.resize(2*(2*ilosc*dlugosc+4*zmiany));
    grupy.resize(2*ilosc*dlugosc+4*zmiany);
    alfabet.resize(poziomy_drzewa+9,0);
    pary.resize(poziomy_drzewa+9);
    pociagi.resize(ilosc+9);
    
    for(int i=0;i<ilosc;i++)
    {
        string pociag;
        cin>>pociag;
        for(int j=0;j<dlugosc;j++)
        {
            pociagi[i].zmiana(j,pociag[j]);
        }
        dodaj_do_listy(pociagi[i].drzewo_etykiet[1],1,i);
    }

    for(int i=1;i<=zmiany;i++)
    {
        int pociag1,pociag2,wagon1,wagon2;
        cin>>pociag1>>wagon1>>pociag2>>wagon2;
        pociag1--; wagon1--; pociag2--; wagon2--;

        int litera_wagonu1=pociagi[pociag2].litera(wagon2);
        int litera_wagonu2=pociagi[pociag1].litera(wagon1);

        dodaj_do_listy(pociagi[pociag1].drzewo_etykiet[1],-1,pociag1);
        if(pociag1!=pociag2)
        {
            dodaj_do_listy(pociagi[pociag2].drzewo_etykiet[1],-1,pociag2);
        }

        pociagi[pociag1].zmiana(wagon1,litera_wagonu1);
        pociagi[pociag2].zmiana(wagon2,litera_wagonu2);

        if(pociag1!=pociag2)
        {
            dodaj_do_listy(pociagi[pociag1].drzewo_etykiet[1],1,pociag1);
        }
        dodaj_do_listy(pociagi[pociag2].drzewo_etykiet[1],1,pociag2);
    }
    for(int i=0;i<ilosc;i++)
    {
        dodaj_do_listy(pociagi[i].drzewo_etykiet[1],-1,i);
    }
    
    for(int i=0;i<2*ilosc*dlugosc+4*zmiany;i++)
    {
        if(etykiety_grup[i]!=-1)
        {
            policz_wynik(i);
        }
    }
    for(int i=0;i<ilosc;i++)
    {
        cout<<pociagi[i].drzewo_etykiet[0]<<endl;
    }
    return 0;
}
 