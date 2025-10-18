#include <iostream>

using namespace std;
int pole[100][100];
int odwiedzone[100][100]={0};
int dziala(int i,int j,int a,int b)
{
    if(i<0||j<0||i>=a||j>=b)
    {
        return false;
    }
    if(pole[i][j]==1 || odwiedzone[i][j]==1)
    {
        return false;
    }
    if(pole[i][j]==2)
    {
        return true;
    }
    odwiedzone[i][j]=1;
    return (dziala(i+1,j,a,b) || dziala(i,j+1,a,b) ||dziala(i-1,j,a,b) ||dziala(i,j-1,a,b));
}

int main()
{
    int a,b;
    pair<int,int> poczatek;
    poczatek.first=0; poczatek.second=0;
    cin>>a>>b;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cin>>pole[i][j];
        }
    }
    if(dziala(poczatek.first,poczatek.second,a,b)==1)
    {
        cout<<"TAK";
    }
    else
    {
        cout<<"NIE";
    }
    return 0;
}