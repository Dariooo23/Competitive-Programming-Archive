//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

bool dziala(int n)
{
    vector<int> liczby(10);

    while(n>0)
    {
        if(liczby[n%10]>0)
        {
            return 0;
        }
        liczby[n%10]++;
        n=n/10;
    }
    return 1;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;
    n++;

    while(!dziala(n))
    {
        n++;
    }

    cout<<n;

    return 0;
}
 