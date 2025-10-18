#include <bits/stdc++.h>
using namespace std;

int main()
{
   queue<int> kolejka;
   int t;
   cin>>t;
   for(int i=0;i<t;i++)
   {
       int a,b;
       cin>>a;
       if(a==0)
       {
           if(!kolejka.empty())
           {
                kolejka.pop();
           }
           else
           {
               cout<<"PUSTA KOLEJKA"<<endl;
           }

       }
       else
       {
           if(a==1)
           {
               cin>>b;
              kolejka.push(b);
           }
           else
           {
               if(a==2)
               {
                  if(!kolejka.empty())
                  {
                  cout<<kolejka.front()<<endl;
                  }
                     else
                     {
                     cout<<"PUSTA KOLEJKA"<<endl;
                     }
               }
           }
       }
   }
    return 0;
}