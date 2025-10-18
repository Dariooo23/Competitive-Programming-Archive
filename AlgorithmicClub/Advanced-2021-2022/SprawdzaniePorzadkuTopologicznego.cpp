#include <bits/stdc++.h>

using namespace std;
int const N=1e6+9;
vector<vector<int>> g(N);
vector<int> pozycja;
vector<int> wejscie;
int main()
{
    std::ios_base::sync_with_stdio(0);
    int n,m,a,b;
    cin>>n>>m;
    pozycja.resize(n);
    wejscie.resize(n);
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        g[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        cin>>wejscie[i];
        pozycja[wejscie[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        for(int v:g[wejscie[i]])
        {
            if(pozycja[v]>i)
            {
                cout<<wejscie[i];
                exit(0);
            }
        }
    }
    cout<<"OK";
    return 0;
}