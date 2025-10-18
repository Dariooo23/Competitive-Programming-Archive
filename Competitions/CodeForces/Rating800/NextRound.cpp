//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m,punkty1=0,punkty2,wynik=0;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>punkty1;
        if(punkty1>0 && (punkty1==punkty2 || m>=i))
        {
            wynik++;
            punkty2=punkty1;
        }
    }

    cout<<wynik;

    return 0;
}
 