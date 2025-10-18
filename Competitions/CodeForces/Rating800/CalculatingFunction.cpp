//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n;
    cin>>n;

    if(n%2)
    {
        cout<<-1*(((n-1)/2)+1);
    }
    else
    {
        cout<<n/2;
    }

    return 0;
}
 