#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int testy;
    cin>>testy;
    for(int j=0;j<testy;j++)
    {

        string slowo;
        cin>>slowo;
        int ilosc=0;
    for(int i=0;i<slowo.size();i++)
    {
       if(slowo[i]=='(' || slowo[i]==')')
       {

           if (slowo[i]=='(')
           {
               ilosc++;
           }
           else
           {
               if (ilosc>0)
               {
                   ilosc--;
               }
               else
               {
                   ilosc--;
                   break;
               }
           }
       }
       else
       {
          ilosc=-1;
           break;
       }



    }
    if(ilosc==0)
    {
        cout<<"TRUE"<<endl;
    }
    else
    {
        cout<<"FALSE"<<endl;
    }
    }

    return 0;
}