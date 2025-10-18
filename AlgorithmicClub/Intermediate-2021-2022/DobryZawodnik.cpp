//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,wygrana,wynik1=0,wynik2=0,zawodnik=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>wygrana;
            wynik2=wynik2+wygrana;
        }

        if(wynik2>wynik1)
        {
            wynik1=wynik2;
            zawodnik=i;
        }
        wynik2=0;
    }

    cout<<zawodnik;
    return 0;
}
 