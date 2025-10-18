#include <iostream>

using namespace std;
int n;
int tab[1001][1001];
int path [1001][1001];
int main()
{
    std::ios_base::sync_with_stdio(0);
    int result;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cin>>tab[i][j];
            if (i==1)
            {
                path[i][j]=tab[i][j];

            }
        }
    }
    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            path[i][j]=path[i-1][j];
            if (j-1>=1)
            {
                path[i][j]=min(path[i][j],path[i-1][j-1]);
            }
            if (j+1<=n)
            {
                path[i][j]=min(path[i][j],path[i-1][j+1]);
            }
            path[i][j]+=tab[i][j];
        }
        result=1000000;

        for (int i=1;i<=n;i++)
        {
            result=min(result,path[n][i]);

        }


    }
     cout<<result;


    return 0;
}