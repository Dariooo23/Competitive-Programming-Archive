//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> alfabet(26);

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string slowo;
    int wynik=0;

    cin>>slowo;

    for(int i=0;i<slowo.size();i++)
    {
        if(alfabet[slowo[i]-'a']==0)
        {
            wynik++;
        }

        alfabet[slowo[i]-'a']++;
    }

    if(wynik%2)
    {
        cout<<"IGNORE HIM!";
    }
    else
    {
        cout<<"CHAT WITH HER!";
    }

    return 0;
}
 