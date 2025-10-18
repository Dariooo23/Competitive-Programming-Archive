//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<pair<long long int,long long int>> pracownicy;
vector<int> prace;

bool cmp(const pair<long long int,long long int> &a, const pair<long long int,long long int> &b)
{
    return a.second<b.second;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int k,n;
    cin>>k>>n;

    pracownicy.resize(k);
    prace.resize(n);

    for(int i=0;i<k;i++)
    {
        cin>>pracownicy[i].first;
        prace[pracownicy[i].first-1]++;
        if(prace[pracownicy[i].first-1]==1)
        {
            n--;
        }
    }
    for(int i=0;i<k;i++)
    {
        cin>>pracownicy[i].second;
    }

    sort(pracownicy.begin(),pracownicy.end(),cmp);

    long long int wynik=0;
    for(int i=0;i<k;i++)
    {
        if(prace[pracownicy[i].first-1]>1 && n>0)
        {
            wynik=wynik+pracownicy[i].second;
            prace[pracownicy[i].first-1]--;
            n--;
        }
    }
    cout<<wynik;

    return 0;
}
 