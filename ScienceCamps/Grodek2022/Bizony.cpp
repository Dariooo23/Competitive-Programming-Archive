//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct pozycja{
    int x,y,czas;
};

vector<pozycja> zamiatanie;
vector<int> wynik;

bool cmp(const pozycja &a,const pozycja &b)
{
    if(a.x==b.x)
    {
        return a.czas<b.czas;
    }
    else
    {
        return a.x<b.x;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int ilosc_bizony,ilosc_osadnicy;
    cin>>ilosc_bizony;
    for(int i=1;i<=ilosc_bizony;i++)
    {
        int x,y;
        cin>>x>>y;
        zamiatanie.push_back({x,y,-1});
    }
    cin>>ilosc_osadnicy;
    wynik.resize(ilosc_osadnicy+1);
    for(int i=1;i<=ilosc_osadnicy;i++)
    {
        int x,y;
        cin>>x>>y;
        zamiatanie.push_back({x,y,i});
    }

    sort(zamiatanie.begin(),zamiatanie.end(),cmp);
    set<pair<int,int>>::iterator it;
    set<pair<int,int>> ploty;
    for(int i=zamiatanie.size()-1;i>=0;i--)
    {
        if(zamiatanie[i].czas==-1)
        {
            it=ploty.lower_bound({zamiatanie[i].y,0});
            if(it==ploty.end())continue;
            wynik[it->second]++;
        }
        else
        {
            if(!ploty.size())ploty.insert({zamiatanie[i].y,zamiatanie[i].czas});
            else
            {
                it=ploty.lower_bound({zamiatanie[i].y,0});
                while(it!=ploty.begin())
                {
                    --it;
                    if((it->second)<zamiatanie[i].czas)break;
                    ploty.erase(it);
                    it=ploty.lower_bound({zamiatanie[i].y,0});
                }
                ploty.insert({zamiatanie[i].y,zamiatanie[i].czas});
            }
        }
    }

    for(int i=1;i<=ilosc_osadnicy;i++)
    {
        cout<<wynik[i]<<endl;
    }
    
    return 0;
}
 