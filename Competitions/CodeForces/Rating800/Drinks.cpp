//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;
    long double napoj,wynik=0;

    for(int i=1;i<=n;i++)
    {
        cin>>napoj;
        wynik=wynik+napoj;
    }

    cout<<fixed<<setprecision(6)<<wynik/n;

    return 0;
}
 