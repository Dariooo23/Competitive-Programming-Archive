//Karol Dziekan
#include <bits/stdc++.h>
#include "koplib.h"
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    unsigned int ilosc_kopaln=dajN();
    unsigned int obsluga=dajK();

    multiset<long long int> kopalnie;
    multiset<long long int>::iterator it;
    
    pair<long long int,long long int> wspolrzedne=odpowiedz(2137);
    kopalnie.insert((long long int)(wspolrzedne.first*wspolrzedne.first+wspolrzedne.second*wspolrzedne.second));

    for(int i=0;i<ilosc_kopaln;i++)
    {
        wspolrzedne=odpowiedz((long long int)(*kopalnie.rbegin()));
        kopalnie.insert((wspolrzedne.first*wspolrzedne.first+wspolrzedne.second*wspolrzedne.second));

        if(kopalnie.size()>obsluga)
        {
            it=kopalnie.end();
            --it;
            kopalnie.erase(it);
        }
    }
    return 0;
}
 