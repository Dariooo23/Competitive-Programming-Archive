#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
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
    int a,b;
    cin>>a>>b;
    cin>>num;
    cout<<convert(num,a,b)<<endl;
    return 0;
}