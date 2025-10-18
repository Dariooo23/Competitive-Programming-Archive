//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string slowo;
    int duze=0,male=0;

    cin>>slowo;

    for(int i=0;i<slowo.size();i++)
    {
        if(slowo[i]>='a')
        {
            male++;
        }
        else
        {
            duze++;
        }
    }

    if(duze>male)
    {
        transform(slowo.begin(),slowo.end(),slowo.begin(), ::toupper);
    }
    else
    {
        transform(slowo.begin(),slowo.end(),slowo.begin(), ::tolower);
    }

    cout<<slowo;
    
    return 0;
}
 