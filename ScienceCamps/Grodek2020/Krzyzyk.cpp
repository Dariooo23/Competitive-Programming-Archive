#include <iostream>

using namespace std;

int main()
{
    int n,m,w=0;
    cin>>n>>m;
    char a[m];
    int x[m];
    for (int i=0;i<m;i++)
    {
        x[i]=0;
    }

    for (int i=0;i<n;i++)
    {
        cin>>a;
        for(int j=0;j<m;j++)
        {
            if(a[j]=='.')x[j]++;
            if(a[j]=='#')x[j]=0;
            if(x[j]==3)
            {
                x[j]=0;
                w++;
            }
        }
    }
    cout<<w;










    return 0;
}
