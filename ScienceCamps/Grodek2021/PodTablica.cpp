#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int testy;
    cin>>testy;
    for(int i=0;i<testy;i++)
    {
            long long int ilosc,modulo,wynik=0,suma=0;
            set<long long int> liczby;
            cin>>ilosc>>modulo;
        for(int i=0;i<ilosc;i++)
        {
            long long int a;
            cin>>a;
            suma=(suma+a)%modulo;
            auto it=liczby.upper_bound(suma);
            if(it==liczby.end())
            {
                wynik=max(wynik,suma);
            }
            else
            {
                wynik=max(wynik,modulo-(*it-suma));
            }
              liczby.insert(suma);
        }
        cout<<wynik<<endl;
    
    }
    return 0;
}