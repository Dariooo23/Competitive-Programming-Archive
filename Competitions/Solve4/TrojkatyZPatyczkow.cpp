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

    vector<int> zlicz(1000009);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        zlicz[a]++;
    }

    int wynik=0;
    for(int i=1;i<=1000000;i++){
        wynik=wynik+zlicz[i]/3;
    }

    cout<<wynik;
    return 0;
}