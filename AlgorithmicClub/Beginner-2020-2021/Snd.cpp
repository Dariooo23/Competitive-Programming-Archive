#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int ConvertToBase10(string num, int base)
{
    int res=0;
    for (int i=0;i<(int)num.size();i++)
    {
        res=(res*base)+num[i]-'0';
    }
    return res;
}
int main()
{
    string num;
    cin>>num;
    cout<<ConvertToBase10(num,6)<<endl;
    return 0;
}