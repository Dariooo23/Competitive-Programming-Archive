#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int n,D;
    long long int powierzchnia,liczba_kratek,znaleziony_max=0;
    cin>>n>>D;
    for (int i=0;i<n;i++)
    {
        long long int a,b;
        cin>>a>>b;
        liczba_kratek=(2+(a-2)/D)*(2+(b-2)/D);
        if (liczba_kratek==znaleziony_max)
        {
            powierzchnia=max(powierzchnia,a*b);
        }
        if (liczba_kratek>znaleziony_max)
        {
            znaleziony_max=liczba_kratek;
            powierzchnia=a*b;
        }
    }
    cout<<powierzchnia;
    return 0;
}