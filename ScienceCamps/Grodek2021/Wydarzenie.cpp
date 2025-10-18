#include <iostream>

using namespace std;
bool odwiedzone[1000009]={0};
int rodzic[1000009];
int ranking[1000009]={0};
int fin(int x)
{
    if(rodzic[x]==x)
    {
        return x;
    }
    else
    {
    rodzic[x]=fin(rodzic [x]);
    return rodzic[x];
    }

}
void unio(int x, int y)
{
    int rodzicX=fin(x);
    int rodzicY=fin(y);
    if(ranking[rodzicX]>ranking[rodzicY])
    {
        rodzic[rodzicY]=rodzicX;
    }
    else
    {
        rodzic[rodzicX]=rodzicY;
    }
    if(ranking[rodzicX]==ranking[rodzicY])
    {
        ranking[rodzicX]++;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    int ilznajomi,ilopowiadacze;
    cin>>ilznajomi;
    for(int i=1;i<=ilznajomi;i++)
    {
        rodzic[i]=i;
    }
    for(int i=1;i<=ilznajomi;i++)
    {
        int a;
        cin>>a;
        if(a!=0)
        {
            unio(a,i);
        }
    }
    int ilopowiadaczy,wynik=0;
    cin>>ilopowiadaczy;
    for(int i=1;i<=ilopowiadaczy;i++)
    {
        int b;
        cin>>b;
        if(odwiedzone[fin(b)]==0)
        {
            wynik++;
            odwiedzone[fin(b)]=1;
        }
    }
    cout<<wynik;
    return 0;
}