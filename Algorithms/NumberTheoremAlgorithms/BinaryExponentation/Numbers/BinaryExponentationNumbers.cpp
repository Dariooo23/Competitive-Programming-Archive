//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int modulo=1e9+7;

long long int potega(long long int a,long long int b)
{
    if(b==0)
    {
        return 1;
    }
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

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    long long int a,b;
    cin>>a>>b;
    cout<<a<<" PODNIESIONE DO POTEGI "<<b<<" I ZMODULOWANE PRZEZ 1E9+7 TO: "<<potega(a,b);
    return 0;
}
 