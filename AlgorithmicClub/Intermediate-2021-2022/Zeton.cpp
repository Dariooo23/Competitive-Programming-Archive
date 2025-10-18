#include <iostream>

using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(0);
    int a;
    cin>>a;
    unsigned long long int tab[a][a];
    for (int i=0;i<a;i++)
    {
        tab[i][0]=1;
        tab[a-1][i]=1;
    }
    for (int i=a-2;i>=0;i--)
    {
        for (int j=1;j<a;j++)
        {
            tab[i][j]=tab[i+1][j]+tab[i][j-1];
        }
    }
    /*for (int i=0;i<a;i++)
    {
        for (int j=0;j<a;j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int b,c;
    while(cin>>b)
    {
        cin>>c;
        cout<<tab[a-(b+1)][c]<<endl;
    }
    return 0;
}