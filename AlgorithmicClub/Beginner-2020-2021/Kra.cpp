#include <iostream>
#include <algorithm>

int tab[1000000];



using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n,m,a;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>tab[i];

    for(int i=2;i<=n;i++)
    {
        tab[i]=min(tab[i],tab[i-1]);
    }
    int wys=n;

    for(int i=0;i<m;i++)
    {
        if(wys==0)
        {
            cout<<0;
            return 0;
        }
        cin>>a;
        if(a>tab[1])
        {
            cout<<0;
            return 0;
        }
        while(tab[wys]<a)
        {
            wys--;
        }
        wys--;

    }

    cout<<wys+1;





}