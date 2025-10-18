#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
int n,k;
cin>>n>>k;
int tab[n];
for (int i=0;i<n;i++)
{
    cin>>tab[i];
}
for (int i=0;i<n;i++)
{
    cout<<tab[(i+k)%n]<<" ";
}
cout<<endl;
    return 0;
}