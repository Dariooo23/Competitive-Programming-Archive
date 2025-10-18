#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> A (10009,vector<long long int> (509));

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n;
    long long int W;
    cin>>n;
    cin>>W;

    long long int c[n+1];
    long long int w[n+1];

    for(int i = 1; i <=n; i++)
    {
        cin>>w[i];
        cin>>c[i];
    }

    for(int i=1;i<=n;i++)
    {
        for (int j=0;j<=W;j++)
        {
            if(w[i]>j)
            {
                A[i][j]=A[i-1][j];
            }
            else
            {
                A[i][j]=max(A[i-1][j],A[i-1][j-w[i]]+c[i]);
            }
        }
    }

   cout<<A[n][W];

   return 0;
}