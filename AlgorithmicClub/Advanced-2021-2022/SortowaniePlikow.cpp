#include <bits/stdc++.h>
using namespace std;

struct podnap
{
    string nazwa;
    string liczby;
    string liczbybz;
    string rozszerzenie;
};

int comparator(podnap a,podnap b)
{
    if(a.nazwa==b.nazwa)
    {
       if(a.liczbybz==b.liczbybz)
       {
          if(a.rozszerzenie==b.rozszerzenie)
          {
             if(a.nazwa+a.liczby==b.nazwa+b.liczby)
             {
                  return a.rozszerzenie<b.rozszerzenie;
             }
             else
             {
                 return a.nazwa+a.liczby<b.nazwa+b.liczby;
             }
          }
          else
          {
              return a.rozszerzenie<b.rozszerzenie;
          }
       }
       else
       {
        if(a.liczbybz.size()==b.liczbybz.size())
        {
            return a.liczbybz<b.liczbybz;
        }
        else
        {
                return a.liczbybz.size()<b.liczbybz.size();
        }
       }
    }
    else
    {
       return a.nazwa<b.nazwa;
    }
}
int main()
{
    int ilosc;
    cin>>ilosc;
    podnap napisy[ilosc];
    for(int i=0;i<ilosc;i++)
    {
        int kropka=0,liczby=1,nazwa2=1,zera=1;
        string nazwa1;
        cin>>nazwa1;
        for(int j=nazwa1.size()-1;j>=0;j--)
        {
            if(kropka==0)
            {
               napisy[i].rozszerzenie=nazwa1[j]+napisy[i].rozszerzenie;
            }
            if(liczby==0)
            {
             if(nazwa1[j]>=48 && nazwa1[j]<=57)
             {
                    napisy[i].liczby=nazwa1[j]+napisy[i].liczby;
             }
             else
             {
                 nazwa2=0;
                 liczby=1;
             }

            }
            if(nazwa1[j]=='.')
            {
                kropka=1;
                liczby=0;
            }
            if(nazwa2==0)
            {
               napisy[i].nazwa=nazwa1[j]+napisy[i].nazwa;
            }

        }
          for(int j=0;j<napisy[i].liczby.size();j++)
                {
                        if(napisy[i].liczby[j]!='0')
                        {
                            zera=0;
                        }

                    if(zera==0)
                    {
                        napisy[i].liczbybz=napisy[i].liczbybz+napisy[i].liczby[j];
                    }


                }
                if(napisy[i].liczbybz.size()==0)
                {
                  napisy[i].liczbybz="0";
                }

        /*if(zera==1)
            {
              napisy[i].liczbybz="0";
            }*/
    }
   // cout<<endl;
    //cout<<endl;

    sort(napisy,napisy+ilosc,comparator);
    for(int i=0;i<ilosc;i++)
    {
        cout<<napisy[i].nazwa<<napisy[i].liczby<<napisy[i].rozszerzenie<<endl;
    }
  /* for(int i=0;i<ilosc;i++)
    {
        cout<<napisy[i].liczbybz<<endl;
    }*/
    return 0;
}