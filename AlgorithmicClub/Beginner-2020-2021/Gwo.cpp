#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n,k,wynik=0,rowne=0,wieksze=0,kandydat,i=0;
    cin>>n>>k;
    int t[n];
    for(int i=0;i<n;i++)
{
    cin>>t[i];
}
sort(t,t+n);
while (i<=n)
{
    kandydat=t[i];
    rowne=0;
    while (i<=n && t[i]==kandydat)
    {
        i++;
        rowne=rowne+1;
        wieksze=n-i;
        wynik=max(wynik,rowne+min(k,wieksze));
    }

}
cout<<wynik;

    return 0;
}