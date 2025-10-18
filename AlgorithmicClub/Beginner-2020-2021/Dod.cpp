#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

string dodaj(string a,string b)
{

    while(a.size()!=b.size())
        if(a.size()>b.size())b='0'+b;
    else a='0'+a;
    string wyn;
    int prze=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        int tmp=prze+(int)a[i]+(int)b[i]-2*48;
        prze=(tmp/10);
        wyn=(char)(tmp%10+48)+wyn;


    }
if(prze!=0) wyn=(char)(prze+48)+wyn;

    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    string a,b;
    cin>>a>>b;

   cout<<dodaj(a,b);

}