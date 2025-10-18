#include <bits/stdc++.h>

using namespace std;
bool zapytania[1000000]={0};
int rodzic[1000000];
int ranking[1000000]={0};
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

    ios_base::sync_with_stdio(0);

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> drogi(m+1);
    for(int i=1;i<=n;i++)
    {
       rodzic[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>drogi[i].first>>drogi[i].second;
    }
    int ilosc;
    cin>>ilosc;
    vector<int>wyniki(ilosc);
    int pytania[ilosc];
    for(int k=0;k<ilosc;k++)
    {

        cin>>pytania[k];
        zapytania[pytania[k]]=1;
    }

    int wynik=n,lol=ilosc-1,odpowiedzi=0;

    for(int i=m;i>0;i--)
    {
        if(zapytania[i]==0)
        {
            if(fin(drogi[i].first)!=fin(drogi[i].second))
               {
                    unio(drogi[i].first,drogi[i].second);
                    wynik--;
               }
        }
        else
        {
            lol--;
        }

    }cout<<endl;
    wyniki[odpowiedzi]=wynik;
    odpowiedzi++;
    //cout<<wynik<<endl;
    for(int i=ilosc-1;i>0;i--)
    {
           if(fin(drogi[pytania[i]].first)!=fin(drogi[pytania[i]].second))
               {
                    unio(drogi[pytania[i]].first,drogi[pytania[i]].second);
                    wynik--;
               }
           wyniki[odpowiedzi]=wynik;
           odpowiedzi++;
    }
    //cout<<wynik<<endl;
    for(int i=ilosc-1;i>=0;i--)
    {
        cout<<wyniki[i]<<" ";
    }

return 0;
}