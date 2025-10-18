//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int


const long long int podstawa1=31;
const long long int podstawa2=29;
const long long int modulo=1e9+7;

long long int potegowanie(long long int a,long long int b){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        long long int wynik=(potegowanie(a,b/2))%modulo;
        return (wynik*wynik)%modulo;
    }else{
        return (a*potegowanie(a,b-1))%modulo;
    }
}

long long int odwrotnosc_modulo1=potegowanie(podstawa1,modulo-2)%modulo;
long long int odwrotnosc_modulo2=potegowanie(podstawa2,modulo-2)%modulo;

map<pair<int,int>,vector<int>> litery;
long long int hash1=0,hash2=0,potega1=1,potega2=1,indeks=0;

void policz_wstepny_hash(string slowo,long long int &k){
    while(indeks<k){
        indeks++;
        potega1=(potega1*podstawa1)%modulo;
        potega2=(potega2*podstawa2)%modulo;
        hash1=(hash1+((slowo[indeks]-'a'+1)*potega1)%modulo)%modulo;
        hash2=(hash2+((slowo[indeks]-'a'+1)*potega2)%modulo)%modulo;
    }

    return;
}

void policz_wejsciowe_slowo(string slowo,long long int &k,long long int &n){
    while(indeks<n){
        indeks++;
        if(litery.find({hash1,hash2})==litery.end()){
            litery[{hash1,hash2}].resize(31,0);
            litery[{hash1,hash2}][29]=(int)('a');
        }
        vector<int> &dane=litery[{hash1,hash2}];

        dane[slowo[indeks]-'a']++;
        if(dane[slowo[indeks]-'a']>dane[28]){
            dane[28]=dane[slowo[indeks]-'a'];
            dane[29]=(int)slowo[indeks];
        }else{
            if(dane[slowo[indeks]-'a']==dane[28] && (char)(dane[29])>slowo[indeks]){
                dane[28]=dane[slowo[indeks]-'a'];
                dane[29]=(int)slowo[indeks];
            }
        }

        long long int dodajnik1=0,odejmnik1=0,dodajnik2=0,odejmnik2=0;
        odejmnik1=(slowo[indeks-k]-'a'+1)%modulo;
        dodajnik1=((slowo[indeks]-'a'+1)*potega1)%modulo;
        hash1=(((((hash1*odwrotnosc_modulo1)%modulo)-odejmnik1+modulo)%modulo)+dodajnik1)%modulo;
        odejmnik2=(slowo[indeks-k]-'a'+1)%modulo;
        dodajnik2=((slowo[indeks]-'a'+1)*potega2)%modulo;
        hash2=(((((hash2*odwrotnosc_modulo2)%modulo)-odejmnik2+modulo)%modulo)+dodajnik2)%modulo;
    }

    return;
}

bool czy_koniec=0;
long long int poczatek_cyklu,koniec_cyklu,dlugosc_cyklu,dlugosc_poczatku;
void policz_dalsza_czesc(string &slowo,long long int &k,long long int &n,long long int &a, long long int &b){
    while(indeks<=b){
        indeks++;
        if(litery.find({hash1,hash2})==litery.end()){
            litery[{hash1,hash2}].resize(31,0);
            litery[{hash1,hash2}][29]=(int)('a');
        }
        vector<int> &dane=litery[{hash1,hash2}];

        if(czy_koniec==0){
            if(indeks>n+k){
                if(dane[30]==0){
                    dane[30]=indeks;
                }else{
                    czy_koniec=1;
                    poczatek_cyklu=dane[30]-k;
                    dlugosc_cyklu=indeks-dane[30];
                    koniec_cyklu=poczatek_cyklu+dlugosc_cyklu-1;

                    dlugosc_poczatku=poczatek_cyklu-1;
                    long long int roznik=a-dlugosc_poczatku-1;
                    if(roznik>=0){
                        long long int iloracznik=roznik/dlugosc_cyklu;
                        a=a-iloracznik*dlugosc_cyklu;
                        b=b-iloracznik*dlugosc_cyklu;
                    }
                    break;
                }
            }
        }

        slowo.push_back((char)(dane[29]));
        dane[slowo[indeks]-'a']++;
        if(dane[slowo[indeks]-'a']>dane[28]){
            dane[28]=dane[slowo[indeks]-'a'];
            dane[29]=(int)slowo[indeks];
        }else{
            if(dane[slowo[indeks]-'a']==dane[28] && (char)(dane[29])>slowo[indeks]){
                dane[28]=dane[slowo[indeks]-'a'];
                dane[29]=(int)slowo[indeks];
            }
        }

        long long int dodajnik1=0,odejmnik1=0,dodajnik2=0,odejmnik2=0;
        odejmnik1=(slowo[indeks-k]-'a'+1)%modulo;
        dodajnik1=((slowo[indeks]-'a'+1)*potega1)%modulo;
        hash1=(((((hash1*odwrotnosc_modulo1)%modulo)-odejmnik1+modulo)%modulo)+dodajnik1)%modulo;
        odejmnik2=(slowo[indeks-k]-'a'+1)%modulo;
        dodajnik2=((slowo[indeks]-'a'+1)*potega2)%modulo;
        hash2=(((((hash2*odwrotnosc_modulo2)%modulo)-odejmnik2+modulo)%modulo)+dodajnik2)%modulo;
    }
    return;
}

void wypisz(string slowo,long long int &a,long long int &b){
    if(czy_koniec==1){
        long long int indeks2=0;
        long long int przesuniecie=(max((long long int)0,(a-poczatek_cyklu)))%dlugosc_cyklu;

        while(indeks2<=(b-a) && indeks2+a<=dlugosc_poczatku){
            cout<<slowo[indeks2+a];
            indeks2++;
        }
        while(indeks2<=(b-a)){
            cout<<slowo[poczatek_cyklu+(przesuniecie)%dlugosc_cyklu];
            przesuniecie++;
            indeks2++;
        }
    }else{
        for(int i=a;i<=b;i++){
            cout<<slowo[i];
        }
    }

    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,k,a,b;
    string slowo;

    cin>>n>>k>>a>>b;
    cin>>slowo;
    slowo='#'+slowo;

    policz_wstepny_hash(slowo,k);
    policz_wejsciowe_slowo(slowo,k,n);
    policz_dalsza_czesc(slowo,k,n,a,b);
    wypisz(slowo,a,b);
    return 0;
}