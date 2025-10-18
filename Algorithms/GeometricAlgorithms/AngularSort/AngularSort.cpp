//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct wektor
{
    long long int x,y;
};

long long int iloczyn_wektorowy(const wektor &a, const wektor &b)
{
    if (a.x*b.y - b.x*a.y>0)
    {
        return 1;
    }
    if (a.x*b.y - b.x*a.y<0)
    {
        return -1;
    }
    return 0;
}

bool cmp(const wektor &a, const wektor &b)
{
    //Dzielimy wektory wzgledem osi Y na te które są po lewo i te po prawo
    if(a.x<0 && b.x>0)
    {
        return 1;
    }
    if(a.x>0 && b.x<0)
    {
        return 0;
    }
    //

    //Kiedy posortowalismy wektory wzgledem osi Y to sortujemy je za pomoca iloczynu wektorowego
    //Jeżeli iloczyn wektorowy jest równy 0 to wektory są względem siebie rownolegle,
    //sortujemy je wtedy po współrzędnej Y
    if(iloczyn_wektorowy(a,b)==0)
    {
        return a.y<b.y;
    }
    else
    {
        return iloczyn_wektorowy(a,b)<0;
    }
}

vector<wektor> wektory;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    //Wczytujemy wektory do posortowania
    for(int i=0;i<n;i++)
    {
        long long int x,y;
        cin>>x>>y;
        wektory.push_back({x,y});
    }

    //Sortujemy
    sort(wektory.begin(),wektory.end(),cmp);

    for(int i=0;i<n;i++)
    {
        cout<<wektory[i].x<<" "<<wektory[i].y<<endl;
    }
    return 0;
}