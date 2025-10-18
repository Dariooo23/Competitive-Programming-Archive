//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,t;
    string slowo;
    cin>>n>>t>>slowo;

    while(t--)
    {
        bool zmiana=0;
        for(int i=1;i<slowo.size();i++)
        {
            if(slowo[i-1]=='B' && slowo[i]=='G' && zmiana==0)
            {
                slowo[i-1]='G';
                slowo[i]='B';
                zmiana=1;
            }
            else
            {
                zmiana=0;
            }
        }
    }
    cout<<slowo;

    return 0;
}
 