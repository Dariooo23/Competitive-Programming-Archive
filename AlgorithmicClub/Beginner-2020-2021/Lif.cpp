#include <iostream>

using namespace std;
long long int tab1[32];
int main()
{
    int a,b,wynik=0;
    std::ios_base::sync_with_stdio(0);
    tab1[0]=0;
    tab1[1]=1;
    for (int i=2;i<32;i++)
    {
       tab1[i]=tab1[i-1]+tab1[i-2];

    }


    tab1[1]=1;

    while(cin>>a>>b)
    {
        for (int i=0;i<32;i++)
    {
       if(tab1[i]>=a && tab1[i]<=b)
       {
             wynik++;
       }

    }
    if (a==1)
    {
        wynik=wynik-1;
    }
    cout<<wynik<<'\n';
    wynik=0;
    }

    return 0;
}