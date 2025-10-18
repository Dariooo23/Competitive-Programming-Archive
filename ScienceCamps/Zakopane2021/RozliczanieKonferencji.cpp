#include <iostream>

using namespace std;

int main()
{
    int a,wynik=0;
    cin>>a;
    int tab[8]={200,100,50,20,10,5,2,1};
    int tab1[8]={0};
    for(int i=0;i<8;i++)
    {
        while(tab[i]<=a)
        {
           a=a-tab[i];
           wynik++;
        }
        tab1[i]=wynik;
        wynik=0;

    }
    for(int i=7;i>=0;i--)
    {
        if(tab1[i]!=0)
        {
            cout<<tab1[i]<<"*"<<tab[i]<<endl;
        }
    }
    return 0;
}