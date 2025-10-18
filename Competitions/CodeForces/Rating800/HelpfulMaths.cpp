//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string slowo;
    int jedynki=0,dwojki=0,trojki=0,plusy=0;

    cin>>slowo;

    for(int i=0;i<slowo.size();i++)
    {
        if(slowo[i]=='1')
        {
            jedynki++;
        }
        if(slowo[i]=='2')
        {
            dwojki++;
        }
        if(slowo[i]=='3')
        {
            trojki++;
        }
        if(slowo[i]=='+')
        {
            plusy++;
        }
    }

    for(int i=0;i<slowo.size();i++)
    {
        if(jedynki>0)
        {
            cout<<'1';
            jedynki--;
        }
        else
        {
            if(dwojki>0)
            {
                cout<<'2';
                dwojki--;
            }
            else
            {
                if(trojki>0)
                {
                    cout<<'3';
                    trojki--;
                }
            }
        }
        if(plusy>0)
        {
            cout<<'+';
            plusy--;
        }
    }
    return 0;
}
 