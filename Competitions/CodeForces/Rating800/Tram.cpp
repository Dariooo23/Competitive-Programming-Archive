//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,osoby=0,wynik=0;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        osoby=osoby-a+b;
        wynik=max(wynik,osoby);
    }

    cout<<wynik;

    return 0;
}
 