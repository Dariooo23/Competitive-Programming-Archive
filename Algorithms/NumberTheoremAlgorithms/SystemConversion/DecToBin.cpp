//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

string s;

string DecToBin(int a,int b)
{
    if(b>0)
    {
        DecToBin(a/2,b-1);
        s=s+(char)(a%2+'0');
    }
    return s;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int a,b=16;
    cin>>a;

    s="";
    cout<<DecToBin(a,16);

    return 0;
}
 