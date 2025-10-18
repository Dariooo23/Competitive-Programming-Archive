//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<long long int> ciag(81);
    ciag[0]=1;
    ciag[1]=1;
    for(int i=2;i<=80;i++){
        ciag[i]=ciag[i-1]+ciag[i-2];
    }

    cout<<ciag[n];
    return 0;
}