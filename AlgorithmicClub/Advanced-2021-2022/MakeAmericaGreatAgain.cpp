//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graf;
vector<bool> visited;

int dfs(int s, int p)
{
    int dzieci=0,luki=0;
    visited[s]=1;

    for(int &v:graf[s])
    {
        if (visited[v]==0)
        {
            dzieci++;
            luki=luki+dfs(v,p);
        }
    }

    return max(0,dzieci+luki-p);
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    graf.resize(n+9);
    visited.resize(n+9);
    for (int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }


    int l=0,r=n,mid;
    while (l<r) {
        mid=(l+r)/2;
        for(int i=0;i<n+9;i++)
        {
            visited[i]=0;
        }

        if(dfs(1,mid)==0)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<l;

    return 0;
}