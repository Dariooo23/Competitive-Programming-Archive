//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int n,wynik=0;
string slowo1,slowo2;
const long long int mod=1e9+696969;
const long long int pierwsza1=3;

vector<long long int> hashpref;
vector<long long int> hashsuf;

vector<long long int> potegi1;

long long int czy_dziala(long long int poczatek,long long int dlugosc)
{
    if(poczatek-dlugosc+1<=0 || poczatek+dlugosc>n)
    {
        return 0;
    }
    else
    {
        return ((((hashpref[poczatek]-hashpref[poczatek-dlugosc]+mod)%mod)*potegi1[n-poczatek-dlugosc])%mod)
               ==((((hashsuf[poczatek+1]-hashsuf[poczatek+dlugosc+1]+mod)%mod)*potegi1[poczatek-dlugosc])%mod);
    }
}
long long int beansearch (long long int os_symetrii)
{
    long long int l=0,r=n,mid;
    while(l<r)
    {
        mid=(l+r+1)/2;

        if(czy_dziala(os_symetrii,mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    return l;
}

void stworz_pref(string s)
{
    hashpref[0]=0;
    for(int i=1;i<=n;i++)
    {
        hashpref[i]=(hashpref[i-1]+((s[i-1]-'a'+1)*potegi1[i])%mod)%mod;
    }
}

void stworz_suf(string s)
{
    hashsuf[n+1]=0;
    for(int i=n;i>=1;i--)
    {
        hashsuf[i]=(hashsuf[i+1]+(('a'-s[i-1]+2)*potegi1[n-i+1])%mod)%mod;
    }
}

void potegowanie()
{
    potegi1[0]=1;
    for(int i=1;i<=n;i++)
    {
        potegi1[i]=(potegi1[i-1]*pierwsza1)%mod;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n;
    cin>>slowo1;

    hashpref.resize(n+9);
    hashsuf.resize(n+9);
    potegi1.resize(n+9);

    potegowanie();

    stworz_pref(slowo1);
    stworz_suf(slowo1);

    for(int i=1;i<=n;i++)
    {
        wynik=wynik+beansearch(i);
    }

    cout<<wynik;
    return 0;
}
 