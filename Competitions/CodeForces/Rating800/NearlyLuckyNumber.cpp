//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,szczesliwe=0;
    cin>>n;

    while(n>0)
    {
        if(n%10==4 || n%10==7)
        {
            szczesliwe++;
        }
        n=n/10;
    }

    if(szczesliwe==4 || szczesliwe==7)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }

    return 0;
}
 