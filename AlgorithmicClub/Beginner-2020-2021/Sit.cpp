#include <iostream>
#include <iomanip>
using namespace std;
bool zlozona[1000001];
int main()
{
ios_base::sync_with_stdio(0);
cout << fixed << setprecision(2);
int n;
cin>>n;
for (int i=2;i*i<=n;i++)
{
    if (zlozona[i]) continue;
        for (int j=i*i;j<=n;j+=i)
        {
            zlozona[j]=true;
        }

}
for (int i=2;i<=n;i++)
{
    if (!zlozona[i])
    {
        cout<<i<<" ";
    }

}

    return 0;
}