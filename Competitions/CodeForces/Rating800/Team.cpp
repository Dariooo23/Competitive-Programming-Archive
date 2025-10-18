//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,p1,p2,p3,wynik=0;
    cin>>n;

    while(n--)
    {
        cin>>p1>>p2>>p3;
        if(p1+p2+p3>=2)
        {
            wynik++;
        }
    }
    cout<<wynik;
    
    return 0;
}
 