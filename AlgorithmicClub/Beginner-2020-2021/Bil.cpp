#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,long long int> tab;
    for (int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int id,v;
            cin>>id>>v;
            tab[id]+=v;
        }
        else
        {
            int id;
            cin>>id;
            cout<<tab[id]<<endl;
        }
    }
    return 0;
}