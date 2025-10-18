#include <iostream>

using namespace std;
int liczba(char x)
{
    int wynik=0;
    switch(x)
    {
        case 'M':

            wynik=1000;
            break;
            case 'D':
            wynik=500;
            break;
            case 'C':
            wynik=100;
            break;
            case 'L':
            wynik=50;
            break;
            case 'X':
            wynik=10;
            break;
            case 'V':
            wynik=5;
            break;
            case 'I':
            wynik=1;
            break;

    }
    return wynik;
}

int obroc(int b)
{
    int w=0;
    while(b>0)
    {
       w*=10;
       w+=b%10;
       b/=10;
    }
    return w;
}
int cosnd(int a,int p)
{
    int w=0,d=1;

    while(a>0)
    {
        w+=d*(a%10);
        d*=p;
        a/=10;
    }
    return w;
}
int dncos(int a,int p)
{
    int w=0,d=1;
    while(a>0)
    {
        w+=(a%p)*d;
        d*=10;
        a/=p;

    }
    return w;
}

int main()
{
   string a;
   cin>>a;
   int maks=0,wynik=0;
   for(int i=a.size()-1;i>=0;i--)
   {
       if(liczba(a[i])<maks)
        wynik-=liczba(a[i]);
       else
       {
           wynik+=liczba(a[i]);
           maks=liczba(a[i]);
       }
   }
   cout<<wynik;







}