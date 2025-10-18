#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int a,b,c,d,e;
    cin>>a;
    int tab[1000001];
    for (int i=0;i<a;i++)
    {
        tab[i]=0;
    }
    for (int i=0;i<a;i++)
    {
        cin>>b;
        tab[b-1]=tab[b-1]+1;
    }

    cin>>c;
    for (int j=0;j<c;j++)
    {
        cin>>d>>e;
        for (int i=d-1;i<e;i++)
    {
        if (tab[i]!=0)
        {
            cout<<i+1<<" "<<tab[i]<<endl;
        }
    }
    cout<<endl;
    }

    return 0;
}