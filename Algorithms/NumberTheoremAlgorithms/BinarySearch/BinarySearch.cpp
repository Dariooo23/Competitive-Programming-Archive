//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> tab;

//FUNKCJA PRZYJMUJĄCA WARTOŚĆ Z WYSZUKIWANIA BINARNEGO
bool dziala(int a,int b)
{
    return (tab[a]<b);
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    //WCZYTANIE DANYCH 
    int n,m;
    cin>>n>>m;
    tab.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>tab[i];
    }
    //WYSZUKIWANIE BINARNE
    int l=1,r=n,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(dziala(mid,m))
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    //POSZUKIWANA POZYCJA
    cout<<l;
    return 0;
}
 