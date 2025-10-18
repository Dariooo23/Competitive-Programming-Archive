#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int it,t,a=0,b=0,bz=0,kosztzp=0,wynikg=0,wynikz=0;
    cin>>it>>t;
    long long int tab[it],koszt[it-1];
    for (int i=0;i<it;i++)
    {
        cin>>tab[i];
    }


    for (int i=0;i<(it-1);i++)
    {
        koszt[i]=tab[i+1]-tab[i];
        if(koszt[i]<0)
        {
            koszt[i]=0;
        }
    }
    /*for (int i=0;i<(it-1);i++)
    {
        cout<<koszt[i]<<" ";
    }
    cout<<endl;
*/


    for(int i=0;i<(it-1);i++)
    {
        kosztzp=kosztzp+koszt[i];
        if(kosztzp>t)
        {
            kosztzp=kosztzp-koszt[i];
            b=i;
            break;
        }
        else
        {
           b=i+1;
        }


    }
    wynikg=(b-a+1);

    for(int i=1;i<(it-1);i++)
    {
        a=i;
        kosztzp=kosztzp-koszt[a-1];
        for (int j=b;j<(it-1);j++)
        {
        kosztzp=kosztzp+koszt[j];
        if(kosztzp<=t)
        {

            bz=j+1;
            wynikz=(bz-a+1);
            if(wynikz>wynikg)
            {
                wynikg=wynikz;
                wynikz=0;
            }

        }
        else
        {
          kosztzp=kosztzp-koszt[j];
          bz=j;
            wynikz=(bz-a+1);
            if(wynikz>wynikg)
            {
                wynikg=wynikz;
                wynikz=0;
            }
          break;
        }


        }
        b=bz;
    }
    if (wynikg==1)
    {
        cout<<"10";
    }
    else
    {
       cout<<wynikg;  
    }
   

    return 0;
}