#include <bits/stdc++.h>

using namespace std;
long long int minimum=1000000000,suma=0;
int rodzic[1000009];
long long int koszty[1000009]={0};
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
        suma=suma-max(koszty[rodzicX],koszty[rodzicY]);
        koszty[rodzicX]=min(koszty[rodzicX],koszty[rodzicY]);
        //cout<<suma<<" "<<koszty[x]<<endl;
    }
    else
    {
        rodzic[rodzicX]=rodzicY;
        suma=suma-max(koszty[rodzicX],koszty[rodzicY]);
        koszty[rodzicY]=min(koszty[rodzicX],koszty[rodzicY]);
        //cout<<suma<<" "<<koszty[x]<<endl;
    }
    if(ranking[rodzicX]==ranking[rodzicY])
    {
        ranking[rodzicX]++;
    }
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    int miasta,drogi,wynik;
    cin>>miasta>>drogi;
    wynik=miasta;
    vector<pair<int,int>> polaczenia(drogi+1);
    for(int i=1;i<=miasta;i++)
    {
        rodzic[i]=i;
    }
    for(int i=1;i<=drogi;i++)
    {
    cin>>polaczenia[i].first>>polaczenia[i].second;
    }
    for(int i=1;i<=miasta;i++)
    {
    cin>>koszty[i];
    suma=suma+koszty[i];
    minimum=min(minimum,koszty[i]);
    }
    //cout<<suma<<endl;
    //cout<<suma<<"PRZED"<<endl;
    for(int i=1;i<=drogi;i++)
    {
        if(fin(polaczenia[i].first)!=fin(polaczenia[i].second))
        {
            unio(polaczenia[i].first,polaczenia[i].second);
            wynik--;
            //cout<<"UNION"<<polaczenia[i].first<<"ORAZ"<<polaczenia[i].second;
        }
    }
    /*for(int i=1;i<10;i++)
    {
        cout<<koszty[i]<<" ";
    }*/
    //cout<<minimum<<" "<<endl;
    //cout<<suma<<"PO"<<endl;
    //cout<<wynik;
    if(wynik==1)
    {
        cout<<0;
    }
    else
    {
       cout<<suma+minimum*(wynik-2);
    }
    return 0;
}