//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;
vector<int> monety;


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    monety.resize(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>monety[i];
    }
    for(int i=0;i<q;i++)
    {
        int a,wynik=1e9+696969,licz=0,reszta;
        cin>>a;
        for(int j=0;j<(1<<n);j++)
        {
            licz=0;
            reszta=a;
            for(int k=0;k<n;k++)
            {
                if((j&(1<<k))!=0)
                {
                    reszta=reszta-monety[k];
                    licz++;
                }
            }
            if(reszta==0)
            {
                wynik=min(wynik,licz);
            }
        }
        if(wynik==1e9+696969)
        {
            cout<<"NIE"<<endl;
        }
        else
        {
            cout<<wynik<<endl;
        }
    }
    return 0;
}