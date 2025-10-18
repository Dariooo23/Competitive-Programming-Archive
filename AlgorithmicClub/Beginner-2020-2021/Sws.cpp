#include <iostream>
#include <iomanip>
#include <algorithm>
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

int convertToBase10(string num,int base)
{
    int res=0;
    for (int i=0;i<(int)num.size();i++)
    {
        res=(res*base)+num[i]-'0';

    }
    return res;
}



string convertFromBase10(int num,int base)
{
    string res;
    while(num>0)
          {
              res.push_back(char(num%base+'0'));
              num/=base;
          }
            reverse(res.begin(), res.end());
    return res;
}




string convert (string num,int from, int to)
{
    return convertFromBase10(convertToBase10(num,from),to);
}




int main()
{
    string num;
    int a,a1,a2;
    string wyn1,wyn3,wyn2,z,z1,wyn4;

    cin>>a;
    cin>>num;
    z=num;
    a1=a;
    wyn1=convert(num,a,10);

    cin>>a;
    cin>>num;
    z1=num;
    a2=a;
    wyn2=convert(num,a,10);



    wyn3=dodaj(wyn1,wyn2);
    cin>>a;
    wyn3=convert(wyn3,10,a);

   
    cout<<z<<"("<<a1<<")";
    cout<<"+";
    cout<<z1<<"("<<a2<<")";
    cout<<"=";
    cout<<wyn3<<"("<<a<<")";
    return 0;
}