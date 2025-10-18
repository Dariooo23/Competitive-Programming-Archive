//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<long long int> prefiksy;
vector<long long int> tab2;

bool czy_dziala(int promien,int srodek)
{
    if(srodek-promien-1<0)
    {
        return 0;
    }

    if(prefiksy[srodek+promien]-prefiksy[srodek-promien-1]<=tab2[srodek])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    prefiksy.resize(n+1);
    tab2.resize(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>prefiksy[i];
    }
    for(int i=1;i<=n;i++)
    {
        prefiksy[i]=prefiksy[i]+prefiksy[i-1];
    }

    for(int i=1;i<=n;i++)
    {
        cin>>tab2[i];
    }

    for(int i=1;i<=n;i++)
    {
        int l=1,r=min(n-i,i-1),mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(czy_dziala(mid,i))
            {
                l=mid+1;
            }
            else
            {
               r=mid-1;
            }
        }

        cout<<l-1<<endl;
    }
    return 0;
}
 