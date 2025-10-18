//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,wynik=1;
    string magnet1,magnet2;
    cin>>n>>magnet2;

    for(int i=1;i<n;i++)
    {
        cin>>magnet1;

        if(magnet1[0]!=magnet2[0])
        {
            wynik++;
        }

        magnet2=magnet1;
    }

    cout<<wynik;
    
    return 0;
}
 