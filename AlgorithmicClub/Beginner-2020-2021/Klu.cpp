#include <iostream>

using namespace std;

int main()
{
int n,m,p,k=0,nu,pu;
cin>>n>>m>>p;
int L[m+1000];
for (int i=0;i<m;i++)
{
    cin>>L[i];
}
k=L[0];


for (int i=0;i<p;i++)
{
    cin>>nu>>pu;

    if (L[nu-1]==k)
    {
        k=pu;
    }
    L[nu-1]=pu;
}
cout<<k;


    return 0;
}