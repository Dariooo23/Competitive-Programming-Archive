//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string slowo;
    cin>>slowo;

    if(slowo[0]>='a')
    {
        slowo[0]=slowo[0]-'a'+'A';
    }

    cout<<slowo;
    
    return 0;
}
 