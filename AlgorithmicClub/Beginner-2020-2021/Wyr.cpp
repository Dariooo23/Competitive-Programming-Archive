#include <iostream>
#include <cmath>
using namespace std;

int licznik[109]={0};
int mianownik[109]={0};
int litery[260]={0};
int finalne_liczby[109]={0};





int main()
{
    unsigned long long int k=0,a,wynik=1;
    char slowo[109];
    while(cin>>slowo[k])
    {
        k++;
        litery[slowo[k-1]]++;
    }
    /*for (int i=0;i<256;i++)
    {
        cout<<litery[i]<<" ";
    }*/
    for (int i=1;i<=k;i++)
    {
      int ii=i;
      int pierw;
      int cos=2;
      pierw=sqrt(ii);
       while(ii>1&&cos<=pierw)
        {
                while(ii%cos==0)
                {
                        licznik[cos-1]++;
                        ii/=cos;
                }
                ++cos;
        }
        if(ii>1)
        {
            licznik[ii-1]++;
        }

    }
    for (int i=0;i<250;i++)
    {
        for (int j=1;j<=litery[i];j++)
        {
         int ii=j;
      int pierw;
      int cos=2;
      pierw=sqrt(ii);
       while(ii>1&&cos<=pierw)
        {
                while(ii%cos==0)
                {
                        mianownik[cos-1]++;
                        ii/=cos;
                }
                ++cos;
        }
        if(ii>1)
        {
            mianownik[ii-1]++;
        }






        }
    }
    for (int i=0;i<109;i++)
    {
        finalne_liczby[i]=licznik[i]-mianownik[i];
    }
    for (int i=0;i<109;i++)
    {
        while(finalne_liczby[i]>0)
        {
            wynik=wynik*(i+1);
            wynik=wynik%1000;
            finalne_liczby[i]--;
        }
    }
    /*for (int i=0;i<101;i++)
    {
        cout<<finalne_liczby[i]<<" ";
    }*/
    wynik=wynik%1000;

        if (wynik>=100)
        {
            cout<<wynik;
        }
        else
        {
            if (wynik>=10)
            {
                cout<<"0"<<wynik;
            }
            else
            {
                if(wynik<10)
                {
                    cout<<"00"<<wynik;
                }
            }

        }


    return 0;
}