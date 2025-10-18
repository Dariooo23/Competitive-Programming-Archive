#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int a,b,wynik=0,spo;
    cin>>a>>b;
    bool tab[a][b];
    int tab1[b];
    for (int i=0;i<b;i++)
    {
        tab1[i]=0;
    }
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<b;j++)
        {
            cin>>tab[i][j];
            if (tab[i][j]==1)
            {
                tab1[j]=tab1[j]+1;
            }

        }
    }
   //for (int i=0;i<b;i++)
//{
     // cout<<tab1[i]<<" ";
    //}
    //cout<<endl;
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<b;j++)
        {
          spo=tab[i][j]+spo;
        }
        //cout<<spo<<" ";
        for (int j=0;j<b;j++)
        {
            if (spo==tab1[j])
        {
            wynik=wynik+1;

        }

        }

        spo=0;

    }
    cout<<wynik;
    return 0;
}