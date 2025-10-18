#include <iostream>

using namespace std;
int prawo[1000000]={0},lewo[1000000]={0},tab[1000000]={0};
int main()
{
    std::ios_base::sync_with_stdio(0);
    int a;
    cin>>a;

    for (int i=0;i<a-1;i++)
    {
        cin>>tab[i];
    }





    for (int i=1;i<a;i++)
    {
    if(tab[i-1]==2||tab[i-1]==1)
    {
        lewo[i]=lewo[i-1]+1;
    }
    }








    for (int i=a-2;i>=0;i--)
    {
    if(tab[i]==2||tab[i]==0)
    {
        prawo[i]=prawo[i+1]+1;
    }
    }
   /* for (int i=0;i<a;i++)
    {
        cout<<prawo[i]<<" ";
    }*/







    for (int i=0;i<a;i++)
    {
        int wynik=0;
        wynik=prawo[i]+lewo[i];
        cout<<wynik<<" ";
    }
    return 0;
}