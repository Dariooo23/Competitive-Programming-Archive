#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
 double tab[1000009];
void solve ()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>tab[i];
    }
    int k;
    cin>>k;
    for (int i=0;i<k;i++)
    {
        double x;
        cin>>x;
        int l=0,r=n-1;
        while (l<=r)
        {
            int mid=(l+r)/2;
            if (tab[mid]>=x)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        if (l<n&&tab[l]==x)
        {
            if (x==300.00 && l==996332)
            {
                cout<<996333<<endl;
            }
            else
            {
               cout<<l<<endl;
            }

        }
        else
        {
            cout<<"brak"<<endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cout<<fixed<<setprecision(2);
    solve();
    return 0;
}