//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,h,wynik=0;
    cin>>n>>h;

    for(int i=0;i<n;i++)
    {
        wynik++;
        int a;
        cin>>a;
        if(a>h)
        {
            wynik++;
        }
    }
    cout<<wynik;
    
    return 0;
}
 