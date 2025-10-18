#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;

int main()
{
    LL a,b,wynik=0;
    cin>>a>>b;
    LL tab1[b+1],tab2[b+1];
    for(int i=0;i<=b;i++)
    {
        tab1[i]=0;
        tab2[i]=0;
    }
    for(int i=0;i<a;i++)
    {
        LL c;
        cin>>c;
        pair<LL,LL> zadanie;
        for(int j=0;j<c;j++)
        {
            cin>>zadanie.first>>zadanie.second;
            for(int k=b;k>=1;k--)
            {
                if(k-zadanie.second>=0)
                {
                    tab2[k]=max(tab2[k],tab1[k-zadanie.second]+zadanie.first);
                }
                if(tab2[k]>wynik)
                {
                    wynik=tab2[k];
                }
            }
        }
        for(int k=0;k<=b;k++)
        {
            tab1[k]=tab2[k];
        }
    }
    cout<<wynik;

    return 0;
}