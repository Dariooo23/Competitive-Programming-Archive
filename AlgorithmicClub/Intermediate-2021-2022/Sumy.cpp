//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> sumy;
vector<char> wynik;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,suma=0;
    cin>>n;

    wynik.resize(n+1);

    for(int i=1;i<=n;i++)
    {
        int sum;
        cin>>sum;
        sumy.push_back({sum,i});
        suma=suma+sum;
    }

    sort(sumy.begin(),sumy.end(),greater<pair<int,int>>());

    long long int min_waga=sumy[0].first;
    for(int i=0;i<sumy.size();i++)
    {
        if(suma>min_waga && sumy[i].first>sumy.back().first)
        {
            min_waga=sumy[i].first;
            wynik[sumy[i].second]='T';
        }
        else
        {
            wynik[sumy[i].second]='N';
        }

        suma=suma-sumy[i].first;
    }

    for(int i=1;i<=n;i++)
    {
        cout<<wynik[i];
    }

    return 0;
}
 