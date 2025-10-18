//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int ilosc;
    cin>>ilosc;

    while(ilosc--)
    {
        string slowo;
        cin>>slowo;
        if(slowo.size()<=10)
        {
            cout<<slowo<<'\n';
        }
        else
        {
            cout<<slowo[0]<<slowo.size()-2<<slowo[slowo.size()-1]<<'\n';
        }
    }

    return 0;
}
 