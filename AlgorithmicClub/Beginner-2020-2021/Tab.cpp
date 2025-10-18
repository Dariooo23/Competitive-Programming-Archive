#include <iostream>

using namespace std;
int tab[1000000];
int main()
{

    ios_base::sync_with_stdio(0);


    int n=0;
    while (cin>>tab[n])
    {
        n++;
    }
    for (int i=n-1;i>=0;i--)
    {
        cout<<tab[i]<<" ";
    }



    return 0;
}