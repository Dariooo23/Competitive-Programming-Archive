#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int w1,w2;
    long long int ww1=0,ww2=0,wynik=0;
    cin>>w1>>w2;
    int a[w1],b[w2];
    for (int i=0;i<w1;i++)
    {
        cin>>a[i];
        ww1=ww1+a[i];
    }
    for (int i=0;i<w2;i++)
    {
        cin>>b[i];
        ww2=ww2+b[i];
    }

    while (ww1!=ww2)
    {
        if (ww1>ww2)
        {
           ww1=ww1-a[w1-1];
           w1=w1-1;
        }
        else
        {
           ww2=ww2-b[w2-1];
           w2=w2-1;
        }
        wynik=wynik+1;
    }

    cout<<wynik;
    return 0;
}