//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int k,n,w,koszt=0;
    cin>>k>>n>>w;

    for(int i=1;i<=w;i++)
    {
        koszt=koszt+i*k;
    }

    if(koszt<=n)
    {
        cout<<0;
    }
    else
    {
        cout<<koszt-n;
    }
    return 0;
}
 