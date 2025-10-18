#include <iostream>
#include <stack>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int budynki,plakaty=0;
    stack<int> wysokosci;
    cin>>budynki;
    int tab[budynki];
    for(int i=0;i<budynki;i++)
    {
        int a;
        cin>>a;
        cin>>tab[i];
    }

    for(int i=0;i<budynki;i++)
    {
       while(!wysokosci.empty() && wysokosci.top()>tab[i])
       {
           wysokosci.pop();
       }
       if(wysokosci.size()==0 || wysokosci.top()<tab[i])
       {
           wysokosci.push(tab[i]);
           plakaty++;
       }
    }
    cout<<plakaty;
    return 0;
}