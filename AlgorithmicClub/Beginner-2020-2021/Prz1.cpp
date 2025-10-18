#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int a,c,e,wynik=0;
    char b,d;
    cin>>a>>b>>c>>d>>e;
    int tab[3];
    tab[0]=a;
    tab[1]=c;
    tab[2]=e;
    sort (tab,tab+3);
    if(b=='>')
    {
        if (d=='<')
        {
            if (tab[1]>tab[0]&&tab[0]<tab[2])
            {
                  cout<<"TAK" ;
                  wynik=1;

            }

        }
        else
        {
            if (d=='=')
            {
              if (tab[2]>tab[0]&&tab[0]==tab[1])
                {

                        cout<<"TAK";
                        wynik=1;


                }
            }
            else
        {
            if (d=='>')
            {
                if (tab[2]>tab[1]&&tab[1]>tab[0])
                {
                    cout<<"TAK";
                    wynik=1;
                }
            }
        }
        }

    }
    else
    {
        if (b=='<')
        {
           if (d=='>')
        {
           if (tab[1]<tab[2] &&tab[2]>tab[0])
            {

                  cout<<"TAK";
                  wynik=1;

            }

        }
        else
        {
            if (d=='=')
            {
                if (tab[0]<tab[2]&&tab[2]==tab[1] )
            {

                  cout<<"TAK";
                  wynik=1;

            }
            }
            else
        {
            if (d=='<')
            {
                if (tab[0]<tab[1]&&tab[1]<tab[2])
                {
                    cout<<"TAK";
                    wynik=1;
                }
            }
        }
        }

        }
        else
        {
            if (b=='=')
            {
               if (d=='<')
        {
              if (tab[0]==tab[1]&&tab[1]<tab[2] )
            {

                  cout<<"TAK";
                  wynik=1;

            }
        }
        else
        {
            if (d=='>')
            {
                  if (tab[1]==tab[2]&&tab[2]>tab[0] )
            {

                  cout<<"TAK";
                  wynik=1;

            }
            }
            else
            {
                if (d=='=')
                {
                      if (tab[0]==tab[2]&&tab[2]==tab[1] )
            {

                  cout<<"TAK";
                  wynik=1;

            }
                }
            }
        }
            }
        }
    }



    if (wynik==0)
    {
        cout<<"NIE";
    }

    return 0;
}