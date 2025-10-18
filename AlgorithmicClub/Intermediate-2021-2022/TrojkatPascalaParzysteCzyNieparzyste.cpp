//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<vector<bool> > pascal(5001,vector<bool> (5001));
int mod=2;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    for(int i=1;i<=5000;i++)
    {
        pascal[i-1][0]=1;
        pascal[i-1][i-1]=1;
        for(int j=1;j<=5000;j++)
        {
            pascal[i][j]=(pascal[i-1][j-1]+pascal[i-1][j])%mod;
        }
    }

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(pascal[a][b])
        {
            cout<<"N"<<endl;
        }
        else
        {
            cout<<"P"<<endl;
        }
    }



    
    return 0;
}
 