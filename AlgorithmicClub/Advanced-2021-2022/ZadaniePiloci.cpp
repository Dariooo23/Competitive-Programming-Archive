//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

deque<pair<int,int>> kolejkamaks,kolejkamin;
vector<int> t;
void push(int a)
{
    while (!kolejkamaks.empty() && kolejkamaks.back().first <= t[a])
        kolejkamaks.pop_back();
    kolejkamaks.push_back(make_pair(t[a], a));
    while (!kolejkamin.empty() && kolejkamin.back().first >= t[a])
        kolejkamin.pop_back();
    kolejkamin.push_back(make_pair(t[a], a));
}

void pop(int a)
{
    if (kolejkamaks.front().second == a)
        kolejkamaks.pop_front();
    if (kolejkamin.front().second == a)
        kolejkamin.pop_front();
}

int get()
{
    return kolejkamaks.front().first-kolejkamin.front().first;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    t.resize(m);
    for(int i=0;i<m;i++)
    {
        cin>>t[i];
    }
    int j=0,maks=0;
    for(int i=0;i<m;i++)
    {
        push(i);
        if(get()>n)
        {
            while(get()>n)
            {
                pop(j);
                j++;
            }
        }
        maks=max(maks,i-j+1);
    }
    cout<<maks;

    return 0;
}