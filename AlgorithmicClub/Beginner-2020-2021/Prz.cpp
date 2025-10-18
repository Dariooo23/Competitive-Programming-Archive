#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
int cnt[1000001];
int main()
{
    int n,m;
    cin>>n>>m;
    int lastSuper=0,maks=0;
    for (int i=0;i<m;i++)
    {
        int p;
        cin>>p;
        if(p==n+1)
        {
            lastSuper=maks;
        }
        else
        {
            cnt[p]=max(cnt[p],lastSuper);
            cnt[p]++;
            maks=max(maks,cnt[p]);


        }
    }
    for (int i=1;i<=n;i++)
    {
        cout<<max(lastSuper,cnt[i])<<" ";
    }
    return 0;
}