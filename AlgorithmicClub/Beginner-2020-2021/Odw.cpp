#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<long long> black(n),grey(n),suf(n+1);
    for (int i=0;i<n;i++)
    {
        cin>>black[i];
    }
    for (int i=0;i<n;i++)
    {
        cin>>grey[i];
    }
    for (int i=n-1;i>=0;i--)
    {
        suf[i]=black[i]+suf[i+1];
    }
    sort(grey.begin(),grey.end());
    for (int i=0;i<n;i++)
    {
        if (binary_search(grey.begin(),grey.end(),2*black[i])&&
            binary_search(grey.begin(),grey.end(),black[i]-suf[i+1]))
        {
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<n<<endl;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
   solve();
    return 0;
}