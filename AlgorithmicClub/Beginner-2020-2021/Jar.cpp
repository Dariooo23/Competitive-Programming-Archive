#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <algorithm>
using namespace std;
int tab[1000000];
int tab2[1000000];
int tab3[1000000];
int tab4[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
       int n,wyn=999999,w=0;
    cin>>n;
    for(int i=0;i<n;i+=3)
    {
        tab[i]=0;
        tab[i+1]=1;
        tab[i+2]=1;
    }
    tab2[0]=1;
    for(int i=1;i<n;i+=3)
    {
        tab2[i]=0;
        tab2[i+1]=1;
        tab2[i+2]=1;
    }
    tab3[0]=1;
    tab3[1]=1;
    for(int i=2;i<n;i+=3)
    {
        tab3[i]=0;
        tab3[i+1]=1;
        tab3[i+2]=1;
    }
    for(int i=0;i<n;i++) cin>>tab4[i];
    for(int i=0;i<n;i++) if(tab4[i]!=tab2[i]) w++;

        if(w<wyn) wyn=w;
    w=0;
     for(int i=0;i<n;i++) if(tab4[i]!=tab3[i]) w++;

        if(w<wyn) wyn=w;
    w=0;
    for(int i=0;i<n;i++) if(tab4[i]!=tab[i]) w++;

        if(w<wyn) wyn=w;
    w=0;
    cout<<wyn;




}