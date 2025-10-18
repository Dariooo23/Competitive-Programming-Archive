#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int a,licznik1=1,licznik2=1;
    cin>>a;
    string slowo;
    transform(slowo.begin(),slowo.end(),slowo.begin(),::tolower);
    cin>>slowo;
    for(int i=1;i<a;i++)
    {
         
       if(slowo[i-1]==slowo[i])
       {
         licznik2=1;  
       }
       else
       {
           licznik2++;
       }
      if(licznik1<licznik2)
           {
               licznik1=licznik2;
           }
    }
    cout<<licznik1;
    return 0;
}