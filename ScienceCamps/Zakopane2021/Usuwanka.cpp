#include <iostream>

using namespace std;

int main()
{


long long int n=0 ,wynik=0,jedynki=0,odleglosc=0;
cin>>n;
char a [n];


cin >>a;




for  ( int i=0; i<n; i++)
{
    if (a [i]=='1')
    {

        odleglosc=odleglosc+jedynki;
        jedynki=jedynki+1;
        wynik=wynik+odleglosc;
       



    }
    else
    {
            odleglosc=odleglosc+jedynki;
    }

}
cout<< wynik<<endl;





    return 0;
}