//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> butelki;
vector<int> visited;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    butelki.resize(n+1);
    visited.resize(n+1,0);
    
    for(int i=1;i<=n;i++)
    {
        cin>>butelki[i];
    }

    long long int odleglosc=0,wynik=0;
    for(int i=1;i<=n && odleglosc<k;i++)
    {
        if(visited[butelki[i]])
        {
            continue;
        }

        wynik=wynik+i-odleglosc-1;
        visited[butelki[i]]=1;
        odleglosc++;
    }

    if(odleglosc==k)
    {
        cout<<wynik;
    }
    else
    {
        cout<<-1;
    }

    return 0;
}
 