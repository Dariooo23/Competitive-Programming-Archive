//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long double odleglosc_trojkat=1e9+9;
vector<pair<int,int>> punkty;
int n,a,b;
void najkrotszy1()
{
    sort(punkty.begin(),punkty.end());
    set<pair<int,int>> s;

    int j=0;
    for (int i=0;i<n;++i)
    {
        long long int d=odleglosc_trojkat;
        while(abs(punkty[i].first-punkty[j].first)>=d)
        {
            s.erase({punkty[j].second,punkty[j].first});
            j++;
        }

        auto it1=s.lower_bound({max((long long int)-10,punkty[i].second-d),punkty[i].first});
        auto it2=s.upper_bound({min(punkty[i].second+d,(long long int)1e9+9),punkty[i].first});

        long long int odleglosc_zapasowa=1e18+9;
        pair<int,int> punkt_zapasowy;
        for(auto iterator1=it1;iterator1!=it2;++iterator1){
            long long int x1=punkty[i].first,x2=iterator1->second;
            long long int y1=punkty[i].second,y2=iterator1->first;

            if(odleglosc_zapasowa>(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)){
                odleglosc_zapasowa=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                punkt_zapasowy.first=x2;
                punkt_zapasowy.second=y2;
            }
        }

        for(auto iterator2=it1;iterator2!=it2;++iterator2){
            if(punkt_zapasowy.first==iterator2->second && punkt_zapasowy.second==iterator2->first)continue;

            long long int x1=punkty[i].first,x2=punkt_zapasowy.first,x3=iterator2->second;
            long long int y1=punkty[i].second,y2=punkt_zapasowy.second,y3=iterator2->first;

            odleglosc_trojkat=min(odleglosc_trojkat,sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
            +sqrtl((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3))+sqrtl((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)));
        }

        s.insert({punkty[i].second,punkty[i].first}); 
    }

    cout<<fixed<<setprecision(2)<<odleglosc_trojkat;
    return;
}

void najkrotszy2()
{
    sort(punkty.begin(),punkty.end());
    set<pair<int,int>> s;

    int j=n-1;
    for (int i=n-1;i>=0;--i)
    {
        long long int d=odleglosc_trojkat;
        while(abs(punkty[i].first-punkty[j].first)>=d)
        {
            s.erase({punkty[j].second,punkty[j].first});
            j--;
        }

        auto it1=s.lower_bound({max((long long int)-10,punkty[i].second-d),punkty[i].first});
        auto it2=s.upper_bound({min(punkty[i].second+d,(long long int)1e9+9),punkty[i].first});

        long long int odleglosc_zapasowa=1e18+9;
        pair<int,int> punkt_zapasowy;
        for(auto iterator1=it1;iterator1!=it2;++iterator1){
            long long int x1=punkty[i].first,x2=iterator1->second;
            long long int y1=punkty[i].second,y2=iterator1->first;

            if(odleglosc_zapasowa>(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)){
                odleglosc_zapasowa=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                punkt_zapasowy.first=x2;
                punkt_zapasowy.second=y2;
            }
        }

        for(auto iterator2=it1;iterator2!=it2;++iterator2){
            if(punkt_zapasowy.first==iterator2->second && punkt_zapasowy.second==iterator2->first)continue;

            long long int x1=punkty[i].first,x2=punkt_zapasowy.first,x3=iterator2->second;
            long long int y1=punkty[i].second,y2=punkt_zapasowy.second,y3=iterator2->first;

            odleglosc_trojkat=min(odleglosc_trojkat,sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
            +sqrtl((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3))+sqrtl((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)));
        }

        s.insert({punkty[i].second,punkty[i].first}); 
    }

    cout<<fixed<<setprecision(2)<<odleglosc_trojkat;
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        punkty.push_back({a,b});
    }

    if(n<10000){
        najkrotszy1();
    }else{
        najkrotszy2();
    }
    return 0;
}