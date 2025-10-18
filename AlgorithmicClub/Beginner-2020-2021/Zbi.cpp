#include <iostream>
#include <set>
using namespace std;

int main()
{
    int a;
    cin>>a;
    set<int> S;
    for (int i=0;i<a;i++)
    {
        int b,c;
        cin>>b>>c;
        if (b==1)
        {
           S.insert(c);
        }
        else
        {
           auto it=S.lower_bound(c);
            if(it!=S.end())
            {
                cout<<*it<<endl;
            }
            else
            {
                cout<<"-1"<<endl;
            }
        }
    }
    return 0;
}