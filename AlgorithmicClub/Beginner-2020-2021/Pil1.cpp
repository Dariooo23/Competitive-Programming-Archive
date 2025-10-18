#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    if(s.size()%2==0)
    {
        s=s+".";
    }
    int n=s.size();
    for (int i=0;i<n;i++)
    {
        if (i%4==2)
        {
            cout<<s[i];
        }
        else
        {
            cout<<"-";
        }
    }
    cout<<endl;
    for (int i=0;i<n;i++)
    {
        if (i%2==1)
        {
            cout<<s[i];
        }
        else
        {
            cout<<"-";
        }
    }
    cout<<endl;
    for (int i=0;i<n;i++)
    {
        if (i%4==0)
        {
            cout<<s[i];
        }
        else
        {
            cout<<"-";
        }
    }
    cout<<endl;
    return 0;
}