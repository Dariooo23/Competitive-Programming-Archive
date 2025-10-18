#include <bits/stdc++.h>
using namespace std;
pair<int,char> tab[26];
int cmp(pair<int,char> a,pair<int,char>b)
{
    if(a.first==b.first)
    {
        return a.second<b.second;
    }
    else
    {
        return a.first>b.first;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);

    for(int i=0;i<26;i++)
    {
        tab[i].second='a'+i;
    }
    char lol;
    while(cin>>lol)
    {
       tab[lol-'a'].first++;
    }
    /*for(int i=0;i<26;i++)
    {
        cout<<tab[i].first<<" "<<tab[i].second<<endl;
    }*/

    sort(tab,tab+26,cmp);
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<tab[i].first;j++)
        {
            cout<<tab[i].second;
        }
    }
    return 0;
}