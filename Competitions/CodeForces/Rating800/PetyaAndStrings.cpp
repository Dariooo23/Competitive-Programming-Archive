//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string slowo1,slowo2;
    cin>>slowo1>>slowo2;

    for(int i=0;i<slowo1.size();i++)
    {
        if(slowo1[i]>='a')
        {
            slowo1[i]=slowo1[i]+'A'-'a';
        }
        if(slowo2[i]>='a')
        {
            slowo2[i]=slowo2[i]+'A'-'a';
        }

        if(slowo1[i]<slowo2[i])
        {
            cout<<-1;
            return 0;
        }
        if(slowo1[i]>slowo2[i])
        {
            cout<<1;
            return 0;
        }
    }

    cout<<0;

    return 0;
}
 