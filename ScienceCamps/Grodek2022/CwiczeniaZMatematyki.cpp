//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> ciag;

bool solve()
{
    int n,l,r;
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++)
    {
        int liczba;
        if(l%i==0)
        {
            liczba=l;
        }
        else
        {
            liczba=l+(i-l%i);
        }

        if(liczba<=r)
        {
            ciag.push_back(liczba);
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int testy;
    cin>>testy;

    while(testy--)
    {
        if(solve())
        {
            cout<<"TAK"<<endl;
            for(int i=0;i<ciag.size();i++)
            {
                cout<<ciag[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<"NIE"<<endl;
        }
        ciag.clear();
    }
    
    return 0;
}
 