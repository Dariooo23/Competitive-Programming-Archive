#include <iostream>

using namespace std;
int rodzic[1000000];
int fin(int x)
{
    if(rodzic[x]==x) return x;
    else return rodzic[x]= fin(rodzic [x]);
}

void unio(int x, int y)
{
    int rodzicX=fin(x);
    int rodzicY=fin(y);
    if(rodzicX!=rodzicY) rodzic[rodzicX]=rodzicY;
}


int main()
{
    ios_base::sync_with_stdio(0);
    int a,b,n,m;
    cin>>n>>m;
    int wynik=n;
    for(int i=0;i<n+1;i++)
    {
       rodzic[i]=i;
    }

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        if(fin(a)!=fin(b))
        {
           unio(b,a);
           wynik--;

        }
    }
cout<<wynik;





}
