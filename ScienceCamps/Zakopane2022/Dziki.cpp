//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> dziki;
set<int,greater<int>> lancuchy;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        dziki.push_back({x,y});
    }

    sort(dziki.begin(),dziki.end());

    lancuchy.insert(dziki[0].second);

    for(int i=1;i<dziki.size();i++)
    {
        auto it=lancuchy.lower_bound(dziki[i].second);

        if(it!=lancuchy.end())
        {
            lancuchy.erase(it);
        }
        lancuchy.insert(dziki[i].second);
    }

    cout<<lancuchy.size();
    return 0;
}
 