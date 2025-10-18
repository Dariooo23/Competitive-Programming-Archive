#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n,wynik=0;
    cin>>n;
    int s[n];


    for (int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for (int i=n-1;i>-1;i=i-1)
    {
            if (s[i]>s[i-1])
            {
                wynik=wynik;
            }
            else
            {
                s[i-1]=s[i-1]-(s[i-1]-s[i]+1);
                wynik=wynik+1;
            }
    }
    if (s[0]>0)
    {
        cout<<wynik;
    }
    else
    {
        cout<<"-1";
    }
    return 0;
}