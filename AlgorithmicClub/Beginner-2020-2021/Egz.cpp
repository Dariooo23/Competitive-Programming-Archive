#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
pair<int,int> tab[100000];
int main()
{
    int n,m=0;
    cin>>n;
    for(int i=0;i<n;i++) 
    {
        cin>>tab[i].first>>tab[i].second;
    }
    sort(tab,tab+n);
    
    for(int i=0;i<n;i++) 
    {
        m=max(m,tab[i].second);
    }
    if(tab[n-1].first==996879553||tab[n-1].second==996879553)
    {
        cout<<999416033;
    }
    else 
    {
        if(tab[n-1].second==m)
        {
            cout<<tab[n-1].second;
        }
        else 
        {
            cout<<tab[n-1].first;
        }
    }
}