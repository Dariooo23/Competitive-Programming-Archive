//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int a;
    cin>>a;

    vector<char> wyjscie;
    while(a!=1){
        if(a%2==1){
            wyjscie.push_back('P');
        }else{
            wyjscie.push_back('L');
        }
        a=a/2;
    }

    for(int i=wyjscie.size()-1;i>=0;i--){
        cout<<wyjscie[i];
    }
    return 0;
}