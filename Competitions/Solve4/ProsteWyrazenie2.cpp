//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int a,b,c;
    cin>>a>>b>>c;
    cout<<(3*a+7*b*b)/(5*c-((a*c)%2));
    return 0;
}