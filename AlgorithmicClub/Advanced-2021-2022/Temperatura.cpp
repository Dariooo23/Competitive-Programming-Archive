//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

deque<pair<int,int>> kolejkamaks;
vector<pair<int,int>> t0;
void push(int a)
{
    while (!kolejkamaks.empty() && kolejkamaks.back().first<=t0[a].first)
    {
        kolejkamaks.pop_back();
    }
    kolejkamaks.push_back({t0[a].first, a});
}

void pop(int a)
{
    if (kolejkamaks.front().second==a)
    {
        kolejkamaks.pop_front();
    }
}

int get()
{   
    if(kolejkamaks.empty())
    {
        return -1e9-9;
    }
    else
    {
        return kolejkamaks.front().first;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;
    t0.resize(n);

    for(int i=0;i<n;i++)
    {
        cin>>t0[i].first>>t0[i].second;
    }

    int j=0,maks=0;
    for(int i=0;i<n;i++)
    {
        while(j<n && get()<=t0[j].second)
        {
            push(j);
            j++;
        }
        maks=max(maks,j-i);
        pop(i);
    }
    cout<<maks;

    return 0;
}