#include <iostream>
#include <vector>
using namespace std;

int lb(int l, int r, int val, vector<int> &arr)
{
  
    if (r<l)
    {
       return l;
    }
    int mid=(l+r)/2;
    if (arr[mid]>=val)
    {
        return lb(l,mid-1,val,arr);
    }
    else
    {
        return lb(mid+1,r,val,arr);
    }
}
void solve()
{
    int a;
    cin>>a;
    vector<int> arr(a);
    for (int i=0;i<a;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    for (int i=0;i<k;i++)
    {
        int val;
        cin>>val;

            int pos=lb(0,a-1,val,arr);
        if (pos!=a)
        {
            cout<<pos+1<<" ";
        }
        else
        {
            cout<<"b"<<" ";
        }

    }
}
int main()
{
    solve();
    return 0;
}