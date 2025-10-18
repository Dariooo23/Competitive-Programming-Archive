#include <bits/stdc++.h>

using namespace std;
long long int tab[101][2];
long long int odejmowanie[101]={0};
int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int k,potega=1;
    cin>>k;
    for(int i=1;i<99;i++)
    {
        if(i%2==1)
        {
            tab[i][0]=i+1;
            tab[i][1]=i+2;
        }
        else
        {
            tab[i][0]=i+1;
            tab[i][1]=-1;
            odejmowanie[i]=potega;
            potega=potega*2;
        }
    }
    while(k>0)
    {
        for(int i=100;i>=1;i=i-2)
        {
            if(odejmowanie[i] !=0 && odejmowanie[i]<=k)
            {
                tab[i][1]=100;
                k=k-odejmowanie[i];
                break;
            }
        }
    }
    //cout<<odejmowanie[98];
    tab[99][0]=-1;
    tab[99][1]=-1;
    tab[100][0]=-1;
    tab[100][1]=-1;
    cout<<"100"<<endl;
    for(int i=1;i<=100;i++)
    {
        //cout<<"LICZNIK"<<i<<"---";
        cout<<tab[i][0]<<" "<<tab[i][1]<<endl;
    }
    return 0;
}