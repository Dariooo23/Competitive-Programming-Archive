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

    long long int minimum=1e18+9,maksimum=0;
    for(int i=0;i<n;i++){
        long long int a;
        cin>>a;
        maksimum=max(maksimum,a);
        minimum=min(minimum,a);
    }

    cout<<(maksimum-minimum+1)-n;
    return 0;
}