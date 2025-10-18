#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<pair<pair<int,int>,int>> praw(n);
    for(int i=0;i<n;i++)
    {
        cin>>praw[i].first.first>>praw[i].first.second;
        praw[i].second=i;
    }
    sort(praw.begin(),praw.end());

    priority_queue <int, vector<int>, greater<int>> q;
    int res=0,resid;
    for(int i=0;i<n;i++)
    {
        q.push(praw[i].first.second);
        if(q.size()>k)
        {
            q.pop();
        }
        while(!q.empty() && q.top() <praw[i].first.first)
        {
            q.pop();
        }
        if(q.size()==k && res<q.top()-praw[i].first.first)
        {
            res=q.top()-praw[i].first.first;
            resid=i;
        }
    }
    vector<int> ids;
    cout<<res<<endl;
    int beg=praw[resid].first.first, koniec=praw[resid].first.first+res;
    for(int i=0;i<n && k>0;i++)
    {
        if(praw[i].first.first<=beg && praw[i].first.second>=koniec)
        {
            ids.push_back(praw[i].second+1);
            k--;
        }
    }
    sort(ids.begin(),ids.end());
    for(int id :ids)
    {
        cout<<id<<" ";
    }
    return 0;
}