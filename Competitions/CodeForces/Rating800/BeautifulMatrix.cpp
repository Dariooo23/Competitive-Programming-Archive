//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>n;
            if(n)
            {
                cout<<abs(i-3)+abs(j-3);
            }
        }
    }
    return 0;
}
 