//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> punkty;
int n,a,b;
void najkrotszy()
{
    sort(punkty.begin(),punkty.end());
    set<pair<int,int>> s;

    int odleglosc=2e9;
    int j=0;
    for (int i=0;i<n;++i)
    {
        int d=ceil(sqrt(odleglosc));
        while(punkty[i].first-punkty[j].first>=d)
        {
            s.erase({punkty[j].second,punkty[j].first});
            j=j+1;
        }

        auto it1=s.lower_bound({punkty[i].second-d,punkty[i].first});
        auto it2=s.upper_bound({punkty[i].second+d,punkty[i].first});
        
        for (auto it=it1;it!=it2;++it) {
            int x=punkty[i].first-it->second;
            int y=punkty[i].second-it->first;
            odleglosc=min(odleglosc,x*x+y*y);     
        } 
        s.insert({punkty[i].second,punkty[i].first}); 
    }
    cout<<fixed<<setprecision(5)<<sqrt(odleglosc);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        punkty.push_back({a,b});
    }
    najkrotszy();
    return 0;
}