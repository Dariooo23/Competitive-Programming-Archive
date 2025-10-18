//Karol Dziekan
#include <iostream>

using namespace std;
typedef long long int LL;

LL fib[90];
void Fib()
{
    for(int i=2;i<90;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);

    LL a,j=89,dwojki=0,trojki=0,wynik=-1;
    cin>>a;
    if(a==1)
    {
        cout<<"1";
    }
    else
    {


    fib[0]=0;
    fib[1]=1;
    Fib();


    while(a>0 && j>2)
    {
        if(fib[j]!=144 && fib[j]!=8)
        {


            if(fib[j]==2)
            {
           while(a%fib[j]==0)
        {
            dwojki++;
            a=a/fib[j];
        }
            }



            if(fib[j]==3)
            {
           while(a%fib[j]==0)
        {
            trojki++;
            a=a/fib[j];
        }
            }



           while(a%fib[j]==0)
        {
            a=a/fib[j];
            wynik=wynik+j;
        }


        }
        j--;
    }

    LL zmienna=min(dwojki/4,trojki/2);
    dwojki=dwojki-zmienna*4;
    trojki=trojki-zmienna*2;
    wynik=wynik+12*zmienna;



    zmienna=dwojki/3;
    dwojki=dwojki-zmienna*3;
    wynik=wynik+6*zmienna;


    /*while(dwojki>=4 && trojki>=2)
    {
        wynik=wynik+12;
        dwojki=dwojki-4;
        trojki=trojki-2;
    }
    while(dwojki>=3)
    {
        wynik=wynik+6;
        dwojki=dwojki-3;
    }*/



    wynik=wynik+dwojki*3;
    wynik=wynik+trojki*4;

    if(wynik==-1 || a!=1 )
    {
        cout<<"NIE";
    }
    else
    {
       cout<<wynik;
    }
    }

    return 0;
}