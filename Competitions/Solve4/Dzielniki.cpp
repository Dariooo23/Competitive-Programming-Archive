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

    vector<long long int> dzielniki;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            dzielniki.push_back(i);
            if(n/i!=i)dzielniki.push_back(n/i);
        }
    }

    sort(dzielniki.begin(),dzielniki.end());

    for(int i=0;i<dzielniki.size();i++){
        cout<<dzielniki[i]<<" ";
    }
    return 0;
}