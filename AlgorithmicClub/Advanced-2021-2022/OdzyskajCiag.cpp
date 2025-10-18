#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int testy;
    cin>>testy;
    for(int k=0;k<testy;k++)
    {
        int n,m,a,b,flaga=1,flaga2=0,licznik=0;
        cin>>n>>m;
        vector<vector<int>> g(n+1);
        vector<int> wejscia(n+1);
        queue<int> kolejka;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            g[a].push_back(b);
            wejscia[b]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(wejscia[i]==0)
            {
                licznik++;
                flaga2=1;
                kolejka.push(i);
            }
        }
        while(!kolejka.empty())
        {
            if(kolejka.size()>1)
            {
                flaga=0;
                break;
            }
            else
            {
                int c=kolejka.front();
                kolejka.pop();
                for(int v:g[c])
                {
                    wejscia[v]--;
                    if(wejscia[v]==0)
                    {
                        licznik++;
                        kolejka.push(v);
                    }
                }
            }
        }
        if(flaga==1 && flaga2==1 && licznik==n)
        {
            cout<<"TAK"<<endl;
        }
        else
        {
            cout<<"NIE"<<endl;
        }
    }
    return 0;
}