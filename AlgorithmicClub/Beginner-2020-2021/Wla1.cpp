//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int krainy[1000000];

void solve()
{

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        cin>>krainy[i];
    }

    sort(krainy,krainy+n);

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(krainy[mid]>=a)
            {
                r=mid-1;
            }else
            {
                l=mid+1;
            }
        }
        int be=l;

        l=0,r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(krainy[mid]>b)
            {
                r=mid-1;
            }else
            {
                l=mid+1;
            }
        }
        int en=l;

        cout<<en-be<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    solve();

    return 0;
}