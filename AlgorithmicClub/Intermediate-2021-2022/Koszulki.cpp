//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> wyniki;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    int wynik=k-1;

    wyniki.resize(n);

    for(int i=0;i<n;i++)
    {
        cin>>wyniki[i];
    }

    sort(wyniki.begin(),wyniki.end(), greater<int>());

    while(wynik<wyniki.size() && wyniki[wynik]==wyniki[k-1])
    {
        wynik++;
    }

    cout<<wynik;

    return 0;
}
 