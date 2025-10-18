//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

long long int poczty;
vector<long long int> sumpref;
vector<long long int> koszty;

long long int lewo(int miasto,int lewo)
{
    if(miasto>lewo)
    {
        return sumpref[miasto]-sumpref[lewo-1];
    }
    else
    {
        return sumpref[poczty]-sumpref[lewo-1]+sumpref[miasto];
    }
}

long long int prawo(int miasto,int prawo)
{
    if(prawo>miasto)
    {
        return sumpref[prawo]-sumpref[miasto-1];
    }
    else
    {
        return sumpref[poczty]-sumpref[miasto-1]+sumpref[prawo];
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>poczty;

    sumpref.resize(poczty+1);
    koszty.resize(poczty+1);

    for(int i=1;i<=poczty;i++)
    {
        cin>>koszty[i];
    }

    sumpref[0]=0;
    for(int i=1;i<=poczty;i++)
    {
        sumpref[i]=sumpref[i-1]+koszty[i];
    }

    for(int i=1;i<=poczty;i++)
    {
        long long int a,b,kosztlewo=0,kosztprawo=0;
        cin>>a>>b;

        

        if(lewo(i,a)<=prawo(i,b))
        {
            cout<<"L ";
        }
        else
        {
            cout<<"R ";
        }
        
    }
    return 0;
}
 