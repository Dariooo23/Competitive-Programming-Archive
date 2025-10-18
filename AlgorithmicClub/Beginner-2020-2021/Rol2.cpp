#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int a,wynik=0,med;
    cin>>a;
    int taab[a],tabb[a];
    cin>>taab[0]>>tabb[0];
    med=tabb[0];
    for (int i=1;i<a;i++)
    {
        cin>>taab[i]>>tabb[i];
    }
    sort (tabb,tabb+a);
    med=tabb[a/2];
    for (int i=0;i<a;i++)
    {
        if (taab[i]<med)
        {
            med=taab[i];
        }
    }
    for (int i=0;i<a;i++)
    {
        wynik=wynik+abs(tabb[i]-med);
    }
    cout<<wynik;
    return 0;
}