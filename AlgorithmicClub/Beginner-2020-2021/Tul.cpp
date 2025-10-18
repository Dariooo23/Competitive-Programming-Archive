#include <iostream>

using namespace std;
   bool tulipan[15001];
int main()
{

    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int rodzaj;
        cin>>rodzaj;
        tulipan[rodzaj] = 1;

    }
    int wynik=0;
    for (int i=1;i<=15000;i++)
    {
        if (tulipan[i]!=1)
        {
            wynik++;
        }
    }
    cout<<wynik<<endl;
    return 0;
}