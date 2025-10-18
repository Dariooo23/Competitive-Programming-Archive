#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ilosc;
    cin>>ilosc;
    priority_queue<int> qMax;
    priority_queue<int,vector<int>, greater<int>> qMin;
    int a;
    cin>>a;
    qMax.push(a);
    cout<<a<<endl;
    for(int i=0;i<ilosc-1;i++)
    {
        int x;
        cin>>x;

           if(x>qMax.top())
           {
               qMin.push(x);
           }
           else
           {
               qMax.push(x);
           }
           
           if(qMax.size()>qMin.size())
           {
               qMin.push(qMax.top());
               qMax.pop();

           }
           
               if(qMax.size()<qMin.size())
               {
                   qMax.push(qMin.top());
                   qMin.pop();
               }
           


        cout<<qMax.top()<<endl;
    }
    return 0;
}