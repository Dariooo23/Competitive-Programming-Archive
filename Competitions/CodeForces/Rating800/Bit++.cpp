//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,x=0;
    cin>>n;

    while(n--)
    {
        string slowo;
        cin>>slowo;
        if(slowo[1]=='+')
        {
            x++;
        }
        else
        {
            x--;
        }
    }
    cout<<x;

    return 0;
}
 