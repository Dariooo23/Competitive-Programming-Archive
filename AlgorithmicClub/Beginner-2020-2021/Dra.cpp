#include <iostream>
#include <math.h>


using namespace std;
unsigned tab[1000005];

int main()
{
    ios_base::sync_with_stdio(0);
    tab[0]=0;
    tab[1]=1;
    tab[2]=2;
    unsigned pot;
    for(int i=3;i<1000003;i++)tab[i]=tab[i-1]+tab[i-2];
    unsigned n,z,p;
    cin>>n;
    for(unsigned i=0;i<n;i++)
    {
        cin>>z>>p;
        pot=pow(2,p);
        cout<<tab[z]%pot<<endl;
    }






}