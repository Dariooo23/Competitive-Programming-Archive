#include <iostream>

using namespace std;
int nwd(int a, int b)
{
    if (a<b) swap(a,b);
    if (b==0) return a;
    return nwd(b, a%b);
}

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int licznik =a*d + c*b;
    int mianownik =b*d;
    int dzielnik =nwd(licznik, mianownik);
    licznik=licznik/dzielnik;
    mianownik=mianownik/dzielnik;
    int czescCalkowita=licznik/mianownik;
    if(czescCalkowita!=0)
    {
        cout<<czescCalkowita<<" ";
    }
    licznik=licznik%mianownik;
    if(licznik!=0)
    {
        cout<<licznik<<"/"<<mianownik;
    }
    return 0;
}