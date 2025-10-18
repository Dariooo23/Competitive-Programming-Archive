//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int filary;
vector<long long int> wysokosci;  

long long int czy_dziala(long long int dzielnik)
{
    long long int wynik=0;
    map<long long int,long long int> reszty;
    for(int k=0;k<filary;k++)
    {
        reszty[wysokosci[k]%dzielnik]++;
        wynik=max(wynik,reszty[wysokosci[k]%dzielnik]);
    }
    return wynik;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>filary;

    wysokosci.resize(filary+1);

    for(int i=0;i<filary;i++)
    {
        cin>>wysokosci[i];
    }

    long long int wynik=1;
    for(int i=1;i<=40;i++)
    {
        int indeks1=rand()%filary,indeks2=rand()%filary;
        long long int roznica=abs(wysokosci[indeks1]-wysokosci[indeks2]);

        long long int dzielnik=2;
        long long int roznica2=roznica;
        while(roznica>1 && dzielnik*dzielnik<=roznica2)
        {
            if(roznica%dzielnik==0)
            {
                wynik=max(wynik,czy_dziala(dzielnik));
            }
            while(roznica%dzielnik==0)
            {
                roznica=roznica/dzielnik;
            }
            dzielnik++;
        }
        if(roznica>1)
        {
            wynik=max(wynik,czy_dziala(roznica));
        }
    }

    cout<<wynik;

    return 0;
}
 