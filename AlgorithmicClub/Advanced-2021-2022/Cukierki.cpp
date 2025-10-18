#include <bits/stdc++.h>

using namespace std;

const int modulo=1e9+7;

vector<long long int> tab(10000);
vector<long long int> tab2(10000);

int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int n,wynik=0,sum1=0,sum2=0;
    cin>>n;
    long long int tab3[n];
    tab[0]=1;
    tab2[0]=1;
    for(int i=0;i<n;i++)
    {
        cin>>tab3[i];
    }
    sort(tab3,tab3+n);

    for(int i=0;i<n;i++)
    {
        sum1=0;
        for(int j=0;j<5000;j++)
        {
            if(tab3[i]<=j+1)
            {
                if(j+tab3[i]>4999)
                {
                    sum1=(sum1+tab[j])%modulo;
                }
                else
                {
                    tab2[j+tab3[i]]=(tab2[j+tab3[i]]+tab[j])%modulo;
                }
            }
        }
        tab=tab2;
        sum2=(sum2*2+sum1)%modulo;
    }
    for(int i=1;i<10000;i++)
    {
        wynik=(wynik+tab[i])%modulo;
    }
    wynik=(wynik+sum2)%modulo;
    cout<<wynik;
    return 0;
}