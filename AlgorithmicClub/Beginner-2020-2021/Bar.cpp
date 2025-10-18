#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cassert>
#include <vector>


using namespace std;

vector<int> V[1000009];

bool comp(const vector<int> &a, const vector<int> &b)
{
    if (a.size()==b.size())
    {
        return a[0]<b[0];
    }
    return a.size()>b.size();
}

void solve()
      {
        int n,k;
        cin>>n>>k;

        for (int i=0;i<n;i++)
        {
            int m;
            cin>>m;
            for (int j=0;j<m;j++)
            {
                int b;
                cin>>b;
                V[i].push_back(b);
            }
            sort (V[i].begin(), V[i].end());
        }
        sort(V,V+n,comp);
        vector<int> result;
        for (int i=0;i<k;i++)
        {
            for (int j=0;j<V[i].size();j++)
            {
                result.push_back(V[i][j]);
            }
        }
        sort (result.begin(), result.end());
        cout<<result.size()<<endl;
        for (int i=0;i<(int)result.size();i++)
        {
            cout<<result[i]<<" ";
        }

      }
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout<<fixed<<setprecision(2);
    solve();
    return 0;
}