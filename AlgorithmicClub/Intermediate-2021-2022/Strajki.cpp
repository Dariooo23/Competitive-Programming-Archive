//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graf(600000);
vector<bool> zablokowane(600000);
vector<int> rozmiar(600000);
vector<int> rodzice(600000);

void dfs(int punkt,int parent)
{
   rodzice[punkt]=parent;
   for(int v : graf[punkt])
   {
       if(v!=parent)
       {
           dfs(v,punkt);
           rozmiar[punkt]++;
       }
   }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int miasta;
    cin>>miasta;

    for(int i=0;i<miasta-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1,0);
    zablokowane[0]=1;


    int strajki,wynik=1;
    cin>>strajki;



    for(int i=0;i<strajki;i++)
    {
        int a;
        cin>>a;
        if(a>0)
        {
            wynik=wynik+rozmiar[a];
            zablokowane[a]=1;
            rozmiar[rodzice[a]]--;
            if(zablokowane[rodzice[a]]==1)
            {
                wynik--;
            }
        }
        else
        {
            a=a*-1;
            wynik=wynik-rozmiar[a];
            zablokowane[a]=0;
            rozmiar[rodzice[a]]++;
            if(zablokowane[rodzice[a]]==1)
            {
                wynik++;
            }
        }
        cout<<wynik<<endl;;
    }
    return 0;
}

