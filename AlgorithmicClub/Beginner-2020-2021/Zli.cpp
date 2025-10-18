#include <iostream>

using namespace std;
int cnt[256];
int main()
{
    int n;
    cin>>n;
    string s;
    getline(cin, s);
    for (int i=0;i<n;i++)
    {

        getline(cin, s);
        for (int j=0; j< (int)s.size();j++)
        {
            cnt [(int)s[j]]++;
        }
    }
    for (int i='a';i<='z';i++)
    {
        if (cnt[i]>0)
        {
            cout<< (char)i <<" "<< cnt[i]<<endl;
        }
    }
    for (int i='A';i<='Z';i++)
    {
        if (cnt[i]>0)
        {
            cout<< (char)i <<" "<< cnt[i]<<endl;
        }
    }
    return 0;
}