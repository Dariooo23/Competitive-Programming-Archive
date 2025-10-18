//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,jedynki=0;
    string slowo;

    cin>>n>>slowo;

    for(int i=0;i<slowo.size();i++)
    {
        if(slowo[i]=='1')
        {
            jedynki++;
        }
    }

    jedynki=jedynki-3*n;
    if(jedynki<0 || jedynki>3*n)
    {
        cout<<"NIE";
        return 0;
    }

    while(jedynki>=3)
    {
        cout<<"o";

        jedynki=jedynki-3;
        n--;
    }

    if(n>=1)
    {
        if(jedynki==2)
        {
            cout<<"g";
        }
        else
        {
            if(jedynki==1)
            {
                cout<<"c";
            }
            else
            {
                if(jedynki==0)
                {
                    cout<<"a";
                }
            }

        }
        n--;
    }

    while(n>=1)
    {
        cout<<'a';
        n--;
    }

    return 0;
}
 