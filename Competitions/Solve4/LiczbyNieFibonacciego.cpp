//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,licznik=1;
    cin>>n;

    vector<long long int> fib;
    set<pair<long long int,int>> liczbyfib;

    fib.push_back(1);
    fib.push_back(1);
    liczbyfib.insert({1,0});
    liczbyfib.insert({1,1});

    while(fib[fib.size()-2]+fib[fib.size()-1]<=1e18){
        licznik++;
        fib.push_back(fib[fib.size()-2]+fib[fib.size()-1]);
        liczbyfib.insert({fib[fib.size()-1],licznik});
    }

    int poprzednik=0;
    auto it=liczbyfib.upper_bound({n,1000});
    --it;

    while(poprzednik!=it->second){
        poprzednik=it->second;
        it=liczbyfib.upper_bound({n+poprzednik,1000});
        --it;
    }

    cout<<n+poprzednik;
    return 0;
}