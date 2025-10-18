//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<long long int> prefhash1;
vector<long long int> prefhash2;
vector<long long int> sufhash1;
vector<long long int> sufhash2;
vector<long long int> potegi1;
vector<long long int> potegi2;

int n,q;
string slowo;
const int modulo=1e9+696969;
const int podstawa1=29,podstawa2=7;

void potegi()
{
    potegi1[0]=1;
    potegi2[0]=1;

    for(int i=1;i<=n;i++)
    {
        potegi1[i]=(potegi1[i-1]*podstawa1)%modulo;
        potegi2[i]=(potegi2[i-1]*podstawa2)%modulo;
    }
}


void suf_hashowanie(string slowo)
{
    sufhash1[slowo.size()+1]=0;
    sufhash2[slowo.size()+1]=0;

    for(int i=slowo.size();i>=1;i--)
    {
        sufhash1[i]=(sufhash1[i+1]+((slowo[i-1]-'a'+1)*potegi1[n-i+1])%modulo)%modulo;
        sufhash2[i]=(sufhash2[i+1]+((slowo[i-1]-'a'+1)*potegi2[n-i+1])%modulo)%modulo;
    }
}
void pref_hashowanie(string slowo)
{
    prefhash1[0]=0;
    prefhash2[0]=0;

    for(int i=1;i<=slowo.size();i++)
    {
        prefhash1[i]=(prefhash1[i-1]+((slowo[i-1]-'a'+1)*potegi1[i])%modulo)%modulo;
        prefhash2[i]=(prefhash2[i-1]+((slowo[i-1]-'a'+1)*potegi2[i])%modulo)%modulo;
    }
}


pair<long long int,long long int> subprefhash(int poczatek,int koniec,int rozmiar)
{
    return {(((prefhash1[koniec]-prefhash1[poczatek-1]+modulo)%modulo)*potegi1[rozmiar-koniec])%modulo,
            (((prefhash2[koniec]-prefhash2[poczatek-1]+modulo)%modulo)*potegi2[rozmiar-koniec])%modulo};
}
pair<long long int,long long int> subsufhash(int poczatek,int koniec,int rozmiar)
{
    return {(((sufhash1[poczatek]-sufhash1[koniec+1]+modulo)%modulo)*potegi1[poczatek-1])%modulo,
            (((sufhash2[poczatek]-sufhash2[koniec+1]+modulo)%modulo)*potegi2[poczatek-1])%modulo};
}


int main()
{
    //PROGRAM WYKORZYSTUJACY PODWOJNE HASHOWANIE PREFIKSOWE I SUFIKSOWE DO SPRAWDZENIA CZY DANY PRZEDZIAL W SLOWIE JEST PALINDROMEM
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>q>>slowo;

    prefhash1.resize(n+1);
    prefhash2.resize(n+1);
    sufhash1.resize(n+2);
    sufhash2.resize(n+2);
    potegi1.resize(n+1);
    potegi2.resize(n+1);

    potegi();
    suf_hashowanie(slowo);
    pref_hashowanie(slowo);

    while(q--)
    {
        int poczatek,koniec;
        cin>>poczatek>>koniec;

        if(subsufhash(poczatek,koniec,n)==subprefhash(poczatek,koniec,n))
        {
            cout<<"TAK"<<endl;
        }
        else
        {
            cout<<"NIE"<<endl;
        }
    }
    return 0;
}
 