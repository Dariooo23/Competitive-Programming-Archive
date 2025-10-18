#include <bits/stdc++.h>

using namespace std;
int dziala(int ilogwo,vector<pair<int,int>>& deski,vector<int>& gwozdzie)
{
    vector<int> zlicz(1000009);
    for(int i=0;i<ilogwo;i++)
    {
        zlicz[gwozdzie[i]]++;
    }
    for(int i=1;i<=zlicz.size();i++)
    {
        zlicz[i]+=zlicz[i-1];
    }
   /* for(int i=0;i<zlicz.size();i++)
    {
        cout<<zlicz[i]<<" ";
    }
    cout<<endl;*/
    for(int i=0;i<deski.size();i++)
    {
            if((zlicz[deski[i].second]-zlicz[deski[i].first-1])==0)
        {
            //cout<<ilogwo<<endl;
            return 0;
        }


    }
    /*for(int i=0;i<zlicz.size();i++)
    {
        cout<<zlicz[i]<<" ";
    }
    cout<<endl;*/

    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> deski(n);
    vector<int> gwozdzie(m);

    for(int i=0;i<n;i++)
    {
        cin>>deski[i].first>>deski[i].second;
    }
    for(int i=0;i<m;i++)
    {
        cin>>gwozdzie[i];
    }
    //dziala(m-2,deski,gwozdzie);

    int lewo=0,prawo=m-1,wynik=0;
    while(lewo<=prawo)
    {
        int mid=(lewo+prawo)/2;
        if(dziala(mid,deski,gwozdzie)==1)
        {
            wynik=mid;
            prawo=mid-1;
        }
        else
        {
            lewo=mid+1;
        }
    }

    cout<<wynik;
    return 0;
}