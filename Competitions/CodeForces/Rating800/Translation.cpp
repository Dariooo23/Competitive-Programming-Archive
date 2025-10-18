//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string word1,word2;
    cin>>word1>>word2;

    if(word1.size()!=word2.size())
    {
        cout<<"NO";
        return 0;
    }

    for(int i=0;i<word1.size();i++)
    {
        if(word1[i]!=word2[word2.size()-i-1])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    
    return 0;
}
 