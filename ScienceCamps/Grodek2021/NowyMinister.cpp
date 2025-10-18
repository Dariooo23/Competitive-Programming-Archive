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
bool tab[1000000];

int main()
{
    ios_base::sync_with_stdio(0);
    int a,b,n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<n+1;i++)
    {
       rodzic[i]=i;
    }

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        unio(b,a);
    }
    for(int i=1;i<q+1;i++)
    {
        int c,d,e;
        cin>>c;
        if(c==0)
        {
            cin>>d>>e;
            if(fin(d)==fin(e))
            {
                cout<<"TAK"<<endl;
            }
            else
            {
                cout<<"NIE"<<endl;
            }
        }
        else
        {
            cin>>d>>e;
            unio(d,e);
        }
    }

return 0;
}
