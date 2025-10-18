//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int n,p,d,przod,tyl,koniec1;
vector<long long int> kolejka;
vector<long long int> prefiksy;
vector<long long int> pokrycie;
vector<long long int> doly;

long long int maksimum(int poczatek, int koniec)
{
  if(koniec1<koniec)
  {
    koniec1=koniec;

    while(przod<tyl && pokrycie[kolejka[tyl-1]]<=pokrycie[koniec])
    {
      tyl--;
    }

    kolejka[tyl++]=koniec;
  }
  
  while(przod<tyl && kolejka[przod]<poczatek)
  {
    przod++;
  }
  
  if(przod==tyl)
  {
    return 0;
  }
  return pokrycie[kolejka[przod]];
}

bool dziala(int poczatek,int koniec)
{
    if(koniec>n)
    {
        return 0;
    }

    return (prefiksy[koniec]-prefiksy[poczatek-1]-maksimum(poczatek,koniec-d+1)<=p);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>p>>d;

    doly.resize(n+9,0);
    kolejka.resize(n+9,0);
    prefiksy.resize(n+9,0);
    pokrycie.resize(n+9,0);


    prefiksy[0]=0;
    pokrycie[1]=0;

    for(int i=1;i<=n;i++)
    {
        cin>>doly[i];
        prefiksy[i]=prefiksy[i-1]+doly[i];
    }
    for(int i=1;i<=d;i++)
    {
        pokrycie[1]=pokrycie[1]+doly[i];
    }
    for(int i=2;i<=n-d+1;i++)
    {
        pokrycie[i]=pokrycie[i-1]-doly[i-1]+doly[i+d-1];
    }


    long long int wynik=d;
    long long int j=d;
    kolejka[tyl++]=1;
    koniec1=1;

    for(int i=1;i<=n-d+1;i++)
    {
        while(dziala(i,j+1))
        {
            j++;
        }

        wynik=max(wynik,j-i+1);
    }
    
    cout<<wynik;


    return 0;
}