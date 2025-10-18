#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int iz,a,b,c,wynik=0;
    cin>>iz;
    for (int i=0;i<iz;i++)
    {
        cin>>a>>b>>c;
        if (c%2==0)
        {
            wynik=wynik+a*(c/2);
            wynik=wynik-b*(c/2);
            cout<<wynik<<endl;
        }
        else
        {
           wynik=wynik+a*(c/2+1);
           wynik=wynik-b*(c/2);
           cout<<wynik<<endl;
        }
        wynik=0;
    }
    return 0;
}