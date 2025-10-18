//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int a;
    cin>>a;
    if(a<0)a=a*-1;
    cout<<a%10;
    return 0;
}