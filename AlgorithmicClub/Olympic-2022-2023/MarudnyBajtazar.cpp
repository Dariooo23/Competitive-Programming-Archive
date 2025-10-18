//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> kombinacje(2e6,0);
vector<int> marudzenie(18,0);

void poczatkowe_kombinacje(string ciag)
{
    for(int i=0;i<ciag.size();i++)
    {
        int potega_dwojki=2;
        int kombinacja=0;
        int dlugosc=1;

        for(int j=i;j<min(i+17,(int)(ciag.size()));j++)
        {
            kombinacja=kombinacja+((int)((ciag[j]-'0'+1)*potega_dwojki));
            kombinacje[kombinacja]++;

            if(kombinacje[kombinacja]==1)
            {
                marudzenie[dlugosc]++;
            }

            potega_dwojki=potega_dwojki<<1;
            dlugosc++;
        }
    }
}

void aktualizuj_usun(const string &ciag, const int &indeks, int poczatek, int koniec, bool lewo, bool prawo, int kombinacja, int dlugosc)
{
    if((poczatek<0 || koniec>=ciag.size()) || (poczatek>indeks || koniec<indeks))
    {
        return;
    }


    if(lewo==1 && prawo==0)
    {
        kombinacja=((kombinacja-(((int)(ciag[koniec+1]-'0'+1))<<(koniec-poczatek+1)))<<1)+((int)(ciag[poczatek]-'0'+1)*2);

        if(kombinacje[kombinacja]==1)
        {
            marudzenie[koniec-poczatek+1]--;
        }
        kombinacje[kombinacja]--;
    }
    if(lewo==0 && prawo==1)
    {
        kombinacja=((kombinacja-((int)(ciag[poczatek-1]-'0'+1)*2))/2)+(((int)(ciag[koniec]-'0'+1))<<(koniec-poczatek+1));

        if(kombinacje[kombinacja]==1)
        {
            marudzenie[koniec-poczatek+1]--;
        }
        kombinacje[kombinacja]--;
    }


    if(lewo)
    {
        aktualizuj_usun(ciag,indeks,poczatek-1,koniec-1,1,0,kombinacja,dlugosc);
    }
    if(prawo)
    {
        aktualizuj_usun(ciag,indeks,poczatek+1,koniec+1,0,1,kombinacja,dlugosc);
    }
    return;
}
void aktualizuj_dodaj(const string &ciag, const int &indeks, int poczatek, int koniec, bool lewo, bool prawo, int kombinacja, int dlugosc)
{
    if((poczatek<0 || koniec>=ciag.size()) || (poczatek>indeks || koniec<indeks))
    {
        return;
    }


    if(lewo==1 && prawo==0)
    {
        kombinacja=((kombinacja-(((int)(ciag[koniec+1]-'0'+1))<<(koniec-poczatek+1)))<<1)+((int)(ciag[poczatek]-'0'+1)*2);

        if(kombinacje[kombinacja]==0)
        {
            marudzenie[koniec-poczatek+1]++;
        }
        kombinacje[kombinacja]++;
    }
    if(lewo==0 && prawo==1)
    {
        kombinacja=((kombinacja-((int)(ciag[poczatek-1]-'0'+1)*2))/2)+(((int)(ciag[koniec]-'0'+1))<<(koniec-poczatek+1));

        if(kombinacje[kombinacja]==0)
        {
            marudzenie[koniec-poczatek+1]++;
        }
        kombinacje[kombinacja]++;
    }


    if(lewo)
    {
        aktualizuj_dodaj(ciag,indeks,poczatek-1,koniec-1,1,0,kombinacja,dlugosc);
    }
    if(prawo)
    {
        aktualizuj_dodaj(ciag,indeks,poczatek+1,koniec+1,0,1,kombinacja,dlugosc);
    }
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int dlugosc,zmiany;
    string ciag;

    cin>>dlugosc>>zmiany>>ciag;

    poczatkowe_kombinacje(ciag);
    for(int i=1;i<=17;i++)
    {
        if(marudzenie[i]!=(1<<i))
        {
            cout<<i<<endl;
            break;
        }
    }

    while(zmiany--)
    {
        int indeks,poczatkowa_kombinacja=0;

        cin>>indeks;
        indeks--;

        int lewo=indeks,prawo=indeks+1,kolejnosc=0;

        for(int i=1;i<=17;i++)
        {
            if(kolejnosc==0)
            {
                if(lewo>=0 && lewo<ciag.size())
                {
                    poczatkowa_kombinacja=(poczatkowa_kombinacja<<1)+((int)(ciag[lewo]-'0'+1)*2);

                    kolejnosc=1;
                    lewo--;
                }
                else
                {
                    if(prawo>=0 && prawo<ciag.size())
                    {
                        poczatkowa_kombinacja=poczatkowa_kombinacja+(((int)(ciag[prawo]-'0'+1))*(1<<i));

                        kolejnosc=0;
                        prawo++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                if(prawo>=0 && prawo<ciag.size())
                {
                    poczatkowa_kombinacja=poczatkowa_kombinacja+(((int)(ciag[prawo]-'0'+1))*(1<<i));

                    kolejnosc=0;
                    prawo++;
                }
                else
                {
                    if(lewo>=0 && lewo<ciag.size())
                    {
                        poczatkowa_kombinacja=(poczatkowa_kombinacja<<1)+((int)(ciag[lewo]-'0'+1)*2);

                        kolejnosc=1;
                        lewo--;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            if(kombinacje[poczatkowa_kombinacja]==1)
            {
                marudzenie[i]--;
            }
            kombinacje[poczatkowa_kombinacja]--;

            aktualizuj_usun(ciag,indeks,lewo+1,prawo-1,1,1,poczatkowa_kombinacja,i);
        }

        if(ciag[indeks]=='0')
        {
            ciag[indeks]='1';
        }
        else
        {
            ciag[indeks]='0';
        }

        poczatkowa_kombinacja=0,lewo=indeks,prawo=indeks+1,kolejnosc=0;

        for(int i=1;i<=17;i++)
        {
            if(kolejnosc==0)
            {
                if(lewo>=0 && lewo<ciag.size())
                {
                    poczatkowa_kombinacja=(poczatkowa_kombinacja<<1)+((int)(ciag[lewo]-'0'+1)*2);

                    kolejnosc=1;
                    lewo--;
                }
                else
                {
                    if(prawo>=0 && prawo<ciag.size())
                    {
                        poczatkowa_kombinacja=poczatkowa_kombinacja+(((int)(ciag[prawo]-'0'+1))*(1<<i));

                        kolejnosc=0;
                        prawo++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                if(prawo>=0 && prawo<ciag.size())
                {
                    poczatkowa_kombinacja=poczatkowa_kombinacja+(((int)(ciag[prawo]-'0'+1))*(1<<i));

                    kolejnosc=0;
                    prawo++;
                }
                else
                {
                    if(lewo>=0 && lewo<ciag.size())
                    {
                        poczatkowa_kombinacja=(poczatkowa_kombinacja<<1)+((int)(ciag[lewo]-'0'+1)*2);

                        kolejnosc=1;
                        lewo--;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            if(kombinacje[poczatkowa_kombinacja]==0)
            {
                marudzenie[i]++;
            }
            kombinacje[poczatkowa_kombinacja]++;

            aktualizuj_dodaj(ciag,indeks,lewo+1,prawo-1,1,1,poczatkowa_kombinacja,i);
        }

        for(int i=1;i<=17;i++)
        {
            if(marudzenie[i]!=(1<<i))
            {
                cout<<i<<endl;
                break;
            }
        }

    }

    return 0;
}