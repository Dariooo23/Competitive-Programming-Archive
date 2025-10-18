//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

void korona(int n)
{
    if(n==0)
    {
        return;
    }

    korona(n/2);
    for(int i=1;i<=n;i++)
    {
        cout<<":";
    }
    cout<<endl;
    korona(n/2);
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    korona(n);
    return 0;
}
 