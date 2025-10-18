//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int n;
    cin>>n;
    cout<<(long long int)(n*log10(2))+1;

    return 0;
}