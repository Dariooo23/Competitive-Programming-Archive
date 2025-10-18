//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> friends;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    friends.resize(n+1);

    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        friends[a]=i;
    }

    for(int i=1;i<=n;i++)
    {
        cout<<friends[i]<<" ";
    }
    return 0;
}
 