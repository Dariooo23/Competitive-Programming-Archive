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

    for(int i=1;i<=n;i++)
    {
        tab[i]=max(tab[i],tab[i-1]);
    }
    int stopien=n;
    for(int i=0;i<m;i++)
    {
        cin>>a;
        while(tab[stopien]>=a)
        {
            stopien--;
        }
        cout<<stopien<<" ";
        if(stopien!=0)
        {
            stopien--;
        }
    }





}