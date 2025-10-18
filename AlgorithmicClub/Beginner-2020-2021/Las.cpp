#include <iostream>

using namespace std;

int licznik[1000001];
int main()
{
    std::ios_base::sync_with_stdio(0);
    int n,r;
    int g;

     cin>>n;

    for (int i=0;i<n;i++)
    {
        cin>>g>>r;
        licznik[r]++;
    }
    int wynik=0;
    for (int i=1;i<=1000000;i++)
    {
        if (licznik[i]>0)
        {
            wynik++;
        }
    }
    cout<<wynik;
    return 0;
}