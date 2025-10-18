//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<bool> visited(101);
vector<int> odleglosc(101);
vector<int> weze_i_drabiny(101,0);

void bfs(int start)
{
    queue<int> kolejka;
    kolejka.push(start);
    visited[start]=1;
    odleglosc[start]=0;
    
    while(!kolejka.empty())
    {
        int s=kolejka.front();
        kolejka.pop();

        if(weze_i_drabiny[s]>0)
        {
            if(!visited[weze_i_drabiny[s]])
            {
                visited[weze_i_drabiny[s]]=1;
                odleglosc[weze_i_drabiny[s]]=odleglosc[s];
                kolejka.push(weze_i_drabiny[s]);
            }
        }
        else
        {
            for(int i=s+1;i<=min(s+6,100);i++)
            {
                if(!visited[i])
                {
                    visited[i]=1;
                    odleglosc[i]=odleglosc[s]+1;
                    kolejka.push(i);
                }
            }
        }
    }

}

void solve()
{
    for(int i=0;i<=100;i++)
    {
        visited[i]=0;
        odleglosc[i]=-1;
        weze_i_drabiny[i]=0;
    }

    int drabiny,weze;
    cin>>drabiny;
    for(int i=1;i<=drabiny;i++)
    {
        int a,b;
        cin>>a>>b;
        weze_i_drabiny[a]=b;
    }
    cin>>weze;
    for(int i=1;i<=weze;i++)
    {
        int a,b;
        cin>>a>>b;
        weze_i_drabiny[a]=b;
    }

    bfs(1);
    cout<<odleglosc[100]<<endl;

}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int q;
    cin>>q;
    while(q--)
    {
        solve();
    }
    return 0;
}
 