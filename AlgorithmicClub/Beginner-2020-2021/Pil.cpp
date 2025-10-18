#include <iostream>

using namespace std;

int main()
{
ios_base::sync_with_stdio(0);
    unsigned int ilosc_z,z[2],lodb=0;
    cin>>ilosc_z;

    for (int i=0;i<ilosc_z;i++)
    {
        for (int j=0;j<2;j++)
        {
            cin>>z[j];
        }
        while(z[0]<z[1])
        {
            z[0]=z[0]*2;
            lodb=lodb+1;
        }
        cout<<lodb<<"\n";
        lodb=0;
    }




    return 0;
}