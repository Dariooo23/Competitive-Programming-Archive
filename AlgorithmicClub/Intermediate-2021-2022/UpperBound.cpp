//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<int> tab;
int n,m;

bool czy_dziala(int srodek,int szukana)
{
    if(srodek>=n || srodek<0)
    {
        return 0;
    }
    else
    {
        return tab[srodek]>szukana;
    }
}
int bin(int l,int r,int szukana)
{
    int mid=(l+r)/2;
    if(l>=r)
    {
        return l;
    }

    if(czy_dziala(mid,szukana))
    {
        r=mid;
    }
    else
    {
        l=mid+1;
    }

    return bin(l,r,szukana);
}

int main()
{
    //std::ios_base::sync_with_stdio(0);
    //cout.tie(0);
    //cin.tie(0);

    cin>>n;

    tab.resize(n+9);
    tab[n]=1e9;

    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
    }

    cin>>m;

    for(int i=0;i<m;i++)
    {
        int szukana,indeks;
        cin>>szukana;
        indeks=bin(0,n,szukana);
        if(indeks>=n)
        {
            cout<<"b"<<" ";
        }
        else
        {
            cout<<indeks+1<<" ";
        }
    }
    return 0;
}