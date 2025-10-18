#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
vector<int> stopien;
vector<int> radary;
vector<vector<int>> kolejka;
vector<bool> bylo;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int n,k,wynik=0;
    cin>>n>>k;
    g.resize(1000009);
    stopien.resize(1000009);
    kolejka.resize(1000009);
    bylo.resize(1000009);

    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        stopien[i]=g[i].size();
        if(stopien[i]==1)
        {
            kolejka[1].push_back(i);
        }
    }
    
    
    for(int i=1;i<=k/2;i++)
    {
            for(int j=0;j<kolejka[i].size();j++)
            {
            if(bylo[kolejka[i][j]]==0)
            {
               bylo[kolejka[i][j]]=1;
               radary.push_back(kolejka[i][j]);
               wynik++;
               for(int k=0;k<g[kolejka[i][j]].size();k++)
               {
                  stopien[g[kolejka[i][j]][k]]--;
                  if(stopien[g[kolejka[i][j]][k]]==1)
                  {
                      kolejka[i+1].push_back(g[kolejka[i][j]][k]);
                  }
               }
            }
        }
    }
    if(k%2==1 && wynik<n)
    {
        wynik++;
    }
    cout<<wynik<<endl;
    for(int i=0;i<radary.size();i++)
    {
        cout<<radary[i]<<" ";
    }
    if(k%2==1 && wynik<=n)
    {
        for(int i=1;i<=n;i++)
        {
            if(bylo[i]==0)
            {
                cout<<i<<" ";
                break;
            }
        }
    }

    return 0;
}