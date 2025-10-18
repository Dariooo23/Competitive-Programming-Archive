#include <iostream>

using namespace std;
long long int tab[1000000]={0};
long long int tab1[1000000]={0};
int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int liczby,pytania;
    cin>>liczby>>pytania;
    tab[0]=0;
    tab1[0]=0;
    for(int i=1;i<=liczby;i++)
    {
        cin>>tab[i];
        tab1[i]=(tab[i]*tab[i])+tab1[i-1];
        tab[i]=tab[i]+tab[i-1];

    }
    for(int i=0;i<pytania;i++)
    {
        long long int l,r,a,wynik=0;
        cin>>l>>r>>a;
        wynik=((r-l+1)*a*a   +    2*a*(tab[r]-tab[l-1])   +   (tab1[r]-tab1[l-1]));
        cout<<wynik<<endl;
    }
    return 0;
}