//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int a,b,wynik=0;
    cin>>a>>b;
    while(a<=b)
    {
        a=a*3;
        b=b*2;
        wynik++;
    }

    cout<<wynik;

    return 0;
}
 