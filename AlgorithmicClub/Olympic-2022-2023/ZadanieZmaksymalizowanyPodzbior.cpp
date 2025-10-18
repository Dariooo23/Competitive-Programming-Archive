#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int testy,a,b,c;
    cin>>testy;
    for(int i=0;i<testy;i++)
    {
        long long int suma=0,uzyte=0;
        cin>>a>>b;
        multiset<long long int ,greater<long long int> > zbior;
        for(int i=0;i<a;i++)
        {
            cin>>c;
            zbior.insert(c);
        }
        while(uzyte<b)
        {
           multiset<long long int>::iterator it=zbior.lower_bound(suma+1);
           suma=suma+*it;
           uzyte++;
           zbior.erase(it);
        }
        cout<<suma<<endl;
        zbior.clear();
    }
    return 0;
}