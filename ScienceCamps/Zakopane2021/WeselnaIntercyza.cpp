#include <iostream>

using namespace std;
typedef long long int LL;
int dasie[1000000]={0};
int main()
{
    int a,suma=0,suma1;
    cin>>a;
    int prezenty[a+1];
    for(int i=0;i<a;i++)
    {
        cin>>prezenty[i];
        suma=suma+prezenty[i];
    }
    dasie[0]=1;
    for(int i=0;i<a;i++)
    {
        for(int j=suma;j>=prezenty[i];j--)
        {
            if(dasie[j-prezenty[i]]==1)
            {
                dasie[j]=1;
            }
        }
    }

    /*for(int i=0;i<suma;i++)
    {
        cout<<dasie[i]<<endl;
    }*/
    suma1=suma;
    if(suma%2==0&&dasie[suma/2]==1)
    {
       cout<<suma/2<<" "<<suma/2;
    }
    else
    {
        suma=suma/2;
        while(dasie[suma]==0)
        {
            suma--;
        }
        cout<<suma1-suma<<" "<<suma;
    }
    return 0;
}