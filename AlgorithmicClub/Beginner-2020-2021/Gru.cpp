#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int p0=n+1,p1=n+1,o0=0,o1=0;
    for (int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if (a==0)
        {
            p0=min(p0,i);
            o0=max(o0,i);
        }
        if (a==1)
        {
            p1=min(p1,i);
            o1=max(o1,i);
        }

    }
    cout<<max(o0-p1,o1-p0)<<endl;
    return 0;
}