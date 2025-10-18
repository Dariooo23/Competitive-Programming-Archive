//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string a,b;
    cin>>a>>b;

    int indeks1=0;
    while(indeks1!=a.size()){
        cout<<a[indeks1]<<b[indeks1];
        indeks1++;
    }
    return 0;
}