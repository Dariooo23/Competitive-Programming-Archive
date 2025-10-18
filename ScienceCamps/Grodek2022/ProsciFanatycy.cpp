//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int n,m,s;
long long int wynik=0;
long long int modulo=1e9+7;
vector<long long int> silnie;
vector<long long int> odleglosci;

void silnia()
{
    silnie[0]=1;
    for(long long int i=1;i<=5e5+1;i++)
    {
        silnie[i]=(silnie[i-1]*i)%modulo;
    }
}
long long int potega(long long int a,long long int b)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        long long int wynik=potega(a,b/2);
        return (wynik*wynik)%modulo;
    }
    else
    {
        return (a*potega(a,b-1))%modulo;
    }
}
void wylicz_srednice()
{
    vector<long long int> prefiksy;
    long long int suma=0;
    prefiksy.resize(n+1);

    prefiksy[0]=0;
    for(long long int i=1;i<=n;i++)
    {
        suma=suma+odleglosci[i];
        prefiksy[i]=prefiksy[i-1]+odleglosci[i];
    }
    if(suma%2==1){
        cout<<potega(m,n);
        exit(0);
    }
    set<long long int> srednice;
    for(long long int i=0;i<=n;i++)
    {
        srednice.insert(prefiksy[i]);
    }
    for(auto it:srednice)
    {
        long long int znajdz=(it+(suma/2))%suma;
        if(srednice.find(znajdz)!=srednice.end())
        {
            s++;
        }
    }
    s=s/2;
}

long long int wzor(long long int k)
{
    if(m-k<0)return 0;
    long long int newton1=(((silnie[s]*potega(silnie[k],modulo-2))%modulo)*potega(silnie[s-k],modulo-2))%modulo;
    long long int newton2=(((silnie[m]*potega(silnie[k],modulo-2))%modulo)*potega(silnie[m-k],modulo-2))%modulo;
    long long int silnia1=silnie[k];
    long long int potega1=potega(m-k,n-2*s)%modulo;
    long long int potega2=potega(m-k,s-k)%modulo;
    long long int potega3=potega(m-k-1,s-k)%modulo;
    return (((((((((newton1*newton2)%modulo)*silnia1)%modulo)*potega1)%modulo)*potega2)%modulo)*potega3)%modulo;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n>>m;

    silnie.resize(6e5+10);
    odleglosci.resize(6e5+10);

    for(long long int i=1;i<=n;i++)
    {
        cin>>odleglosci[i];
    }

    wylicz_srednice();
    silnia();
    for(long long int k=0;k<=s;k++)
    {
        wynik=(wynik+wzor(k))%modulo;
    }

    cout<<wynik;

    return 0;
}