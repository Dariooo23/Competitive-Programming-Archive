//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<char> alfabet;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    alfabet.resize(257);

    string slowo1;

    cin>>slowo1;
    for(int i=0;i<slowo1.size();i++)
    {
        alfabet[slowo1[i]]++;
    }

    cin>>slowo1;
    for(int i=0;i<slowo1.size();i++)
    {
        alfabet[slowo1[i]]--;
    }

    for(int i='a';i<='z';i++)
    {
        if(alfabet[i]!=0)
        {
            cout<<"NIE";
            return 0;
        }
    }

    cout<<"TAK";
    
    return 0;
}
 