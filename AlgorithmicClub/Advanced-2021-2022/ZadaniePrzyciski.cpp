#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
int cnt[1000001];
int main()
{
    std::ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    int maks1=0,maks=0;
    for (int i=0;i<m;i++)
    {
        int p;
        cin>>p;
        if(p==n+1)
        {
            maks1=maks;
        }
        else
        {
            cnt[p]=max(cnt[p],maks1);
            cnt[p]++;
            maks=max(maks,cnt[p]);
        }
    }
    for (int i=1;i<=n;i++)
    {
        cout<<max(maks1,cnt[i])<<" ";
    }
    return 0;
}
