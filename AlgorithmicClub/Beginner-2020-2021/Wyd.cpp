#include <iostream>

using namespace std;

int main()
{
   int monety,kasa,wynik=0,im=0;
   cin>>monety>>kasa;
  while (kasa!=0)
   {
       im=kasa/monety;
       wynik=wynik+im;
       kasa=kasa-im*monety;
       monety=monety-1;

   }
   cout<<wynik;
    return 0;
}