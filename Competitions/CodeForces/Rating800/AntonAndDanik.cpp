//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,p1=0,p2=0;
    string slowo;
    cin>>n>>slowo;

    for(int i=0;i<n;i++)
    {
        if(slowo[i]=='A')
        {
            p1++;
        }
        else
        {
            p2++;
        }
    }

    if(p1>p2)
    {
        cout<<"Anton";
    }
    if(p1<p2)
    {
        cout<<"Danik";
    }
    if(p1==p2)
    {
        cout<<"Friendship";
    }

    return 0;
}
 