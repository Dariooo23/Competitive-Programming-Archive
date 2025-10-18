//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;
    if(n==1) cout<<"cukierek";
    else if(n>=11&&n<=20) cout<<"cukierkow";
    else if(n%10<=4&&n%10>1) cout<<"cukierki";
    else cout<<"cukierkow";
    return 0;
}