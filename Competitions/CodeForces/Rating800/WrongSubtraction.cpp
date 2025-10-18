//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    while(k--)
    {
        if(n%10==0)
        {
            n=n/10;
        }
        else
        {
            n--;
        }
    }
    cout<<n;
    
    return 0;
}
 