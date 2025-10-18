#include <iostream>

using namespace std;
int szefowie[1000000];
int main()
{
    std::ios_base::sync_with_stdio(0);
    int pracownicy,pytania;
    cin>>pracownicy>>pytania;
    for(int i=2;i<=pracownicy;i++)
    {
        cin>>szefowie[i];
    }
    szefowie[1]=-1;
    for(int i=0;i<pytania;i++)
    {
        int x,y,py;
        cin>>x>>y;
        py=y;
        while(szefowie[y]>0 &&szefowie[y]!=x)
        {
            y=szefowie[y];
        }
        while(szefowie[py]>0)
        {
            py=szefowie[py];
        }
        if(szefowie[py]==0)
        {
            cout<<"NIE"<<endl;
        }
        else
        {
           if(szefowie[y]==x)
                {
                    cout<<"TAK"<<endl;
                }
                else
                {
                    cout<<"NIE"<<endl;
                }
        }

        }
    
    return 0;
}