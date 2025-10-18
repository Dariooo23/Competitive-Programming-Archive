//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> zera;
vector<int> jedynki;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,q;
    string slowo;

    cin>>n>>q>>slowo;
    
    jedynki.resize(n+1);
    zera.resize(n+1);
    jedynki[0]=0;
    zera[0]=0;

    for(int i=1;i<=n;i++)
    {
        if(slowo[i-1]=='0')
        {
            zera[i]++;
        }
        else
        {
            jedynki[i]++;
        }

        zera[i]=zera[i]+zera[i-1];
        jedynki[i]=jedynki[i]+jedynki[i-1];
    }

    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if((zera[b]-zera[a-1])%2==0 && (jedynki[b]-jedynki[a-1])%2==0)
        {
            cout<<"Niewykluczone"<<endl;
        }
        else
        {
            cout<<"Zdecydowanie nie"<<endl;
        }
    }

    return 0;
}
 