#include <bits/stdc++.h>
using namespace std;
pair<long long int,long long int> prefiksy[1000009];

int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int a,k,wynik=0,liczba;
    cin>>a>>k;
    prefiksy[0].first=0;
    prefiksy[0].second=0;
    for(int i=1;i<=a;i++)
    {
        cin>>liczba;
        prefiksy[i].first=prefiksy[i-1].first+liczba;
        prefiksy[i].second=i;
    }
    sort(prefiksy,prefiksy+a+1);
 /* for(int i=0;i<=a;i++)
    {
        cout<<prefiksy[i].first<<" ";
    }
    cout<<endl;*/
    int j=0;
    if(k>=0)
    {
       for(int i=1;i<=a;++i)
    {
        if(j<i)
        {
        j=i;
        }
        while(j+1<=a && prefiksy[j].first-prefiksy[i].first<=k)
        {

                if(prefiksy[j].first-prefiksy[i].first==k)
        {
            wynik=max(wynik,prefiksy[j].second-prefiksy[i].second);
            //cout<<prefiksy[i].second<<" "<<prefiksy[j].second<<endl;
        }


        j++;
        }

    }
    }
    else
    {
    for(int i=a;i>0;i--)
    {
        if(j<i)
        {
            j=i;
        }
        while(j+1>0 &&prefiksy[i].first-prefiksy[j].first<=k)
        {
            if(prefiksy[i].first-prefiksy[j].first==k)
        {
            wynik=max(wynik,prefiksy[i].second-prefiksy[j].second);
            //cout<<prefiksy[i].second<<" "<<prefiksy[j].second<<endl;
        }
        j--;
        }
    }
    }

if(wynik<=0)
{
    cout<<"BRAK";
}
else
{
   cout<<wynik<<endl;
}

    return 0;
}