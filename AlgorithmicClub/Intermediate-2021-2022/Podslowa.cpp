//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<long long int> hash1;
vector<long long int> hash2;
vector<long long int> potegi1;
vector<long long int> potegi2;
const int modulo=1e9+696969;
const int podstawa1=29,podstawa2=7;

void potegi(int n)
{
    potegi1[0]=1;
    potegi2[0]=1;
    potegi1[1]=podstawa1;
    potegi2[1]=podstawa2;

    for(int i=1;i<=n;i++)
    {
        potegi1[i]=(potegi1[i-1]*podstawa1)%modulo;
        potegi2[i]=(potegi2[i-1]*podstawa2)%modulo;
    }
}

void hashowanie(string slowo)
{
    hash1[0]=0;
    hash2[0]=0;

    for(int i=1;i<=slowo.size();i++)
    {
        hash1[i]=(hash1[i-1]+((slowo[i-1]-'a'+1)*potegi1[i])%modulo)%modulo;
        hash2[i]=(hash2[i-1]+((slowo[i-1]-'a'+1)*potegi2[i])%modulo)%modulo;
    }
}

long long int subhash1(int poczatek,int koniec,int rozmiar)
{
    return (((hash1[koniec]-hash1[poczatek-1]+modulo))%modulo*potegi1[rozmiar-koniec])%modulo;
}
long long int subhash2(int poczatek,int koniec,int rozmiar)
{
    return (((hash2[koniec]-hash2[poczatek-1]+modulo))%modulo*potegi2[rozmiar-koniec])%modulo;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,q;
    string slowo;
    cin>>n>>slowo;

    hash1.resize(n+1);
    hash2.resize(n+1);
    potegi1.resize(n+1);
    potegi2.resize(n+1);

    potegi(n);
    hashowanie(slowo);

    cin>>q;
    while(q--)
    {
        int p1,k1,p2,k2;
        cin>>p1>>k1>>p2>>k2;

        if((subhash1(p1,k1,n)==subhash1(p2,k2,n)) && (subhash2(p1,k1,n)==subhash2(p2,k2,n)))
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
 