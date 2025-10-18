//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int test;
    cin>>test;

    while(test--)
    {
        int ilosc,wynik=0;
        cin>>ilosc;

        while(ilosc%2==0)
        {
            ilosc=ilosc/2;
            wynik++;
        }
        if(wynik%2)
        {
            cout<<"TAK"<<'\n';
        }
        else
        {
            cout<<"NIE"<<'\n';
        }
    }
    
    return 0;
}
 