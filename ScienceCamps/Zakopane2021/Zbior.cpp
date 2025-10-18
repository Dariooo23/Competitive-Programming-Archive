#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int slowo10[256]={0},slowo20[256]={0};

int main()
{
    string slowo1,slowo2;
    int dziala=1;
    cin>>slowo1>>slowo2;

       for(int i=0;i<slowo1.size();i++)
       {
           slowo10[slowo1[i]]++;
           slowo20[slowo2[i]]++;
       }
       for(int i=0;i<=256;i++)
       {
           if(slowo10[i]!=slowo20[i])
           {
               dziala=0;
           }
       }
       if(dziala==1)
       {
           cout<<"TAK";
       }
       else
       {
           cout<<"NIE";
       }


    return 0;
}