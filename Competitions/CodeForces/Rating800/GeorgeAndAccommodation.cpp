//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,wynik=0;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(b-a>=2)
        {
            wynik++;
        }
    }
    cout<<wynik;

    return 0;
}
 